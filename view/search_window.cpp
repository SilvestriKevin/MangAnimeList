#include "search_window.h"
#include "QDebug"

DBSearch::DBSearch(ItemDatabase *dbIt, UserDatabase *dbUs, User *user, QWidget *parent):
    QWidget(parent), listItems(dbIt), listUsers(dbUs), user(user){
    this->setAttribute(Qt::WA_DeleteOnClose);
    table=nullptr;
    info_user=nullptr;
    info_item=nullptr;
    newLayout();
    setStyleSheet("QGroupBox{ border: 1px solid gray;  margin-top: 5px;}"
                  "QGroupBox::title{ subcontrol-origin: margin; subcontrol-position:top center;}");
}

void DBSearch::newLayout(){
    pushRefreshList=new QPushButton("Aggiorna Dati");
    pushRefreshList->setFixedWidth(100);
    pushRefreshList->setFixedHeight(40);

    refresh = new QGroupBox(tr("Aggiorna"));
    refresh->setFixedWidth(150);
    refresh->setFixedHeight(100);
    gridRefresh = new QGridLayout();

    gridRefresh->addWidget(pushRefreshList);

    layoutRefresh=new QHBoxLayout();
    layoutRefresh->addLayout(gridRefresh);
    refresh->setLayout(layoutRefresh);

    textSearch=new QLineEdit();
    textSearch->setFixedWidth(300);
    textSearch->setPlaceholderText("Inserisci testo da cercare");
    searchFor=new QComboBox();

    if(user->proFunctions() || user->AlterUsers()){
        searchFor->addItem("Utenti");
    }
    searchFor->addItem("Articoli");
    searchFor->addItem("Manga");
    searchFor->addItem("Anime");
    searchFor->setFixedWidth(100);

    if(user->getLabel()=="Standard_User"){
        stateFor=new QComboBox();
        stateFor->addItem("Stato");
        stateFor->addItem("Terminato");
        stateFor->addItem("In corso");
        stateFor->addItem("Non ancora uscito");

        genreFor=new QComboBox();
        genreFor->addItem("Categoria");
        genreFor->addItem("Arti Marziali");
        genreFor->addItem("Avventura");
        genreFor->addItem("Azione");
        genreFor->addItem("Bambini");
        genreFor->addItem("Combattimento");
        genreFor->addItem("Commedia");
        genreFor->addItem("Crimine");
        genreFor->addItem("Cucina");
        genreFor->addItem("Demenziale");
        genreFor->addItem("Demoni");
        genreFor->addItem("Erotico");
        genreFor->addItem("Fantascienza");
        genreFor->addItem("Fantasy");
        genreFor->addItem("Fiaba");
        genreFor->addItem("Gang Giovanili");
        genreFor->addItem("Giallo");
        genreFor->addItem("Gioco");
        genreFor->addItem("Guerra");
        genreFor->addItem("Hentai");
        genreFor->addItem("Horror");
        genreFor->addItem("Magia");
        genreFor->addItem("Mecha");
        genreFor->addItem("Mistero");
        genreFor->addItem("Musica");
        genreFor->addItem("Parodia");
        genreFor->addItem("Politico");
        genreFor->addItem("Poliziesco");
        genreFor->addItem("Psicologico");
        genreFor->addItem("Scolastico");
        genreFor->addItem("Sentimentale");
        genreFor->addItem("Sketch Comedy");
        genreFor->addItem("Soprannaturale");
        genreFor->addItem("Sperimentale");
        genreFor->addItem("Splatter");
        genreFor->addItem("Sport");
        genreFor->addItem("Storico");
        genreFor->addItem("Supereroi");
        genreFor->addItem("Superpoteri");
        genreFor->addItem("Thriller");
        genreFor->addItem("Visual Novel");
        genreFor->addItem("Western");
        genreFor->addItem("Umorismo");
        genreFor->addItem("Violenza");
    }

    pushSearch=new QPushButton("Cerca");
    pushSearch->setFixedWidth(100);
    pushSearch->setFixedHeight(40);

    search = new QGroupBox(tr("Ricerca"));
    search->setFixedWidth(775);
    search->setFixedHeight(100);
    gridSearch=new QGridLayout();

    gridSearch->addWidget(textSearch,0,1);
    gridSearch->addWidget(searchFor,0,2);
    if(user->getLabel()=="Standard_User"){
        gridSearch->addWidget(stateFor,0,3);
        gridSearch->addWidget(genreFor,0,4);
        gridSearch->addWidget(pushSearch,0,5);
    }
    gridSearch->addWidget(pushSearch,0,3);

    layoutSearch = new QHBoxLayout();
    layoutSearch->addLayout(gridSearch);
    search->setLayout(layoutSearch);

    profileIcon = new QLabel();
    profileIcon->setAlignment(Qt::AlignCenter);
    QPixmap image(":/profile.png");
    profileIcon->setPixmap(image.scaled(200,203,Qt::KeepAspectRatio));

    gridIcon = new QGridLayout();
    gridIcon->addWidget(profileIcon);

    labelName = new QLabel("Nome:");
    labelSurname = new QLabel("Cognome:");
    labelUsername = new QLabel("Username:");
    labelPassword = new QLabel("Password:");
    name = new QLineEdit();
    name->setText(user->getName());
    name->setReadOnly(true);
    surname = new QLineEdit();
    surname->setText(user->getSurname());
    surname->setReadOnly(true);
    username = new QLineEdit();
    username->setText(user->getUsername());
    username->setReadOnly(true);
    password = new QLineEdit();
    password->setText(user->getPassword());
    password->setReadOnly(true);

    gridInfo = new QGridLayout();
    gridInfo->addWidget(labelUsername,0,0);
    gridInfo->addWidget(username,0,1);
    gridInfo->addWidget(labelPassword,1,0);
    gridInfo->addWidget(password,1,1);
    gridInfo->addWidget(labelName,2,0);
    gridInfo->addWidget(name,2,1);
    gridInfo->addWidget(labelSurname,3,0);
    gridInfo->addWidget(surname,3,1);

    info = new QGroupBox(tr("Informazioni Utente"));
    info->setFixedWidth(250);
    info->setFixedHeight(150);

    layoutProfile=new QHBoxLayout();
    layoutProfile->addLayout(gridInfo);
    info->setLayout(layoutProfile);

    if(user->getLabel()=="Standard_User"){
        labelAnime = new QLabel("Anime:");
        labelManga = new QLabel("Manga:");
        pushViewed=new QPushButton("Visto");
        pushViewed->setFixedWidth(100);
        pushViewed->setFixedHeight(25);
        pushRead=new QPushButton("Letto");
        pushRead->setFixedWidth(100);
        pushRead->setFixedHeight(25);
        pushSeing=new QPushButton("Sto vedendo");
        pushSeing->setFixedWidth(100);
        pushSeing->setFixedHeight(25);
        pushReading=new QPushButton("Sto leggendo");
        pushReading->setFixedWidth(100);
        pushReading->setFixedHeight(25);
        pushToBeSeen=new QPushButton("Da vedere");
        pushToBeSeen->setFixedWidth(100);
        pushToBeSeen->setFixedHeight(25);
        pushToRead=new QPushButton("Da leggere");
        pushToRead->setFixedWidth(100);
        pushToRead->setFixedHeight(25);

        gridOptions = new QGridLayout();
        gridOptions->addWidget(labelAnime,0,0);
        gridOptions->addWidget(labelManga,0,1);
        gridOptions->addWidget(pushViewed,1,0);
        gridOptions->addWidget(pushRead,1,1);
        gridOptions->addWidget(pushSeing,2,0);
        gridOptions->addWidget(pushReading,2,1);
        gridOptions->addWidget(pushToBeSeen,3,0);
        gridOptions->addWidget(pushToRead,3,1);

        item = new QGroupBox(tr("Categorie"));
        item->setFixedWidth(250);
        item->setFixedHeight(150);

        layoutOptionsItems=new QHBoxLayout();
        layoutOptionsItems->addLayout(gridOptions);
        item->setLayout(layoutOptionsItems);

        connect(pushViewed,SIGNAL(clicked()),this,SLOT(searchListItem()));
        connect(pushSeing,SIGNAL(clicked(bool)),this,SLOT(searchListItem()));
        connect(pushToBeSeen,SIGNAL(clicked(bool)),this,SLOT(searchListItem()));
        connect(pushRead,SIGNAL(clicked(bool)),this,SLOT(searchListItem()));
        connect(pushReading,SIGNAL(clicked(bool)),this,SLOT(searchListItem()));
        connect(pushToRead,SIGNAL(clicked(bool)),this,SLOT(searchListItem()));
    }

    table= new DBList (listItems, listUsers,this);
    table->setMaximumHeight(400);
    table->setMaximumWidth(933);
    connect(table,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(doubleclick(int)));

    gridFinal = new QGridLayout();
    gridFinal->addWidget(table);

    finalLayout = new QVBoxLayout();
    finalLayout->addLayout(gridFinal);
    finalLayout->setAlignment(Qt::AlignHCenter);

    mainLayout = new QHBoxLayout();
    mainLayout->setAlignment(Qt::AlignHCenter);
    mainLayout->addWidget(refresh);
    mainLayout->addWidget(search);

    infoLayout = new QHBoxLayout();
    infoLayout->setAlignment(Qt::AlignHCenter);
    infoLayout->addLayout(gridIcon);
    infoLayout->addWidget(info);
    if(user->getLabel()=="Standard_User") infoLayout->addWidget(item);

    totalLayout = new QVBoxLayout();
    totalLayout->addLayout(infoLayout);
    totalLayout->addLayout(mainLayout);
    totalLayout->addLayout(finalLayout);

    connect(pushSearch,SIGNAL(clicked(bool)),this,SLOT(searchItem()));
    connect(pushRefreshList,SIGNAL(clicked(bool)),this,SLOT(refreshList()));
    setLayout(totalLayout);
    table->verticalHeader()->hide();
    table->viewItems();
    table->addListAllItems();
    table->show();
}

