#ifndef USER_ADMIN
#define USER_ADMIN

#include "user.h"
#include "item.h"
#include "user_database.h"
#include "item_database.h"

class User_Admin: public User{
public:
    User_Admin(const QString& usrnm="", const QString& pwd="", const QString& nm="", const QString& srnm="");

    virtual QString getLabel() const;
    virtual bool AlterUsers() const;
    virtual bool AlterItems() const;
    virtual bool proFunctions() const;

};
#endif // USER_ADMIN

