#include "item_controller.h"

Item_Controller::Item_Controller(ItemDatabase* dbItem, QObject* parent):  QObject(parent), allItems(dbItem){}

void Item_Controller::updateItemView(ItemSettings* itemview){
    viewItems=itemview;

    //Manga Base
    connect(viewItems,SIGNAL(sendInsertMB(Item*,User*, QString, QString, QString, QString, QString, QString, QString,
                                          QString, QString, QString, QString)),this,SLOT(getChangesMB(Item*,User*,QString,
                                                                                                      QString, QString, QString, QString, QString, QString, QString, QString, QString, QString)));

    //Manga Deluxe
    connect(viewItems,SIGNAL(sendInsertMD(Item*,User*, QString, QString, QString, QString, QString, QString, QString,
                                          QString, QString, QString, bool, bool, bool, bool)),this,SLOT(getChangesMD(Item*,User*,
                                                                                                                     QString, QString, QString, QString, QString, QString, QString, QString, QString, QString,
                                                                                                                     bool, bool, bool, bool)));

    //Anime Serie
    connect(viewItems,SIGNAL(sendInsertAS(Item*, User*, QString, QString, QString, QString, QString, QString, QString,
                                          QString, QString, QString, QString, QString, QString)),this,SLOT(getChangesAS(Item*,
                                                                                                                        User*, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString,
                                                                                                                        QString, QString)));

    //Anime Film
    connect(viewItems,SIGNAL(sendInsertAF(Item*, User*, QString, QString, QString, QString, QString, QString, QString,
                                          QString, QString, QString, QString, bool)),this,SLOT(getChangesAF(Item*, User*, QString, QString,
                                                                                                            QString, QString, QString, QString, QString, QString, QString, QString, QString, bool)));

    connect(viewItems,SIGNAL(sendDeleteItem(Item*)),this,SLOT(getDelete(Item*)));
    connect(viewItems,SIGNAL(sendNewItem(Item*)),this,SLOT(getNewItem(Item*)));
}

bool Item_Controller::checkCommonFields(Item* item, QString orig_name, QString engl_name, QString aut,
                                        QString rel_d, QString st, QString gen, QString rat, bool modif){
    if(orig_name != "" && orig_name != item->getOriginalName()){
        item->setOriginalName(orig_name); modif=true; }

    if(engl_name != "" && engl_name != item->getEnglishName()){
        item->setEnglishName(engl_name); modif=true; }

    if(aut != "" && aut != item->getAuthor()){
        item->setAuthor(aut); modif=true; }

    if(rel_d != "" && rel_d != item->getReleaseDate().toString("dd/MM/yyyy")){
        QDate dt = QDate::fromString(rel_d,"dd/MM/yyyy");
        item->setReleaseDate(dt); modif=true; }

    if(st != "" && st != item->getState()){
        item->setState(st); modif=true; }

    if(gen != "" && gen != item->getGenre()){
        item->setGenre(gen); modif=true; }

    if(rat != "" && rat != item->getRating()){
        item->setRating(rat); modif=true; }

    return modif;
}

void Item_Controller::getChangesMB(Item* item, User* user, QString orig_name, QString engl_name, QString aut, QString rel_d,
                                   QString st, QString gen, QString rat,QString deal, QString cap,
                                   QString vol, QString rep){
    if(user->AlterItems()){ //Se l'utente può modificare l'articolo
        bool modif=false;

        modif = checkCommonFields(item, orig_name, engl_name, aut, rel_d, st, gen, rat, modif);

        if(deal != "" && deal != (dynamic_cast<Base*>(item))->getDealer()){
            (dynamic_cast<Base*>(item))->setDealer(deal); modif=true; }
        if(cap != "" && cap != QString::number((dynamic_cast<Base*>(item))->getChapters()) ){
            (dynamic_cast<Base*>(item))->setChapters(cap.toInt()); modif=true; }
        if(vol != "" && vol != QString::number((dynamic_cast<Base*>(item))->getVolumes())){
            (dynamic_cast<Base*>(item))->setVolumes(vol.toInt()); modif=true; }
        if(rep != "" && rep != QString::number((dynamic_cast<Base*>(item))->getReprint())){
            (dynamic_cast<Base*>(item))->setReprint(rep.toInt()); modif=true; }

        if(modif){
            QMessageBox::information(0,"Modifiche campi dati","Modifiche avvenute con successo!");
            allItems->SaveAndClose();
            viewItems->close();
        }
    }
}

