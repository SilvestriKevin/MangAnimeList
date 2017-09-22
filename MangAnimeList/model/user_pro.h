#ifndef USER_PRO
#define USER_PRO

#include "user.h"

class Pro_User: public User{
public:
    Pro_User(const QString& usrnm="", const QString& pwd="", const QString& nm="", const QString& srnm="");

    virtual QString getLabel() const;
    virtual bool AlterUsers() const;
    virtual bool AlterItems() const;
    virtual bool proFunctions() const;
};
#endif // USER_PRO

