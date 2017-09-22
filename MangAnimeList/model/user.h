#ifndef USER
#define USER

#include "item.h"
#include "item_database.h"
#include <QString>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>

class User{
private:
    QString username;
    QString password;
    QString name;
    QString surname;

public:
    User(const QString& usrnm="", const QString& pwd="", const QString& nm="", const QString& srnm="");
    virtual ~User()=default;

    virtual QString getLabel() const = 0;
    virtual bool AlterUsers() const =0;
    virtual bool AlterItems() const =0;
    virtual bool proFunctions() const =0;

    QString getUsername() const;
    QString getPassword() const;
    QString getName()const;
    QString getSurname()const;

    void setUsername(const QString&);
    void setPassword(const QString&);
    void setName(const QString&);
    void setSurname(const QString&);

    void saveCommonFieldsUser(QXmlStreamWriter&);
    void loadCommonFieldsUser(QXmlStreamReader&);

    virtual void saveUser(QXmlStreamWriter&);

};
#endif // USER

