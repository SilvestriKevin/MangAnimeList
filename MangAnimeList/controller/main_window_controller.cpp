#include "main_window_controller.h"


MainWindowController::MainWindowController(QObject* parent) : QObject(parent){
    login=nullptr;
    userController=nullptr;
    itemController=nullptr;

    mainWindow=nullptr;
    allItems= new ItemDatabase();
    allUsers = new UserDatabase();
}

MainWindowController::~MainWindowController(){
    delete allItems;
    delete allUsers;
}

void MainWindowController::Login(){
    login=new LoginWindow();
    connect(login,SIGNAL(doLogin(QString,QString)),this,SLOT(doLoginController(QString,QString)));
    connect(login,SIGNAL(doRegister(QString,QString,QString,QString)),this,SLOT(doRegisterController(QString,QString,QString,QString)));
    login->show();
    userController=new User_Controller(allUsers,this);
    itemController=new Item_Controller(allItems,this);
}

void MainWindowController::doLoginController(const QString &username, const QString &password){
    logged_user=allUsers->checkUser(username,password);
    if(!logged_user){
        QMessageBox::warning(0,"Errore login", "Errore con le credenziali, ritenta!");
        login->empty();
    }
    else{
        mainWindow = new MainWindow(allUsers,allItems,logged_user);
        connect(mainWindow,SIGNAL(doLogout()),this,SLOT(updateLogin()));
        connect(mainWindow,SIGNAL(updateUserSettings(UserSettings*)),this,SLOT(updateUserController(UserSettings*)));
        connect(mainWindow,SIGNAL(updateItemSettings(ItemSettings*)),this,SLOT(updateItemController(ItemSettings*)));
        connect(mainWindow,SIGNAL(updateItemStatus(ViewItem*)),this,SLOT(updateItemStatusController(ViewItem*)));

        login->close();
        login=nullptr;
        mainWindow->show();
    }
}

void MainWindowController::doRegisterController(const QString &username, const QString &password,const QString &name,const QString &surname){
    if(username != "" && password != "" && name != "" && surname != ""){

        if(username.length()>5){
            if(password.length()>5){
                User * generalUser=nullptr;
                generalUser= new Standard_User(username,password,name,surname);
                allUsers->addUserToDB(generalUser);
                login->empty();
            }else QMessageBox::warning(0,"Attenzione","La password deve essere lunga almeno 6 caratteri");
        }
        else QMessageBox::warning(0,"Attenzione","L'username deve essere lungo almeno 6 caratteri");
    }
    else
        QMessageBox::warning(0,"Attenzione","E' necessario riempire tutti i campi dati");
}

void MainWindowController::updateLogin(){
    if(!login)
        login=new LoginWindow();

    connect(login,SIGNAL(doLogin(QString,QString)),this,SLOT(doLoginController(QString,QString)));
    connect(login,SIGNAL(doRegister(QString,QString,QString,QString)),this,SLOT(doRegisterController(QString,QString,QString,QString)));

    login->empty();
    login->show();
}

void MainWindowController::updateUserController(UserSettings * viewus){
    userController->updateUserView(viewus);
}

void MainWindowController::updateItemController(ItemSettings* itemview){
    itemController->updateItemView(itemview);
}

void MainWindowController::updateItemStatusController(ViewItem* viewitem){
    userController->updateItemStatusView(viewitem);
}