void DBSearch::searchUsersView(){
    connect(this,SIGNAL(searchUsers()),this,SLOT(searchUSER()));
    emit searchUsers();
}

void DBSearch::searchItemsView(){
    connect(this,SIGNAL(searchItems()),this,SLOT(searchITEMS()));
    emit searchItems();
}

void DBSearch::searchMangaView(){
    connect(this,SIGNAL(searchManga()),this,SLOT(searchMANGA()));
    emit searchManga();
}

void DBSearch::searchAnimeView(){
    connect(this,SIGNAL(searchAnime()),this,SLOT(searchANIME()));
    emit searchAnime();
}

void DBSearch::refreshList(){
    name->setText(user->getName());
    surname->setText(user->getSurname());
    username->setText(user->getUsername());
    password->setText(user->getPassword());
    textSearch->clear();
    if(table->horizontalHeaderItem(0)->text()=="Username"){
        table->viewUsers();
        table->addListAllUsers();
    }
    else if(table->horizontalHeaderItem(0)->text()=="Cod."){
        table->viewItems();
        table->addListAllItems();
    }
    table->verticalHeader()->hide();
    table->show();
}

void DBSearch::searchUSER(){
    textSearch->clear();
    table->viewUsers();
    table->addListAllUsers();
    table->verticalHeader()->hide();
    table->show();
}

