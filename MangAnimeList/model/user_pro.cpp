#include "user_pro.h"

Pro_User::Pro_User(const QString& usrnm, const QString& pwd, const QString& nm, const QString& srnm):
    User(usrnm, pwd, nm, srnm){}

QString Pro_User::getLabel() const{
   return "Pro_User";
}
bool Pro_User::AlterUsers() const{
    return false;
}
bool Pro_User::AlterItems() const{
    return true;
}
bool Pro_User::proFunctions() const{
  return true;
}

