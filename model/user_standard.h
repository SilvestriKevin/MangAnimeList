#ifndef STANDARD_USER
#define STANDARD_USER

#include "user.h"
#include "item.h"
#include "item_database.h"
#include <QMap>

class Standard_User: public User{
private:
    QMap<int,QString> listItem;

public:
    Standard_User(const QString& usrnm="", const QString& pwd="", const QString& nm="", const QString& srnm="");

    virtual QString getLabel() const;
    virtual bool AlterUsers() const;
    virtual bool AlterItems() const;
    virtual bool proFunctions() const;

    QMap<int, QString>* getMapItem();
    const QList<Item*> getListItem(const QString&, ItemDatabase*) const;
    QString getStatus(int) const;

    void loadPersonalItem(QXmlStreamReader &);
    void savePersonalItem(QXmlStreamWriter &);
};
#endif // STANDARD_USER

