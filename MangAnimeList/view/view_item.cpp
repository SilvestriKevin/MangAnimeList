#include "view_item.h"

ViewItem::ViewItem(User *us,Item *it): user(us), item(it){
    this->setAttribute(Qt::WA_DeleteOnClose);
    setWindowTitle("Visualizza Articolo");
    addLayout();
}

void ViewItem::commonLabels(){
    labelOriginalName = new QLabel("Nome Originale:");
    labelEnglishName = new QLabel("Nome Inglese:");
    labelAuthor = new QLabel("Autore:");
    labelReleaseDate = new QLabel("Data Pubblicazione:");
    labelState = new QLabel("Stato:");
    labelGenre = new QLabel("Categoria:");
    labelRating = new QLabel("Classificazione:");
    originalName = new QLabel(item->getOriginalName());
    englishName = new QLabel(item->getEnglishName());
    author = new QLabel(item->getAuthor());
    releaseDate = new QLabel(item->getReleaseDate().toString("dd/MM/yyyy"));
    state = new QLabel(item->getState());
    genre = new QLabel(item->getGenre());
    rating = new QLabel(item->getRating());
    labelItemType = new QLabel("Tipo:");
    ItemType = new QLabel(item->getTypeItem());
    labelStatus = new QLabel("Status:");
    statusFor = new QComboBox();
    statusFor->addItem("Nessuno");
    saveStatus = new QPushButton("Salva");
}

void ViewItem::commonLabelsManga(){
    labelDealer = new QLabel("Distributore:");
    labelChapters = new QLabel("Capitoli:");
    labelVolumes = new QLabel("Volumi:");
    statusFor->addItem("Letto");
    statusFor->addItem("Sto_leggendo");
    statusFor->addItem("Da_leggere");
}

void ViewItem::commonLabelsAnime(){
    labelProducer = new QLabel("Produttore:");
    labelStudio = new QLabel("Studio:");
    labelSource = new QLabel("Origine:");
    labelDuration = new QLabel("Durata (min):");
    statusFor->addItem("Visto");
    statusFor->addItem("Sto_vedendo");
    statusFor->addItem("Da_vedere");
}

void ViewItem::commonLayoutManga()const {
    gridItemLabel->addWidget(labelDealer,8,0);
    gridItemLabel->addWidget(labelChapters,9,0);
    gridItemLabel->addWidget(labelVolumes,10,0);

    gridItemLabel->addWidget(dealer,8,1);
    gridItemLabel->addWidget(chapters,9,1);
    gridItemLabel->addWidget(volumes,10,1);
}

