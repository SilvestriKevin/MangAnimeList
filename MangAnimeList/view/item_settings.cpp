#include "item_settings.h"

ItemSettings::ItemSettings(User *u, Item *it): user(u), editedItem(it){
    this->setAttribute(Qt::WA_DeleteOnClose);
    setWindowTitle("Informazioni Articolo");
    addLayout();
    move(500,150);
    setFixedWidth(300);
}

void ItemSettings::addLayout(){
    /*  CAMPI COMUNI PER OGNI ARTICOLO */
    labelOriginalName=new QLabel("Nome Originale");
    labelEnglishName=new QLabel("Nome Inglese");
    labelAuthor=new QLabel("Autore");
    labelReleaseDate=new QLabel("Data Pubblicazione");
    labelState=new QLabel("Stato");
    labelGenre=new QLabel("Categoria");
    labelRating=new QLabel("Classificazione");

    editOriginalName=new QLineEdit();
    editOriginalName->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9\\s]{1,25}")));
    editOriginalName->setPlaceholderText("Inserisci nome originale");

    editEnglishName=new QLineEdit();
    editEnglishName->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9\\s]{1,25}")));
    editEnglishName->setPlaceholderText("Inserisci nome inglese");

    editAuthor=new QLineEdit();
    editAuthor->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9\\s]{1,25}")));
    editAuthor->setPlaceholderText("Inserisci autore");

    editReleaseDate= new QDateEdit(QDate::currentDate());
    editReleaseDate->setDisplayFormat("dd/MM/yyyy");

    editState = new QComboBox();
    editState->addItem("Terminato");
    editState->addItem("In corso");
    editState->addItem("Non ancora uscito");

    editGenre = new QComboBox();
    editGenre->addItem("Arti Marziali");
    editGenre->addItem("Avventura");
    editGenre->addItem("Azione");
    editGenre->addItem("Bambini");
    editGenre->addItem("Combattimento");
    editGenre->addItem("Commedia");
    editGenre->addItem("Crimine");
    editGenre->addItem("Cucina");
    editGenre->addItem("Demenziale");
    editGenre->addItem("Demoni");
    editGenre->addItem("Erotico");
    editGenre->addItem("Fantascienza");
    editGenre->addItem("Fantasy");
    editGenre->addItem("Fiaba");
    editGenre->addItem("Gang Giovanili");
    editGenre->addItem("Giallo");
    editGenre->addItem("Gioco");
    editGenre->addItem("Guerra");
    editGenre->addItem("Hentai");
    editGenre->addItem("Horror");
    editGenre->addItem("Magia");
    editGenre->addItem("Mecha");
    editGenre->addItem("Mistero");
    editGenre->addItem("Musica");
    editGenre->addItem("Parodia");
    editGenre->addItem("Politico");
    editGenre->addItem("Poliziesco");
    editGenre->addItem("Psicologico");
    editGenre->addItem("Scolastico");
    editGenre->addItem("Sentimentale");
    editGenre->addItem("Sketch Comedy");
    editGenre->addItem("Soprannaturale");
    editGenre->addItem("Sperimentale");
    editGenre->addItem("Splatter");
    editGenre->addItem("Sport");
    editGenre->addItem("Storico");
    editGenre->addItem("Supereroi");
    editGenre->addItem("Superpoteri");
    editGenre->addItem("Thriller");
    editGenre->addItem("Visual Novel");
    editGenre->addItem("Western");
    editGenre->addItem("Umorismo");
    editGenre->addItem("Violenza");

    editRating = new QComboBox();
    editRating->addItem("12+");
    editRating->addItem("15+");
    editRating->addItem("18+");
    editRating->addItem("Per tutti");

    /* SCELTA CATEGORIA E SOTTOCATEGORIA */
    labelItemType = new QLabel("Tipologia articolo:");

    MB = new QRadioButton("Manga Base", this);
    MD = new QRadioButton("Manga Deluxe", this);
    AS = new QRadioButton("Anime Serie", this);
    AF = new QRadioButton("Anime Film", this);


    /* MANGA GENERICO */
    labelDealer = new QLabel("Distributore");
    labelChapters = new QLabel("Capitoli");
    labelVolumes = new QLabel("Volumi");

    editDealer=new QLineEdit();
    editDealer->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9\\s]{1,25}")));
    editDealer->setPlaceholderText("Inserisci distributore");

    editChapters=new QLineEdit();
    editChapters->setValidator(new QRegExpValidator(QRegExp("[0-9]{1,3}")));
    editChapters->setPlaceholderText("Inserisci capitoli");

    editVolumes=new QLineEdit();
    editVolumes->setValidator(new QRegExpValidator(QRegExp("[0-9]{1,2}")));
    editVolumes->setPlaceholderText("Inserisci volumi");

    /* MANGA BASE */
    labelReprint = new QLabel("Ristampa");

    editReprint= new QLineEdit();
    editReprint->setValidator(new QRegExpValidator(QRegExp("[0-9]")));
    editReprint->setPlaceholderText("Inserisci ristampa");

    /* MANGA DELUXE */
    editVariantCover = new QCheckBox(tr("Variant Cover"));
    editPoster = new QCheckBox(tr("Poster"));
    editActionFigure = new QCheckBox(tr("Action Figure"));
    editAdhesives = new QCheckBox(tr("Adesivi"));

    /* ANIME GENERICO */
    labelProducer = new QLabel("Produttore");
    labelStudio = new QLabel("Studio");
    labelSource = new QLabel("Origine");
    labelDuration = new QLabel("Durata (min)");

    editProducer=new QLineEdit();
    editProducer->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9\\s]{1,25}")));
    editProducer->setPlaceholderText("Inserisci produttore");

    editStudio=new QLineEdit();
    editStudio->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9\\s]{1,25}")));
    editStudio->setPlaceholderText("Inserisci studio");

    editSource = new QComboBox();
    editSource->addItem("Manga");
    editSource->addItem("Videogioco");
    editSource->addItem("Film");
    editSource->addItem("Nessuna");

    editDuration=new QLineEdit();
    editDuration->setValidator(new QRegExpValidator(QRegExp("[0-9]{1,3}")));
    editDuration->setPlaceholderText("Inserisci durata");

    /* ANIME SERIE */
    labelEpisodes= new QLabel("Episodi");
    labelSeasons = new QLabel("Stagioni");

    editEpisodes=new QLineEdit();
    editEpisodes->setValidator(new QRegExpValidator(QRegExp("[0-9]{1,3}")));
    editEpisodes->setPlaceholderText("Inserisci episodi");

    editSeasons=new QLineEdit();
    editSeasons->setValidator(new QRegExpValidator(QRegExp("[0-9]{1,2}")));
    editSeasons->setPlaceholderText("Inserisci stagioni");

    /* ANIME FILM */
    editSceneAfterQueueTitles = new QCheckBox(tr("Scena dopo i titoli di coda"));

    pushSaveChanges=new QPushButton("Salva le modifiche");
    pushDelete=new QPushButton("Elimina l'articolo");
    pushNew=new QPushButton("Crea nuovo articolo");

    gridItem=new QGridLayout;
    gridItem->addWidget(labelOriginalName,0,0);
    gridItem->addWidget(editOriginalName,0,1);
    gridItem->addWidget(labelEnglishName,1,0);
    gridItem->addWidget(editEnglishName,1,1);
    gridItem->addWidget(labelAuthor,2,0);
    gridItem->addWidget(editAuthor,2,1);
    gridItem->addWidget(labelReleaseDate,3,0);
    gridItem->addWidget(editReleaseDate,3,1);
    gridItem->addWidget(labelState,4,0);
    gridItem->addWidget(editState,4,1);
    gridItem->addWidget(labelGenre,5,0);
    gridItem->addWidget(editGenre,5,1);
    gridItem->addWidget(labelRating,6,0);
    gridItem->addWidget(editRating,6,1);
    gridItem->addWidget(labelItemType,7,0);
    gridItem->addWidget(MB,8,0);
    gridItem->addWidget(MD,9,0);
    gridItem->addWidget(AS,10,0);
    gridItem->addWidget(AF,11,0);

    layoutItemSettings=new QVBoxLayout();
    layoutItemSettings->addLayout(gridItem);

    connect(MB,SIGNAL(toggled(bool)),this,SLOT(viewTypeMB(bool)));
    connect(MD, SIGNAL(toggled(bool)),this,SLOT(viewTypeMD(bool)));
    connect(AS,SIGNAL(toggled(bool)),this,SLOT(viewTypeAS(bool)));
    connect(AF,SIGNAL(toggled(bool)),this,SLOT(viewTypeAF(bool)));

    connect(pushSaveChanges,SIGNAL(clicked()),this,SLOT(saveItem()));
    connect(pushDelete,SIGNAL(clicked()),this,SLOT(saveDELETE()));
    connect(pushNew,SIGNAL(clicked(bool)),this,SLOT(saveNEWITEM()));
    setLayout(layoutItemSettings);
}

