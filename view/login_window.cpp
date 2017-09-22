#include "login_window.h"

LoginWindow::LoginWindow(){
    this->setAttribute(Qt::WA_DeleteOnClose);
    setWindowTitle("MangAnimeList");

    setFixedHeight(700);
    setFixedWidth(250);

    windowIcon = new QLabel();
    windowIcon->setAlignment(Qt::AlignCenter);
    QPixmap image(":/icon.png");
    windowIcon->setPixmap(image.scaled(250,240,Qt::KeepAspectRatio));

    labelLogin=new QLabel("Login");
    labelUsernameLogin=new QLabel("Username:");
    labelPasswordLogin=new QLabel("Password:");
    textUsernameLogin=new QLineEdit();
    textPasswordLogin=new QLineEdit();
    textUsernameLogin->setPlaceholderText("Inserisci username");
    textPasswordLogin->setPlaceholderText("Inserisci password");
    textUsernameLogin->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]{1,15}")));
    textPasswordLogin->setEchoMode(QLineEdit::Password);
    pushLogin=new QPushButton("Login");

    gridLogin=new QGridLayout;
    gridLogin->addWidget(windowIcon);
    gridLogin->addWidget(labelLogin);
    gridLogin->addWidget(labelUsernameLogin);
    gridLogin->addWidget(textUsernameLogin);
    gridLogin->addWidget(labelPasswordLogin);
    gridLogin->addWidget(textPasswordLogin);
    gridLogin->addWidget(pushLogin);

    labelRegister=new QLabel("Register");
    labelUsernameRegister=new QLabel("Username:");
    labelPasswordRegister=new QLabel("Password:");
    labelName=new QLabel("Name:");
    labelSurname=new QLabel("Surname:");
    textUsernameRegister=new QLineEdit();
    textUsernameRegister->setToolTip("L'username deve avere almeno 6 caratteri");
    textPasswordRegister=new QLineEdit();
    textPasswordRegister->setToolTip("La password deve avere almeno 6 caratteri");
    textName=new QLineEdit();
    textSurname=new QLineEdit();
    textUsernameRegister->setPlaceholderText("Inserisci username");
    textPasswordRegister->setPlaceholderText("Inserisci password");
    textName->setPlaceholderText("Inserisci nome");
    textSurname->setPlaceholderText("Inserisci cognome");
    textUsernameRegister->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]{1,20}")));
    textPasswordRegister->setEchoMode(QLineEdit::Password);
    textName->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]{1,20}")));
    textSurname->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]{1,20}")));
    pushRegister=new QPushButton("Register");

    gridRegister=new QGridLayout;
    gridRegister->addWidget(labelRegister);
    gridRegister->addWidget(labelUsernameRegister);
    gridRegister->addWidget(textUsernameRegister);
    gridRegister->addWidget(labelPasswordRegister);
    gridRegister->addWidget(textPasswordRegister);
    gridRegister->addWidget(labelName);
    gridRegister->addWidget(textName);
    gridRegister->addWidget(labelSurname);
    gridRegister->addWidget(textSurname);
    gridRegister->addWidget(pushRegister);

    layoutLogin=new QVBoxLayout();
    layoutLogin->addLayout(gridLogin);
    layoutLogin->addLayout(gridRegister);
    setLayout(layoutLogin);
    connect(pushLogin,SIGNAL(clicked()),this,SLOT(login()));
    connect(pushRegister,SIGNAL(clicked()),this,SLOT(register_user()));
}

void LoginWindow::login(){
    emit doLogin(textUsernameLogin->text(),textPasswordLogin->text());
}

void LoginWindow::register_user(){
    emit doRegister(textUsernameRegister->text(),textPasswordRegister->text(),textName->text(),textSurname->text());
}

void LoginWindow::empty(){
    textUsernameLogin->clear();
    textPasswordLogin->clear();
    textUsernameRegister->clear();
    textPasswordRegister->clear();
    textName->clear();
    textSurname->clear();
    textUsernameLogin->setFocus();
}