void ViewItem::commonLayoutAnime() const{
    gridItemLabel->addWidget(labelProducer,8,0);
    gridItemLabel->addWidget(labelStudio,9,0);
    gridItemLabel->addWidget(labelSource,10,0);
    gridItemLabel->addWidget(labelDuration,11,0);

    gridItemLabel->addWidget(producer,8,1);
    gridItemLabel->addWidget(studio,9,1);
    gridItemLabel->addWidget(source,10,1);
    gridItemLabel->addWidget(duration,11,1);
}
void ViewItem::addLayout(){
    commonLabels();
    if(item->getTypeItem() == "Manga - Base"){
        commonLabelsManga();
        dealer = new QLabel(dynamic_cast<Base*>(item)->getDealer());
        chapters = new QLabel(QString::number(dynamic_cast<Base*>(item)->getChapters()));
        volumes = new QLabel(QString::number(dynamic_cast<Base*>(item)->getVolumes()));
        labelReprint = new QLabel("Ristampa:");
        reprint = new QLabel(QString::number(dynamic_cast<Base*>(item)->getReprint()));
    }

    if(item->getTypeItem() == "Manga - Deluxe"){
        commonLabelsManga();
        dealer = new QLabel(dynamic_cast<Deluxe*>(item)->getDealer());
        chapters = new QLabel(QString::number(dynamic_cast<Deluxe*>(item)->getChapters()));
        volumes = new QLabel(QString::number(dynamic_cast<Deluxe*>(item)->getVolumes()));

        labelVariantCover = new QLabel("Variant Cover:");
        if(dynamic_cast<Deluxe*>(item)->getVariantCover() == 1)
            variantCover = new QLabel("Si");
        else variantCover = new QLabel("No");

        labelPoster = new QLabel("Poster:");
        if(dynamic_cast<Deluxe*>(item)->getPoster() == 1)
            poster = new QLabel("Si");
        else poster = new QLabel("No");

        labelActionFigure = new QLabel("Action Figure:");
        if(dynamic_cast<Deluxe*>(item)->getActionFigure() == 1)
            actionFigure = new QLabel("Si");
        else actionFigure = new QLabel("No");

        labelAdhesives = new QLabel("Adesivi:");
        if(dynamic_cast<Deluxe*>(item)->getAdhesives() == 1)
            adhesives = new QLabel("Si");
        else adhesives = new QLabel("No");
    }

    if(item->getTypeItem() == "Anime - Serie"){
        commonLabelsAnime();
        producer = new QLabel(dynamic_cast<Serie*>(item)->getProducer());
        studio = new QLabel(dynamic_cast<Serie*>(item)->getStudio());
        source = new QLabel(dynamic_cast<Serie*>(item)->getSource());
        duration = new QLabel(QString::number(dynamic_cast<Serie*>(item)->getDuration()));
        labelEpisodes = new QLabel("Episodi:");
        episodes = new QLabel(QString::number(dynamic_cast<Serie*>(item)->getEpisodes()));
        labelSeasons = new QLabel("Stagioni:");
        seasons = new QLabel(QString::number(dynamic_cast<Serie*>(item)->getSeasons()));
    }

    if(item->getTypeItem() == "Anime - Film"){
        commonLabelsAnime();
        producer = new QLabel(dynamic_cast<Film*>(item)->getProducer());
        studio = new QLabel(dynamic_cast<Film*>(item)->getStudio());
        source = new QLabel(dynamic_cast<Film*>(item)->getSource());
        duration = new QLabel(QString::number(dynamic_cast<Film*>(item)->getDuration()));
        labelSceneAfterQueueTitles = new QLabel("Scena dopo i titoli di coda:");
        if(dynamic_cast<Film*>(item)->getSceneAfterQueueTitles() == 1)
            sceneAfterQueueTitles = new QLabel("Si");
        else sceneAfterQueueTitles = new QLabel("No");
    }

    gridItemLabel=new QGridLayout;
    gridItemLabel->addWidget(labelOriginalName,0,0);
    gridItemLabel->addWidget(originalName,0,1);
    gridItemLabel->addWidget(labelEnglishName,1,0);
    gridItemLabel->addWidget(englishName,1,1);
    gridItemLabel->addWidget(labelAuthor,2,0);
    gridItemLabel->addWidget(author,2,1);
    gridItemLabel->addWidget(labelReleaseDate,3,0);
    gridItemLabel->addWidget(releaseDate,3,1);
    gridItemLabel->addWidget(labelState,4,0);
    gridItemLabel->addWidget(state,4,1);
    gridItemLabel->addWidget(labelGenre,5,0);
    gridItemLabel->addWidget(genre,5,1);
    gridItemLabel->addWidget(labelRating,6,0);
    gridItemLabel->addWidget(rating,6,1);
    gridItemLabel->addWidget(labelItemType,7,0);
    gridItemLabel->addWidget(ItemType,7,1);

    if(item->getTypeItem() == "Manga - Base"){
        commonLayoutManga();
        gridItemLabel->addWidget(labelReprint, 11,0);
        gridItemLabel->addWidget(reprint,11,1);
        gridItemLabel->addWidget(labelStatus,12,0);
        gridItemLabel->addWidget(statusFor,12,1);
        gridItemLabel->addWidget(saveStatus,13,1);
    }
    if(item->getTypeItem() == "Manga - Deluxe"){
        commonLayoutManga();
        gridItemLabel->addWidget(labelVariantCover,11,0);
        gridItemLabel->addWidget(labelPoster,12,0);
        gridItemLabel->addWidget(labelActionFigure,13,0);
        gridItemLabel->addWidget(labelAdhesives,14,0);
        gridItemLabel->addWidget(variantCover,11,1);
        gridItemLabel->addWidget(poster,12,1);
        gridItemLabel->addWidget(actionFigure,13,1);
        gridItemLabel->addWidget(adhesives,14,1);
        gridItemLabel->addWidget(labelStatus,15,0);
        gridItemLabel->addWidget(statusFor,15,1);
        gridItemLabel->addWidget(saveStatus,16,1);
    }

    if(item->getTypeItem() == "Anime - Serie"){
        commonLayoutAnime();
        gridItemLabel->addWidget(labelEpisodes,12,0);
        gridItemLabel->addWidget(episodes,12,1);
        gridItemLabel->addWidget(labelSeasons,13,0);
        gridItemLabel->addWidget(seasons,13,1);
        gridItemLabel->addWidget(labelStatus,14,0);
        gridItemLabel->addWidget(statusFor,14,1);
        gridItemLabel->addWidget(saveStatus,15,1);
    }
    if(item->getTypeItem() == "Anime - Film"){
        commonLayoutAnime();
        gridItemLabel->addWidget(labelSceneAfterQueueTitles,12,0);
        gridItemLabel->addWidget(sceneAfterQueueTitles,12,1);
        gridItemLabel->addWidget(labelStatus,13,0);
        gridItemLabel->addWidget(statusFor,13,1);
        gridItemLabel->addWidget(saveStatus,14,1);
    }

    status = dynamic_cast<Standard_User*>(user)->getStatus(item->getCodeNumber());
    int indexStatus = statusFor->findText(status);
    statusFor->setCurrentIndex(indexStatus);
    statusFor->itemText(indexStatus);

    window = new QWidget(this);
    window->setLayout(gridItemLabel);
    window->show();

    connect(saveStatus,SIGNAL(clicked()),this,SLOT(saveListItem()));
}

void ViewItem::saveListItem(){
    emit sendInsertStatus(item,user,statusFor->currentText(),status);
}