void ItemSettings::showSaveDeleteNew(){
    gridItem->addWidget(pushSaveChanges);
    gridItem->addWidget(pushDelete);
    gridItem->addWidget(pushNew);
}

void ItemSettings::hideManga(){
    labelDealer->hide(); editDealer->hide();
    labelChapters->hide(); editChapters->hide();
    labelVolumes->hide(); editVolumes->hide();
}

void ItemSettings::hideMB(){
    labelReprint->hide(); editReprint->hide();
}

void ItemSettings::hideMD(){
    editVariantCover->hide();
    editPoster->hide();
    editActionFigure->hide();
    editAdhesives->hide();
}

void ItemSettings::hideAnime(){
    labelProducer->hide();
    editProducer->hide();
    labelStudio->hide();
    editStudio->hide();
    labelSource->hide();
    editSource->hide();
    labelDuration->hide();
    editDuration->hide();
}

void ItemSettings::hideAS(){
    labelEpisodes->hide();
    editEpisodes->hide();
    labelSeasons->hide();
    editSeasons->hide();
}

void ItemSettings::hideAF(){
    editSceneAfterQueueTitles->hide();
}

void ItemSettings::hideALL(){
    hideManga();
    hideMB();
    hideMD();
    hideAnime();
    hideAS();
    hideAF();
}

