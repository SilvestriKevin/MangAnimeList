#include "user_controller.h"

User_Controller::User_Controller(UserDatabase *dbUser, QObject *parent):QObject(parent), allUsers(dbUser) {
    viewUsers=nullptr;
}

void User_Controller::updateUserView(UserSettings *usv){
    viewUsers=usv;
    connect(viewUsers,SIGNAL(thisUser(User*)),this,SLOT(addUserController(User*)));
    connect(viewUsers,SIGNAL(sendChanges(User*,QString,QString,QString,QString,QString)),this,SLOT(getChangesUser(User*,QString,QString,QString,QString,QString)));
    connect(viewUsers,SIGNAL(sendDelete(User*)),this,SLOT(getDeleteUser(User*)));
}

void User_Controller::updateItemStatusView(ViewItem * viewitem)
{
    viewItems=viewitem;

    connect(viewItems,SIGNAL(sendInsertStatus(Item*,User*, QString, QString)),this,SLOT(getChangesStatus(Item*,User*, QString, QString)));


}

void User_Controller::addUserController(User *u){
    viewUsers->empty();
    allUsers->addUserToDB(u);
}

void User_Controller::getChangesUser(User * us,  QString username, QString password, QString name, QString surname, QString type){
    if(us->getUsername() != username && allUsers->findUsername(username)){
        viewUsers->changeUsername();
        QMessageBox::information(0,"Modifiche utente", "Username già in uso! Riprova.");
    }
    else{
        us->setUsername(username);
        us->setPassword(password);
        us->setName(name);
        us->setSurname(surname);

        if(type != us->getLabel()){
            allUsers->upgradeUserGrade(us,type);
        }
        QMessageBox::information(0,"Modifiche utente", "Modifiche utente avvenute con successo!");
        allUsers->SaveAndClose();
        viewUsers->close();
    }
}

void User_Controller::getDeleteUser(User *us){
    allUsers->removeUserToDB(us);
    allUsers->SaveAndClose();
    QMessageBox::warning(0,"Eliminazione utente","Utente eliminato con successo!");
}

void User_Controller::getChangesStatus(Item *item, User *user, QString currentStatus, QString status)
{
    if(currentStatus!=status && currentStatus=="Nessuno")
    dynamic_cast<Standard_User*>(user)->getMapItem()->remove(item->getCodeNumber());
    else if(currentStatus!=status && status=="Nessuno")
        dynamic_cast<Standard_User*>(user)->getMapItem()->insert(item->getCodeNumber(),currentStatus);
    else{
        auto it=dynamic_cast<Standard_User*>(user)->getMapItem()->find(item->getCodeNumber());
        it.value()=currentStatus;
    }
    QMessageBox::information(0,"Modifiche status","Hai modificato con successo lo status!");
    allUsers->SaveAndClose();
    viewItems->close();
}
