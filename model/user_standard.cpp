#include "user_standard.h"
#include "math.h"
#include <iostream>
using std::cout;

Standard_User::Standard_User(const QString& usrnm, const QString& pwd, const QString& nm, const QString& srnm):
    User(usrnm, pwd, nm, srnm){}

QString Standard_User::getLabel() const{
    return "Standard_User";
}
bool Standard_User::AlterUsers() const{
    return false;
}
bool Standard_User::AlterItems() const{
    return false;
}
bool Standard_User::proFunctions() const{
    return false;
}

QMap<int, QString>* Standard_User::getMapItem()
{
    return &listItem;
}

const QList<Item*> Standard_User::getListItem(const QString& type, ItemDatabase* listItemsDB) const
{
    QList<Item*> temp;
    auto it=listItem.begin();
    for(; it!=listItem.end(); ++it){
        if(it.value()==type) temp.push_back(listItemsDB->getItem(it.key()));
    }
    return temp;
}

QString Standard_User::getStatus(int cod) const
{
    auto it = listItem.find(cod);
    if(it!=listItem.end()) return it.value();
    else return "Nessuno";
}

void Standard_User::loadPersonalItem(QXmlStreamReader &xmlReader){
        int cod;
        xmlReader.readNextStartElement();
        while(xmlReader.name()=="Item") {
            xmlReader.readNextStartElement();
            cod = (xmlReader.readElementText()).toInt();
            xmlReader.readNextStartElement();
            listItem.insert(cod,xmlReader.readElementText());
            xmlReader.readNextStartElement();
            xmlReader.readNextStartElement();
        }
}

void Standard_User::savePersonalItem(QXmlStreamWriter &xmlWriter){
    xmlWriter.writeStartElement("Items");
    auto it=listItem.begin();
    for(; it!=listItem.end(); ++it){
        xmlWriter.writeStartElement("Item");
        xmlWriter.writeTextElement("Cod",QString::number(it.key()));
        xmlWriter.writeTextElement("Status",it.value());
        xmlWriter.writeEndElement();
    }
    xmlWriter.writeEndElement();
}