void ItemSettings::gridWidMB(){
    gridItem->addWidget(labelDealer,12,0);
    gridItem->addWidget(editDealer,12,1);
    gridItem->addWidget(labelChapters,13,0);
    gridItem->addWidget(editChapters,13,1);
    gridItem->addWidget(labelVolumes,14,0);
    gridItem->addWidget(editVolumes,14,1);

    gridItem->addWidget(labelReprint,15,0);
    gridItem->addWidget(editReprint,15,1);
    showSaveDeleteNew();
}

void ItemSettings::viewTypeMB(bool mb){
    if(mb){
        gridWidMB();
        //SHOW MANGA
        labelDealer->show(); editDealer->show();
        labelChapters->show(); editChapters->show();
        labelVolumes->show(); editVolumes->show();
        //SHOW MB
        labelReprint->show(); editReprint->show();
        hideMD();
        hideAnime();
        hideAS();
        hideAF();
    }
    else hideALL();
}

void ItemSettings::gridWidMD(){
    gridItem->addWidget(labelDealer,12,0);
    gridItem->addWidget(editDealer,12,1);
    gridItem->addWidget(labelChapters,13,0);
    gridItem->addWidget(editChapters,13,1);
    gridItem->addWidget(labelVolumes,14,0);
    gridItem->addWidget(editVolumes,14,1);

    gridItem->addWidget(editVariantCover,15,0);
    gridItem->addWidget(editPoster,16,0);
    gridItem->addWidget(editActionFigure,17,0);
    gridItem->addWidget(editAdhesives,18,0);
    showSaveDeleteNew();
}

void ItemSettings::viewTypeMD(bool md){
    if(md){
        gridWidMD();
        //SHOW MANGA
        labelDealer->show(); editDealer->show();
        labelChapters->show(); editChapters->show();
        labelVolumes->show(); editVolumes->show();
        hideMB();
        //SHOW MD
        editVariantCover->show();
        editPoster->show();
        editActionFigure->show();
        editAdhesives->show();
        hideAnime();
        hideAS();
        hideAF();
    }
    else hideALL();

}

void ItemSettings::gridWidAS(){
    gridItem->addWidget(labelProducer,12,0);
    gridItem->addWidget(editProducer,12,1);
    gridItem->addWidget(labelStudio,13,0);
    gridItem->addWidget(editStudio,13,1);
    gridItem->addWidget(labelSource,14,0);
    gridItem->addWidget(editSource,14,1);
    gridItem->addWidget(labelDuration,15,0);
    gridItem->addWidget(editDuration,15,1);

    gridItem->addWidget(labelEpisodes,16,0);
    gridItem->addWidget(editEpisodes,16,1);
    gridItem->addWidget(labelSeasons,17,0);
    gridItem->addWidget(editSeasons,17,1);
    showSaveDeleteNew();
}

