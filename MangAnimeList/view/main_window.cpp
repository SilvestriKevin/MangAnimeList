#include "main_window.h"
#include <QPixmap>

MainWindow::MainWindow(UserDatabase *dbus, ItemDatabase *dbit, User *u, QWidget *parent):
    QMainWindow(parent),allUsers(dbus), allItems(dbit), user(u){
    this->setAttribute(Qt::WA_DeleteOnClose);
    setWindowTitle("MangAnimeList");

    setFixedHeight(700);
    setFixedWidth(1000);

    QRect wmainPosition = geometry();
    wmainPosition.moveCenter(QApplication::desktop()->availableGeometry().center());
    setGeometry(wmainPosition);

    setMenuOptions();
    searchfromDB=nullptr;
    viewUserSettings=nullptr;
    viewAccountSettings=nullptr;
    viewItemSettings=nullptr;
    doSearch();
}

void MainWindow::setMenuOptions(){
    menuOptions=new QMenu("Profile",this);
    menuAccountSettings=new QAction("Settings",this);
    menuLogout=new QAction("Log Out",this);
    menuOptions->addAction(menuAccountSettings);
    menuOptions->addAction(menuLogout);

    connect(menuAccountSettings,SIGNAL(triggered(bool)),this,SLOT(openAccountSettings()));
    connect(menuLogout,SIGNAL(triggered(bool)),this,SLOT(closeSession()));

    menuBar()->addMenu(menuOptions);

    if(user->AlterUsers() || user->AlterItems()) menuSettings=new QMenu("Add",this);

    if(user->AlterUsers()){
        menuUserSettings=new QAction("User",this);
        menuSettings->addAction(menuUserSettings);
        connect(menuUserSettings,SIGNAL(triggered(bool)),this,SLOT(openUserSettings()));
        menuBar()->addMenu(menuSettings);
    }

    if(user->AlterItems()){
        menuItemSettings=new QAction("Item", this);
        menuSettings->addAction(menuItemSettings);
        connect(menuItemSettings,SIGNAL(triggered(bool)),this,SLOT(openItemSettings()));
        menuBar()->addMenu(menuSettings);
    }

    menuViews=new QMenu("List",this);

    if(user->proFunctions() || user->AlterUsers()){

        menuViewAllUsers=new QAction("All Users", this);
        menuViews->addAction(menuViewAllUsers);

        connect(menuViewAllUsers,SIGNAL(triggered(bool)),this,SLOT(searchUsers()));
    }

    menuViewAllItems=new QAction("All Items", this);
    menuViewAllManga=new QAction("All Manga", this);
    menuViewAllAnime=new QAction("All Anime", this);

    menuViews->addAction(menuViewAllItems);
    menuViews->addAction(menuViewAllManga);
    menuViews->addAction(menuViewAllAnime);

    connect(menuViewAllItems,SIGNAL(triggered(bool)),this,SLOT(searchItems()));
    connect(menuViewAllManga,SIGNAL(triggered(bool)),this,SLOT(searchManga()));
    connect(menuViewAllAnime,SIGNAL(triggered(bool)),this,SLOT(searchAnime()));

    menuBar()->addMenu(menuViews);

    menuInfo=new QMenu("Info",this);
    menuInfoclick=new QAction("About M.A.L.", this);
    menuInfo->addAction(menuInfoclick);
    menuBar()->addMenu(menuInfo);
    connect(menuInfoclick, SIGNAL(triggered(bool)),this,SLOT(openInfo()));
}

void MainWindow::openInfo(){
    QMessageBox info;
    info.setWindowFlags(Qt::WindowTitleHint);
    info.setWindowTitle("Informazioni sul programma");
    info.setText("MangAnimeList e' un programma creato per gli appassionati di manga "
                 "(fumetti giapponesi) ed anime (cartoni animati giapponesi). Lo sviluppatore è Silvestri Kevin.");
    info.exec();
}

void MainWindow::doSearch(){
    searchfromDB=new DBSearch(allItems, allUsers, user);
    connect(searchfromDB,SIGNAL(close_mainwindow()),this,SLOT(closeWindows()));
    connect(searchfromDB, SIGNAL(savechanges_User(UserSettings*)),this,SLOT(updateAccountSettings(UserSettings*)));
    connect(searchfromDB,SIGNAL(savechanges_Item(ItemSettings*)),this,SIGNAL(updateItemSettings(ItemSettings*)));
    connect(searchfromDB,SIGNAL(savechanges_Status(ViewItem*)),this,SIGNAL(updateItemStatus(ViewItem*)));
    setCentralWidget(searchfromDB);
}

void MainWindow::openUserSettings(){
    openSettings();
    viewAccountSettings->setLayoutAdd();
    viewAccountSettings->show();
}

void MainWindow::openAccountSettings(){
    openSettings();
    viewAccountSettings->setModLayout();
    viewAccountSettings->show();
}

void MainWindow::openSettings(){
    viewAccountSettings=new UserSettings(user,user);
    closeWindows();
    connect(viewAccountSettings,SIGNAL(finished(int)),this,SLOT(closeWindows()));
    emit(updateUserSettings(viewAccountSettings));
}

void MainWindow::openItemSettings(){
    viewItemSettings=new ItemSettings(user);
    closeWindows();
    connect(viewItemSettings,SIGNAL(finished(int)),this,SLOT(closeWindows()));
    emit(updateItemSettings(viewItemSettings));
    viewItemSettings->setNewLayout();
    viewItemSettings->show();
}

void MainWindow::updateAccountSettings(UserSettings *userprofile){
    emit updateUserSettings(userprofile);
}

void MainWindow::searchUsers(){
    searchfromDB->searchUsersView();
}

void MainWindow::searchItems(){
    searchfromDB->searchItemsView();
}

void MainWindow::searchManga(){
    searchfromDB->searchMangaView();
}

void MainWindow::searchAnime(){
    searchfromDB->searchAnimeView();
}

void MainWindow::closeSession(){
    emit doLogout();
    this->close();
}

void MainWindow::closeWindows(){
    if(isEnabled()) this->setEnabled(0);
    else this->setEnabled(1);
}