void DBSearch::searchITEMS(){
    textSearch->clear();
    table->viewItems();
    table->addListAllItems();
    table->verticalHeader()->hide();
    table->show();
}

void DBSearch::searchItem(){
    QString text_search = textSearch->text();
    QString type = searchFor->currentText();
    QString state = "Stato";
    QString category = "Categoria";
    table->clear();

    if(type=="Utenti"){
        table->viewUsers();
        table->addListUsers(listUsers->searchUsers(text_search));
    }
    else{
        if(user->getLabel()=="Standard_User"){
            state = stateFor->currentText();
            category = genreFor->currentText();
        }

        table->viewItems();
        table->addListItems(listItems->searchItems(text_search,type,state,category));
    }

    table->verticalHeader()->hide();
    table->show();
    textSearch->clear();
}

void DBSearch::searchListItem(){
    QString type;
    table->clear();
    table->viewItems();

    if(((QPushButton*)sender())->text()=="Visto") type = "Visto";
    else if(((QPushButton*)sender())->text()=="Sto vedendo") type = "Sto_vedendo";
    else if(((QPushButton*)sender())->text()=="Da vedere") type = "Da_vedere";
    else if(((QPushButton*)sender())->text()=="Letto") type = "Letto";
    else if(((QPushButton*)sender())->text()=="Sto leggendo") type = "Sto_leggendo";
    else if(((QPushButton*)sender())->text()=="Da leggere") type = "Da_leggere";

    table->addListItems(dynamic_cast<Standard_User*>(user)->getListItem(type,listItems));
    table->verticalHeader()->hide();
    table->show();
    textSearch->clear();
}

void DBSearch::searchMANGA(){
    textSearch->clear();
    table->viewItems();
    table->addListItems(listItems->allManga());
    table->verticalHeader()->hide();
    table->show();
}


void DBSearch::searchANIME(){
    textSearch->clear();
    table->viewItems();
    table->addListItems(listItems->allAnime());
    table->verticalHeader()->hide();
    table->show();
}

void DBSearch::doubleclick(int x){
    if(table->horizontalHeaderItem(0)->text()=="Username" && user->AlterUsers()){
        User* modifyUser=listUsers->getUser((table->item(x,0))->text());
        info_user=new UserSettings(user,modifyUser);
        emit close_mainwindow();
        connect(info_user,SIGNAL(finished(int)),this,SIGNAL(close_mainwindow()));
        info_user->setModLayout();
        info_user->show();
        emit savechanges_User(info_user);
    }
    if(table->horizontalHeaderItem(0)->text()=="Cod." && user->AlterItems()){
        Item* modifyItem=listItems->getItem((table->item(x,0))->text().toInt());
        info_item=new ItemSettings(user,modifyItem);
        emit close_mainwindow();
        connect(info_item,SIGNAL(finished(int)),this,SIGNAL(close_mainwindow()));
        info_item->setModLayout();
        info_item->show();
        emit savechanges_Item(info_item);
    }
    else if(table->horizontalHeaderItem(0)->text()=="Cod."){
        Item* item=listItems->getItem((table->item(x,0))->text().toInt());
        view_item = new ViewItem(user,item);
        emit close_mainwindow();
        connect(view_item,SIGNAL(finished(int)),this,SIGNAL(close_mainwindow()));
        view_item->addLayout();
        view_item->show();
        emit savechanges_Status(view_item);
    }
}