void ItemSettings::viewTypeAS(bool as){
    if(as){
        gridWidAS();
        hideManga();
        hideMB();
        hideMD();
        //SHOW ANIME
        labelProducer->show();
        editProducer->show();
        labelStudio->show();
        editStudio->show();
        labelSource->show();
        editSource->show();
        labelDuration->show();
        editDuration->show();
        //SHOW AS
        labelEpisodes->show();
        editEpisodes->show();
        labelSeasons->show();
        editSeasons->show();
        hideAF();
    }
    else hideALL();
}

void ItemSettings::gridWidAF(){
    gridItem->addWidget(labelProducer,12,0);
    gridItem->addWidget(editProducer,12,1);
    gridItem->addWidget(labelStudio,13,0);
    gridItem->addWidget(editStudio,13,1);
    gridItem->addWidget(labelSource,14,0);
    gridItem->addWidget(editSource,14,1);
    gridItem->addWidget(labelDuration,15,0);
    gridItem->addWidget(editDuration,15,1);

    gridItem->addWidget(editSceneAfterQueueTitles,16,0);
    showSaveDeleteNew();
}

void ItemSettings::viewTypeAF(bool af){
    if(af){
        gridWidAF();
        hideManga();
        hideMB();
        hideMD();
        //SHOW ANIME
        labelProducer->show();
        editProducer->show();
        labelStudio->show();
        editStudio->show();
        labelSource->show();
        editSource->show();
        labelDuration->show();
        editDuration->show();
        hideAS();
        //SHOW AF
        editSceneAfterQueueTitles->show();
    }
    else hideALL();
}


void ItemSettings::closeWindow(){
    if(isEnabled())
        this->setEnabled(0);
    else
        this->setEnabled(1);
}

void ItemSettings::setNewLayout(){
    pushSaveChanges->hide();
    pushDelete->hide();

}

void ItemSettings::setModLayout(){
    if(editedItem){
        editOriginalName->setText(editedItem->getOriginalName());
        editEnglishName->setText(editedItem->getEnglishName());
        editAuthor->setText(editedItem->getAuthor());
        editReleaseDate->setDate(editedItem->getReleaseDate());

        int indexState = editState->findText(editedItem->getState());
        editState->setCurrentIndex(indexState);
        editState->itemText(indexState);

        int indexGenre = editGenre->findText(editedItem->getGenre());
        editGenre->setCurrentIndex(indexGenre);
        editGenre->itemText(indexGenre);

        int indexRating = editRating->findText(editedItem->getRating());
        editRating->setCurrentIndex(indexRating);
        editRating->itemText(indexRating);

        labelItemType->hide();

        if(editedItem->getTypeItem() =="Manga - Base"){
            MB->hide(); MD->hide(); AS->hide(); AF->hide();
            gridWidMB();

            editDealer->setText(dynamic_cast<Base*>(editedItem)->getDealer());
            editChapters->setText(QString::number(dynamic_cast<Base*>(editedItem)->getChapters()));
            editVolumes->setText(QString::number(dynamic_cast<Base*>(editedItem)->getVolumes()));
            editReprint->setText(QString::number(dynamic_cast<Base*>(editedItem)->getReprint()));

        }

        if(editedItem->getTypeItem() =="Manga - Deluxe"){
            MB->hide(); MD->hide(); AS->hide(); AF->hide();
            gridWidMD();

            editDealer->setText(dynamic_cast<Deluxe*>(editedItem)->getDealer());
            editChapters->setText(QString::number(dynamic_cast<Deluxe*>(editedItem)->getChapters()));
            editVolumes->setText(QString::number(dynamic_cast<Deluxe*>(editedItem)->getVolumes()));

            editVariantCover->setChecked(dynamic_cast<Deluxe*>(editedItem)->getVariantCover());
            editPoster->setChecked(dynamic_cast<Deluxe*>(editedItem)->getPoster());
            editActionFigure->setChecked(dynamic_cast<Deluxe*>(editedItem)->getActionFigure());
            editAdhesives->setChecked(dynamic_cast<Deluxe*>(editedItem)->getAdhesives());

        }

        if(editedItem->getTypeItem() =="Anime - Serie"){
            MB->hide(); MD->hide(); AS->hide(); AF->hide();
            gridWidAS();

            editProducer->setText(dynamic_cast<Serie*>(editedItem)->getProducer());
            editStudio->setText(dynamic_cast<Serie*>(editedItem)->getStudio());
            int indexSource = editSource->findText(dynamic_cast<Serie*>(editedItem)->getSource());
            editSource->setCurrentIndex(indexSource);
            editSource->itemText(indexSource);
            editDuration->setText(QString::number(dynamic_cast<Serie*>(editedItem)->getDuration()));

            editEpisodes->setText(QString::number(dynamic_cast<Serie*>(editedItem)->getEpisodes()));
            editSeasons->setText(QString::number(dynamic_cast<Serie*>(editedItem)->getSeasons()));

        }

        if(editedItem->getTypeItem() =="Anime - Film"){
            MB->hide(); MD->hide(); AS->hide(); AF->hide();
            gridWidAF();

            editProducer->setText(dynamic_cast<Film*>(editedItem)->getProducer());
            editStudio->setText(dynamic_cast<Film*>(editedItem)->getStudio());
            int indexSource = editSource->findText(dynamic_cast<Film*>(editedItem)->getSource());
            editSource->setCurrentIndex(indexSource);
            editSource->itemText(indexSource);
            editDuration->setText(QString::number(dynamic_cast<Film*>(editedItem)->getDuration()));

            editSceneAfterQueueTitles->setChecked(dynamic_cast<Film*>(editedItem)->getSceneAfterQueueTitles());

        }
    }

    pushNew->hide();
}

