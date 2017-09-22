#include "user_database.h"

UserDatabase::UserDatabase(){
    Load();
}

UserDatabase::~UserDatabase(){
    SaveAndClose();
    auto it=users.begin();
    for( ; it!=users.end(); ++it){
        delete *it;
        it=users.erase(it);
        it--;
    }
}

User *UserDatabase::getUser(const QString &text) {
    User* result =nullptr;
    auto it=users.begin();
    for( ;it!=users.end(); ++it){
        if((*it)->getUsername() == text ){
            result= *it;
        }
    }
    return result;
}

const QList<User*> UserDatabase::getAllUsers() const{
    QList<User*> u;
    for(auto it=users.begin();it!=users.end();++it){
        u.push_back(*it);
    }
    return u;
}

QList<User*> UserDatabase::searchUsers(const QString & word) const{
    QList<User*> temp;
    bool result=false;
    for(auto it=users.begin(); it!=users.end(); ++it){
        if( word=="" || ( word!="" && ( (*it)->getUsername().contains(word, Qt::CaseInsensitive) || (*it)->getName().contains(word, Qt::CaseInsensitive) ||
                                        (*it)->getSurname().contains(word, Qt::CaseInsensitive) ) ) ){
            temp.push_back(*it);
            result=true;
        }
    }
    if(result == false)
        QMessageBox::warning(0,"Attenzione","Nessun risultato, ritenta!");
    return temp;
}

bool UserDatabase::findUsername(const QString &username){
    bool found=false;
    auto it=users.begin();
    for(; it!=users.end() && !found ; ++it){
        if((*it)->getUsername()==username){
            found=true;
        }
    }
    return found;
}

User* UserDatabase::checkUser(const QString &username, const QString &password){
    User* logged_user=nullptr;

    bool check_admin=false;
    auto it=users.begin();
    for(; it!=users.end(); ++it){

        if(((*it)->getUsername()==username) && ((*it)->getPassword()==password))
            logged_user=(*it);

        if((*it)->getLabel() =="Admin")
            check_admin=true;
    }
    //Se eseguo accesso con db vuoto
    if(!check_admin){
        if(("admin"==username)&&("admin"==password)){
            logged_user=new User_Admin("admin","admin");
            users.push_back(logged_user);
        }
    }
    return logged_user;
}

void UserDatabase::upgradeUserGrade(User *u, QString c){
    User *temp =nullptr;

    if(c=="Admin")
        temp=new User_Admin(u->getUsername(),u->getPassword(), u->getName(), u->getSurname());

    if(c =="Standard_User")
        temp=new Standard_User(u->getUsername(),u->getPassword(), u->getName(), u->getSurname());

    if(c =="Pro_User")
        temp=new Pro_User(u->getUsername(),u->getPassword(), u->getName(), u->getSurname());

    if(temp){
        removeUserToDB(u);
        users.push_back(temp);
        SaveAndClose();
    }
}

void UserDatabase::addUserToDB(User *u){
    User* add_user=getUser(u->getUsername());
    if(add_user){
        QMessageBox::warning(0,"Errore inserimento utente", "Username già in uso! Riprova.");
        delete u;
        u=nullptr;
    }
    else{
        users.push_back(u);
        QMessageBox::information(0,"Inserimento utente", "Inserimento avvenuto con successo!");
        SaveAndClose();
    }
}

void UserDatabase::removeUserToDB(User *u){
    auto it=users.begin();
    for(; it!=users.end(); ++it){
        if((*it)->getUsername()==u->getUsername()){
            delete *it;
            it=users.erase(it);
            it--;
        }
    }
}

void UserDatabase::Load() {
    QFile file("UserDatabase.xml");
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QXmlStreamReader xmlReader(&file);
        xmlReader.readNextStartElement();
        while(!xmlReader.atEnd()){
            User* u=nullptr;
            if(xmlReader.name()=="Admin") u=new User_Admin;
            else if(xmlReader.name()=="Standard_User") u=new Standard_User;
            else if(xmlReader.name()=="Pro_User") u=new Pro_User;

            if(u){
                u->loadCommonFieldsUser(xmlReader);
                if((u)->getLabel()=="Standard_User"){
                    dynamic_cast<Standard_User*>(u)->loadPersonalItem(xmlReader);
                    xmlReader.readNextStartElement();
                }
                users.push_back(u);
            }
            xmlReader.readNextStartElement();
        }
    }
    else{
        QMessageBox::warning(0,"Database mancante","Creazione database di default degli utenti");
    }
}

void UserDatabase::SaveAndClose(){
    QFile file("UserDatabase.xml");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("Utenti");
    auto it=users.begin();
    for(; it!=users.end(); ++it){
        (*it)->saveUser(xmlWriter);
        if((*it)->getLabel()=="Standard_User") dynamic_cast<Standard_User*>(*it)->savePersonalItem(xmlWriter);
        xmlWriter.writeEndElement();
    }
    xmlWriter.writeEndElement();
    xmlWriter.writeEndDocument();
    file.close();
}