void Item_Controller::getChangesMD(Item* item, User* user, QString orig_name, QString engl_name, QString aut, QString rel_d,
                                   QString st, QString gen, QString rat,QString deal, QString cap,
                                   QString vol, bool vc, bool post, bool actfig, bool adh){
    if(user->AlterItems()){ //Se l'utente può modificare l'articolo
        bool modif=false;

        modif = checkCommonFields(item, orig_name, engl_name, aut, rel_d, st, gen, rat, modif);

        if(deal != "" && deal != (dynamic_cast<Deluxe*>(item))->getDealer()){
            (dynamic_cast<Deluxe*>(item))->setDealer(deal); modif=true; }
        if(cap != "" && cap != QString::number((dynamic_cast<Deluxe*>(item))->getChapters()) ){
            (dynamic_cast<Deluxe*>(item))->setChapters(cap.toInt()); modif=true; }
        if(vol != "" && vol != QString::number((dynamic_cast<Deluxe*>(item))->getVolumes())){
            (dynamic_cast<Deluxe*>(item))->setVolumes(vol.toInt()); modif=true; }
        if(vc != (dynamic_cast<Deluxe*>(item))->getVariantCover()){
            (dynamic_cast<Deluxe*>(item))->setVariantCover(vc); modif=true; }
        if(post != (dynamic_cast<Deluxe*>(item))->getPoster()){
            (dynamic_cast<Deluxe*>(item))->setPoster(post); modif=true; }
        if(actfig != (dynamic_cast<Deluxe*>(item))->getActionFigure()){
            (dynamic_cast<Deluxe*>(item))->setActionFigure(actfig); modif=true; }
        if(adh != (dynamic_cast<Deluxe*>(item))->getAdhesives()){
            (dynamic_cast<Deluxe*>(item))->setAdhesives(adh); modif=true; }

        if(modif){
            QMessageBox::information(0,"Modifiche campi dati","Modifiche avvenute con successo!");
            allItems->SaveAndClose();
            viewItems->close();
        }
    }
}

void Item_Controller::getChangesAS(Item* item, User* user, QString orig_name, QString engl_name, QString aut, QString rel_d,
                                   QString st, QString gen, QString rat, QString prod, QString stud, QString sour,
                                   QString dur, QString ep, QString seas){
    if(user->AlterItems()){ //Se l'utente può modificare l'articolo
        bool modif=false;

        modif = checkCommonFields(item, orig_name, engl_name, aut, rel_d, st, gen, rat, modif);

        if(prod != "" && prod != (dynamic_cast<Serie*>(item))->getProducer()){
            (dynamic_cast<Serie*>(item))->setProducer(prod); modif=true; }
        if(stud != "" && stud != (dynamic_cast<Serie*>(item))->getStudio()){
            (dynamic_cast<Serie*>(item))->setStudio(stud); modif=true; }
        if(sour != "" && sour != (dynamic_cast<Serie*>(item))->getSource()){
            (dynamic_cast<Serie*>(item))->setSource(sour); modif=true; }
        if(dur != "" && dur != QString::number((dynamic_cast<Serie*>(item))->getDuration())){
            (dynamic_cast<Serie*>(item))->setDuration(dur.toInt()); modif=true; }
        if(ep != "" && ep != QString::number((dynamic_cast<Serie*>(item))->getEpisodes())){
            (dynamic_cast<Serie*>(item))->setEpisodes(ep.toInt()); modif=true; }
        if(seas != "" && seas != QString::number((dynamic_cast<Serie*>(item))->getSeasons())){
            (dynamic_cast<Serie*>(item))->setSeasons(seas.toInt()); modif=true; }

        if(modif){
            QMessageBox::information(0,"Modifiche campi dati","Modifiche avvenute con successo!");
            allItems->SaveAndClose();
            viewItems->close();
        }
    }
}

void Item_Controller::getChangesAF(Item* item, User* user, QString orig_name, QString engl_name, QString aut, QString rel_d,
                                   QString st, QString gen, QString rat, QString prod, QString stud, QString sour,
                                   QString dur, bool saqt){
    if(user->AlterItems()){ //Se l'utente può modificare l'articolo
        bool modif=false;

        modif = checkCommonFields(item, orig_name, engl_name, aut, rel_d, st, gen, rat, modif);

        if(prod != "" && prod != (dynamic_cast<Film*>(item))->getProducer()){
            (dynamic_cast<Film*>(item))->setProducer(prod); modif=true; }
        if(stud != "" && stud != (dynamic_cast<Film*>(item))->getStudio()){
            (dynamic_cast<Film*>(item))->setStudio(stud); modif=true; }
        if(sour != "" && sour != (dynamic_cast<Film*>(item))->getSource()){
            (dynamic_cast<Film*>(item))->setSource(sour); modif=true; }
        if(dur != "" && dur != QString::number((dynamic_cast<Film*>(item))->getDuration())){
            (dynamic_cast<Film*>(item))->setDuration(dur.toInt()); modif=true; }
        if(saqt != (dynamic_cast<Film*>(item))->getSceneAfterQueueTitles()){
            (dynamic_cast<Film*>(item))->setSceneAfterQueueTitles(saqt); modif=true; }

        if(modif){
            QMessageBox::information(0,"Modifiche campi dati","Modifiche avvenute con successo!");
            allItems->SaveAndClose();
            viewItems->close();
        }
    }
}

void Item_Controller::getDelete(Item *item){
    viewItems->close();
    allItems->removeItemFromDB(item);
    allItems->SaveAndClose();
    QMessageBox::warning(0,"Eliminazione articolo","Articolo eliminato con successo!");
}

void Item_Controller::getNewItem(Item *item){
    allItems->addItemToDB(item);
    viewItems->close();
    allItems->SaveAndClose();
    QMessageBox::information(0,"Inserimento articolo", "Inserimento avvenuto con successo!");

}
