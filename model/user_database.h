#ifndef USER_DATABASE
#define USER_DATABASE

#include "user_admin.h"
#include "user_standard.h"
#include "user_pro.h"
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QString>

class UserDatabase{
private:
    QList<User*> users;

public:
    UserDatabase();
    ~UserDatabase();

    User* getUser(const QString &);
    const QList<User*> getAllUsers()const;
    QList<User*> searchUsers(const QString &) const;
    bool findUsername(const QString &);
    User *checkUser(const QString&, const QString&);
    void upgradeUserGrade(User*, QString );
    void addUserToDB(User*);
    void removeUserToDB(User*);
    void Load();
    void SaveAndClose();
};
#endif // USER_DATABASE

