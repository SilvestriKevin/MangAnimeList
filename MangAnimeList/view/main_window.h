#ifndef MAINWINDOW
#define MAINWINDOW

#include <QMainWindow>
#include <QPixmap>
#include <QIcon>
#include <QMenuBar>
#include <QAction>
#include <QApplication>
#include <QDesktopWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QMainWindow>
#include "../model/user_database.h"
#include "../model/item_database.h"
#include "search_window.h"
#include "user_settings.h"

class MainWindow : public QMainWindow{
private:
    Q_OBJECT
    UserDatabase* allUsers;
    ItemDatabase* allItems;
    User* user;

    QMenu * menuOptions;
    QAction * menuAccountSettings;
    QAction * menuLogout;

    QMenu * menuSettings;
    QAction * menuUserSettings;
    QAction * menuItemSettings;

    QMenu * menuViews;
    QAction * menuViewAllUsers;
    QAction * menuViewAllItems;
    QAction * menuViewAllManga;
    QAction * menuViewAllAnime;

    QMenu * menuInfo;
    QAction * menuInfoclick;

    DBSearch * searchfromDB;

    UserSettings * viewUserSettings;
    UserSettings * viewAccountSettings;
    ItemSettings * viewItemSettings;

public:
    MainWindow(UserDatabase * dbus=0, ItemDatabase *dbit=0, User *u=0, QWidget *parent =0);
    void setMenuOptions();
    void doSearch();
    void openSettings();

public slots:
    void openUserSettings();
    void openAccountSettings();
    void openItemSettings();
    void updateAccountSettings(UserSettings*);
    void searchUsers();
    void searchItems();
    void searchManga();
    void searchAnime();
    void closeWindows();
    void closeSession();

private slots:
    void openInfo();

signals:
    void closeMainWindow();
    void doLogout();
    void updateUserSettings(UserSettings*);
    void updateItemSettings(ItemSettings*);
    void updateItemStatus(ViewItem*);
    void searchUsersView();
    void searchItemsView();
    void searchMangaView();
    void searchAnimeView();

};
#endif // MAINWINDOW
