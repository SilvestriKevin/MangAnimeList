#ifndef SEARCHWINDOW
#define SEARCHWINDOW

#include <QDialog>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QString>
#include <QComboBox>
#include <QHeaderView>
#include "../model/item_database.h"
#include "../model/user_database.h"
#include "list.h"
#include "item_settings.h"
#include "view_item.h"
#include "user_settings.h"

class DBSearch:public QWidget{
private:
    Q_OBJECT
    ItemDatabase * listItems;
    UserDatabase * listUsers;
    User * user;

    QLineEdit * textSearch;
    QLineEdit * name;
    QLineEdit * surname;
    QLineEdit * username;
    QLineEdit * password;

    QComboBox * searchFor;
    QComboBox * stateFor;
    QComboBox * genreFor;

    QLabel * profileIcon;
    QLabel * labelName;
    QLabel * labelSurname;
    QLabel * labelUsername;
    QLabel * labelPassword;
    QLabel * labelAnime;
    QLabel * labelManga;

    QPushButton * pushSearch;
    QPushButton * pushRefreshList;
    QPushButton * pushViewed;
    QPushButton * pushRead;
    QPushButton * pushSeing;
    QPushButton * pushReading;
    QPushButton * pushToBeSeen;
    QPushButton * pushToRead;

    QGroupBox * refresh;
    QGroupBox * search;
    QGroupBox * info;
    QGroupBox * item;

    QGridLayout * gridIcon;
    QGridLayout * gridInfo;
    QGridLayout * gridOptions;
    QGridLayout * gridMain;
    QGridLayout * gridFinal;
    QGridLayout * gridRefresh;
    QGridLayout * gridSearch;

    QHBoxLayout * layoutSearch;
    QHBoxLayout * layoutRefresh;
    QHBoxLayout * layoutProfile;
    QHBoxLayout * layoutOptionsItems;
    QHBoxLayout * infoLayout;
    QHBoxLayout * mainLayout;
    QVBoxLayout * finalLayout;
    QVBoxLayout * totalLayout;

    DBList * table;
    UserSettings * info_user;
    ItemSettings * info_item;
    ViewItem * view_item;

public:
    DBSearch(ItemDatabase * dbIt=0, UserDatabase *dbUs=0, User *user=0, QWidget *parent =0);
    void newLayout();
    void searchUsersView();
    void searchItemsView();
    void searchMangaView();
    void searchAnimeView();

public slots:
    void refreshList();
    void searchUSER();
    void searchITEMS();
    void searchItem();
    void searchListItem();
    void searchMANGA();
    void searchANIME();
    void doubleclick(int);

signals:
    void savechanges_User(UserSettings*);
    void savechanges_Item(ItemSettings*);
    void savechanges_Status(ViewItem*);
    void searchUsers();
    void searchItems();
    void searchManga();
    void searchAnime();
    void close_mainwindow();
};
#endif // SEARCHWINDOW

