#include "user_admin.h"
#include <QDebug>

User_Admin::User_Admin(const QString& usrnm, const QString& pwd, const QString& nm, const QString& srnm):
    User(usrnm, pwd, nm, srnm){}

QString User_Admin::getLabel() const{
    return "Admin";
}
bool User_Admin::AlterUsers() const{
    return true;
}
bool User_Admin::AlterItems() const{
    return true;
}
bool User_Admin::proFunctions() const{
    return false;
}
