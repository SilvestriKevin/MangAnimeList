#ifndef MAINWINDOW_CONTROLLER
#define MAINWINDOW_CONTROLLER

#include "../model/item_database.h"
#include "../model/user_database.h"
#include "../view/login_window.h"
#include "../view/main_window.h"
#include "user_controller.h"
#include "item_controller.h"
#include <QObject>
#include <QMessageBox>

class MainWindowController:public QObject{
private:
    Q_OBJECT
    ItemDatabase* allItems;
    UserDatabase* allUsers;

    User* logged_user;
    User* new_user;

    LoginWindow* login;
    MainWindow* mainWindow;

    User_Controller* userController;
    Item_Controller* itemController;

public:
    MainWindowController(QObject* parent=0);
    ~MainWindowController();
    void Login();

public slots:
    void doLoginController(const QString &, const QString &);
    void doRegisterController(const QString &,const QString &,const QString &, const QString &);
    void updateLogin();
    void updateUserController(UserSettings*);
    void updateItemController(ItemSettings*);
    void updateItemStatusController(ViewItem*);
};

#endif // MAINWINDOW_CONTROLLER
