#include "user.h"

User::User(const QString& usrnm, const QString& pwd, const QString &nm, const QString &srnm):
    username(usrnm), password(pwd), name(nm), surname(srnm){}

QString User::getUsername() const {
    return username;
}
QString User::getPassword() const {
    return password;
}
QString User::getName() const {
    return name;
}
QString User::getSurname() const {
    return surname;
}

void User::setUsername(const QString& newUsername){
    username = newUsername;
}
void User::setPassword(const QString& newPassword){
    password = newPassword;
}
void User::setName(const QString& newName){
    name = newName;
}
void User::setSurname(const QString& newSurname){
    surname = newSurname;
}

void User::saveCommonFieldsUser(QXmlStreamWriter &xmlWriter){
    xmlWriter.writeTextElement("Username",getUsername());
    xmlWriter.writeTextElement("Password",getPassword());
    xmlWriter.writeTextElement("Nome",getName());
    xmlWriter.writeTextElement("Cognome",getSurname());
}

void User::loadCommonFieldsUser(QXmlStreamReader &xmlReader){
    xmlReader.readNextStartElement();
    if(xmlReader.name()=="Username") {
        setUsername(xmlReader.readElementText());
        xmlReader.readNextStartElement();
    }
    if(xmlReader.name()=="Password") {
        setPassword(xmlReader.readElementText());
        xmlReader.readNextStartElement();
    }
    if(xmlReader.name()=="Nome") {
        setName(xmlReader.readElementText());
        xmlReader.readNextStartElement();
    }
    if(xmlReader.name()=="Cognome") {
        setSurname(xmlReader.readElementText());
        xmlReader.readNextStartElement();
    }
}

void User::saveUser(QXmlStreamWriter &xmlWriter){
    xmlWriter.writeStartElement(getLabel());
    saveCommonFieldsUser(xmlWriter);
}