void ItemSettings::saveItem(){
    if(editOriginalName->text()=="" && editEnglishName->text()=="")
        QMessageBox::warning(0,"Attenzione","E' necessario inserire almeno un nome dell'articolo");
    if(editAuthor->text()=="")
        QMessageBox::warning(0,"Attenzione","E' necessario inserire l'autore dell'articolo");
    if(editState->currentText()=="")
        QMessageBox::warning(0,"Attenzione","E' necessario inserire lo stato dell'articolo");
    if(editGenre->currentText()=="")
        QMessageBox::warning(0,"Attenzione","E' necessario inserire la categoria dell'articolo");
    if(editRating->currentText()=="")
        QMessageBox::warning(0,"Attenzione","E' necessario inserire la classificazione dell'articolo");
    else{
        if(editedItem->getTypeItem() == "Manga - Base"){
            if(editChapters->text()=="" && editVolumes->text()=="")
                QMessageBox::warning(0,"Attenzione","E' necessario inserire il numero di capitoli o di volumi del manga");
            if(editReprint->text()=="")
                QMessageBox::warning(0,"Attenzione","E' necessario inserire il numero di ristampa del manga");

            else emit sendInsertMB(editedItem,user,editOriginalName->text(),editEnglishName->text(),editAuthor->text(),
                                   editReleaseDate->text(),editState->currentText(),editGenre->currentText(),
                                   editRating->currentText(),editDealer->text(),editChapters->text(),editVolumes->text(),
                                   editReprint->text());
        }

        if(editedItem->getTypeItem() == "Manga - Deluxe"){
            if(editChapters->text()=="" && editVolumes->text()=="")
                QMessageBox::warning(0,"Attenzione","E' necessario inserire almeno il numero di capitoli o di volumi del manga");
            if(editVariantCover->isChecked()==false && editPoster->isChecked()==false && editActionFigure->isChecked()==false && editAdhesives->isChecked()==false){
                QMessageBox::warning(0,"Attenzione","E' necessario inserire almeno un contenuto extra. Se quest'ultimo non esiste, inserire un Manga Base");}

            else emit sendInsertMD(editedItem,user,editOriginalName->text(),editEnglishName->text(),editAuthor->text(),
                                   editReleaseDate->text(),editState->currentText(),editGenre->currentText(),
                                   editRating->currentText(),editDealer->text(),editChapters->text(),editVolumes->text(),
                                   editVariantCover->isChecked(),editPoster->isChecked(),editActionFigure->isChecked(),
                                   editAdhesives->isChecked());
        }

        if(editedItem->getTypeItem() == "Anime - Serie"){
            if(editDuration->text()=="")
                QMessageBox::warning(0,"Attenzione","E' necessario inserire la durata dell'episodio dell'anime");
            if(editEpisodes->text()=="" && editSeasons->text()=="")
                QMessageBox::warning(0,"Attenzione","E' necessario inserire almeno il numero di episodi o di stagioni della serie");

            else emit sendInsertAS(editedItem,user,editOriginalName->text(),editEnglishName->text(),editAuthor->text(),
                                   editReleaseDate->text(),editState->currentText(),editGenre->currentText(),
                                   editRating->currentText(),editProducer->text(),editStudio->text(),editSource->currentText(),
                                   editDuration->text(),editEpisodes->text(),editSeasons->text());
        }

        if(editedItem->getTypeItem() == "Anime - Film"){
            if(editDuration->text()=="")
                QMessageBox::warning(0,"Attenzione","E' necessario inserire la durata dell'episodio dell'anime");

            else emit sendInsertAF(editedItem,user,editOriginalName->text(),editEnglishName->text(),editAuthor->text(),
                                   editReleaseDate->text(),editState->currentText(),editGenre->currentText(),
                                   editRating->currentText(),editProducer->text(),editStudio->text(),editSource->currentText(),
                                   editDuration->text(),editSceneAfterQueueTitles->isChecked());}
    }
}


