#include "user_settings.h"

UserSettings::UserSettings(User *user, User *editedus):user(user),editeduser(editedus){
    this->setAttribute(Qt::WA_DeleteOnClose);
    setWindowTitle("Informazioni Utente");
    addModLayout();
}

void UserSettings::addModLayout(){
    labelName=new QLabel("Nome");
    labelSurname=new QLabel("Cognome");
    labelUsername=new QLabel("Username");
    labelPassword=new QLabel("Password");
    Type=new QLabel("Tipologia Account");

    labelType=new QLabel(editeduser->getLabel());
    textName=new QLineEdit();
    textName->setValidator(new QRegExpValidator(QRegExp("[A-Za-z\\s]{1,15}")));
    textSurname=new QLineEdit();
    textSurname->setValidator(new QRegExpValidator(QRegExp("[A-Za-z\\s]{1,15}")));
    textUsername=new QLineEdit();
    textUsername->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]{1,15}")));
    textPassword=new QLineEdit();
    textPassword->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]{1,15}")));
    selectType=new QComboBox();
    selectType->addItem("Standard_User");
    selectType->addItem("Pro_User");
    selectType->addItem("Admin");

    int index= selectType->findText(editeduser->getLabel());
    selectType->setCurrentIndex(index);
    selectType->itemText(index);

    textName->setPlaceholderText("Inserisci nome");
    textSurname->setPlaceholderText("Inserisci cognome");
    textUsername->setPlaceholderText("Inserisci username");
    textPassword->setPlaceholderText("Inserisci password");

    textUsername->setText(editeduser->getUsername());
    textPassword->setText(editeduser->getPassword());
    textName->setText(editeduser->getName());
    textSurname->setText(editeduser->getSurname());

    pushModify=new QPushButton("Salva le modifiche effettuate");
    pushDelete=new QPushButton("Elimina l'utente");
    pushAdd=new QPushButton("Aggiungi utente");

    gridUserSettings=new QGridLayout;
    gridUserSettings->addWidget(labelUsername,0,0);
    gridUserSettings->addWidget(labelPassword,1,0);
    gridUserSettings->addWidget(labelName,2,0);
    gridUserSettings->addWidget(labelSurname,3,0);

    gridUserSettings->addWidget(textUsername,0,1);
    gridUserSettings->addWidget(textPassword,1,1);
    gridUserSettings->addWidget(textName,2,1);
    gridUserSettings->addWidget(textSurname,3,1);

    gridUserSettings->addWidget(Type,4,0);
    gridUserSettings->addWidget(selectType,4,1);
    gridUserSettings->addWidget(labelType,4,1);
    gridUserSettings->addWidget(pushModify,6,0);
    gridUserSettings->addWidget(pushDelete,6,1);
    gridUserSettings->addWidget(pushAdd,7,0);

    layoutUserSettings=new QVBoxLayout();
    layoutUserSettings->addLayout(gridUserSettings);

    connect(pushModify,SIGNAL(clicked()),this,SLOT(save_change_user()));
    connect(pushAdd,SIGNAL(clicked()),this,SLOT(addUser()));
    connect(pushDelete,SIGNAL(clicked()),this,SLOT(save_delete()));
    setLayout(layoutUserSettings);
}

void UserSettings::setModLayout(){
    pushAdd->hide();
    if(user->AlterUsers() && user->getUsername() !=  editeduser->getUsername()){
        textPassword->setEchoMode(QLineEdit::PasswordEchoOnEdit);
        labelType->hide();
    }
    else{
        selectType->hide();
        pushDelete->hide();
    }
}

void UserSettings::changeUsername(){
    textUsername->clear();
    textUsername->setText(editeduser->getUsername());
    textUsername->setFocus();
}

void UserSettings::empty(){
    textPassword->clear();
    textUsername->clear();
    textName->clear();
    textSurname->clear();
    textUsername->setFocus();
}

void UserSettings::setLayoutAdd(){
    pushAdd->show();
    pushDelete->hide();
    pushModify->hide();
    labelType->hide();
    selectType->show();
    this->empty();
}

void UserSettings::save_change_user(){
    if(textUsername->text() != "" && textPassword->text() != "" && textName->text() != "" && textSurname->text() != ""){
        emit sendChanges(editeduser,textUsername->text(),textPassword->text(),
                         textName->text(), textSurname->text(), selectType->currentText());
    }
    else{
        textUsername->setText(editeduser->getUsername());
        textPassword->setText(editeduser->getPassword());
        textName->setText(editeduser->getName());
        textSurname->setText(editeduser->getSurname());
        QMessageBox::warning(0,"Modifiche fallite","Compilare tutti i campi");
    }
}

void UserSettings::addUser(){
    if(textUsername->text() != "" && textPassword->text() != "" && textName->text() != "" && textSurname->text() != ""){
        User *generalUser=nullptr;
        if(selectType->currentText()=="Standard_User")
            generalUser= new Standard_User(textUsername->text(),textPassword->text(), textName->text(),textSurname->text());

        else if(selectType->currentText()=="Pro_User")
            generalUser= new Pro_User(textUsername->text(),textPassword->text(), textName->text(),textSurname->text());

        else if(selectType->currentText()=="Admin")
            generalUser= new User_Admin(textUsername->text(),textPassword->text(), textName->text(),textSurname->text());

        emit thisUser(generalUser);
    }
    else
        QMessageBox::warning(0,"Attenzione","E' necessario riempire tutti i campi dati");

}

void UserSettings::save_delete(){
    emit sendDelete(editeduser);
    if(user==editeduser){
        emit logout();
    }
    this->close();
}
