#ifndef USER_CONTROLLER
#define USER_CONTROLLER

#include "../model/user_database.h"
#include "../view/user_settings.h"
#include "../view/view_item.h"
#include <QObject>
#include <QMessageBox>

class User_Controller:public QObject{
private:
    Q_OBJECT
    UserDatabase * allUsers;
    UserSettings * viewUsers;
    ViewItem * viewItems;

public:
    User_Controller(UserDatabase* dbUser, QObject* parent=0);
    void updateUserView(UserSettings*);
    void updateItemStatusView(ViewItem*);

public slots:
    void addUserController(User*);
    void getChangesUser(User*, QString, QString, QString, QString, QString);
    void getDeleteUser(User*);
    void getChangesStatus(Item*,User*, QString, QString);

};

#endif // USER_CONTROLLER