void ItemSettings::saveDELETE(){
    emit(sendDeleteItem(editedItem));
}

void ItemSettings::saveNEWITEM(){
    Item* p=nullptr;
    if((editOriginalName->text() !="" || editEnglishName->text() !="") && editAuthor->text() !="" &&
            editReleaseDate->text() !="" && editState->currentText() !="" && editGenre->currentText() !="" && editRating->currentText() !="" ){
        if(MB->isChecked()){
            if((editChapters->text()!="" || editVolumes->text()!="") && editReprint->text() !=""){
                p= new Base(editOriginalName->text(),editEnglishName->text(),editAuthor->text(),
                            editReleaseDate->date(),editState->currentText(),editGenre->currentText(),
                            editRating->currentText(),editDealer->text(),editChapters->text().toInt(),
                            editVolumes->text().toInt(),editReprint->text().toInt());
                emit sendNewItem(p);
            }
            else QMessageBox::warning(0,"Errore di inserimento","Campi mancanti");
        }

        else if(MD->isChecked()){
            if((editChapters->text()!="" || editVolumes->text()!="") && (editVariantCover->isChecked()==true || editPoster->isChecked()==true || editActionFigure->isChecked()==true ||
                     editAdhesives->isChecked()==true)){
                p = new Deluxe(editOriginalName->text(),editEnglishName->text(),editAuthor->text(),
                               editReleaseDate->date(),editState->currentText(),editGenre->currentText(),
                               editRating->currentText(),editDealer->text(),editChapters->text().toInt(),
                               editVolumes->text().toInt(),editVariantCover->isChecked(),editPoster->isChecked(),
                               editActionFigure->isChecked(),editAdhesives->isChecked());
                emit sendNewItem(p);
            }
            else QMessageBox::warning(0,"Errore di inserimento","Campi mancanti");
        }

        else if(AS->isChecked()){
            if(editDuration->text() !="" && (editEpisodes->text() !="" || editSeasons->text() !="" )){
                p = new Serie(editOriginalName->text(),editEnglishName->text(),editAuthor->text(),
                              editReleaseDate->date(),editState->currentText(),editGenre->currentText(),
                              editRating->currentText(),editProducer->text(),editStudio->text(),editSource->currentText(),
                              editDuration->text().toInt(),editSceneAfterQueueTitles->isChecked());
                emit sendNewItem(p);
            }
            else QMessageBox::warning(0,"Errore di inserimento","Campi mancanti");
        }

        else if(AF->isChecked()){
            if(editDuration->text() !=""){
                p = new Film(editOriginalName->text(),editEnglishName->text(),editAuthor->text(),
                             editReleaseDate->date(),editState->currentText(),editGenre->currentText(),
                             editRating->currentText(),editProducer->text(),editStudio->text(),editSource->currentText(),
                             editDuration->text().toInt(),editSceneAfterQueueTitles->isChecked());
                emit sendNewItem(p);
            }
            else QMessageBox::warning(0,"Errore di inserimento","Campi mancanti");
        }
    }
    else
        QMessageBox::warning(0,"Errore","Campi vuoti! Inserisci i dati e riprova");

}
