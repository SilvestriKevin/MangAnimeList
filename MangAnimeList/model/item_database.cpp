#include"item_database.h"

ItemDatabase::ItemDatabase(){ Load(); }

ItemDatabase::~ItemDatabase(){
    SaveAndClose();
    auto it=items.begin();
    for(; it!=items.end(); ++it){
        delete *it;
        it=items.erase(it);
        it--;
    }
}

void ItemDatabase::addItemToDB(Item* p){
    items.push_back(p);
}

void ItemDatabase::removeItemFromDB(Item* p){
    auto it=items.begin();
    for( ; it!=items.end(); ++it){
        if((*it)->getCodeNumber() == p->getCodeNumber()){
            delete *it;
            it=items.erase(it);
            it--;
        }
    }
}

Item* ItemDatabase::getItem(int codeNumber)const{
    Item* p = nullptr;
    auto it=items.begin();
    for( ;it!=items.end(); ++it){
        if((*it)->getCodeNumber() == codeNumber){
            p = *it;
        }
    }
    return p;
}

const QList<Item*> ItemDatabase::getAllItems()const{
    QList<Item*> temp;
    for(auto it=items.begin(); it!=items.end(); ++it){
        temp.push_back(*it);
    }
    return temp;
}

const QList<Item*> ItemDatabase::searchItems(const QString & word,const QString & type,const QString & state,const QString & category) const{
    QList<Item*> temp;
    bool result=false;
    if(type=="Articoli"){
        for(auto it=items.begin(); it!=items.end(); ++it){
            if( word=="" || ( word!="" && ( (*it)->getOriginalName().contains(word, Qt::CaseInsensitive) ||
                                            (*it)->getEnglishName().contains(word, Qt::CaseInsensitive) || (*it)->getAuthor().contains(word, Qt::CaseInsensitive) ) ) ){
                if((state!="Stato" && (*it)->getState().contains(state, Qt::CaseInsensitive)) || state=="Stato"){
                    if((category!="Categoria" && (*it)->getGenre().contains(category, Qt::CaseInsensitive)) || category=="Categoria"){
                        temp.push_back(*it);
                        result=true;
                    }
                }
            }
        }
    }
    else if(type=="Manga"){
        for(auto it=items.begin(); it!=items.end(); ++it){
            if( ( word=="" || ( word!="" && ( (*it)->getOriginalName().contains(word, Qt::CaseInsensitive) ||
                                              (*it)->getEnglishName().contains(word, Qt::CaseInsensitive) || (*it)->getAuthor().contains(word, Qt::CaseInsensitive) ) ) )
                    && (*it)->getTypeItem().contains("Manga", Qt::CaseInsensitive) ){
                if((state!="Stato" && (*it)->getState().contains(state, Qt::CaseInsensitive)) || state=="Stato"){
                    if((category!="Categoria" && (*it)->getGenre().contains(category, Qt::CaseInsensitive)) || category=="Categoria"){
                        temp.push_back(*it);
                        result=true;
                    }
                }
            }
        }
    }
    else if(type=="Anime"){
        for(auto it=items.begin(); it!=items.end(); ++it){
            if( ( word=="" || ( word!="" && ( (*it)->getOriginalName().contains(word, Qt::CaseInsensitive) ||
                                              (*it)->getEnglishName().contains(word, Qt::CaseInsensitive) || (*it)->getAuthor().contains(word, Qt::CaseInsensitive) ) ) )
                    && (*it)->getTypeItem().contains("Anime", Qt::CaseInsensitive) ){
                if((state!="Stato" && (*it)->getState().contains(state, Qt::CaseInsensitive)) || state=="Stato"){
                    if((category!="Categoria" && (*it)->getGenre().contains(category, Qt::CaseInsensitive)) || category=="Categoria"){
                        temp.push_back(*it);
                        result=true;
                    }
                }
            }
        }
    }
    if(result == false)
        QMessageBox::warning(0,"Attenzione","Nessun risultato trovato, ritenta!");
    return temp;
}

QList<Item*> ItemDatabase::allManga() const{
    QList<Item*> mangaBase;
    for(auto it = items.begin(); it !=items.end(); ++it){
        Base* mb = dynamic_cast<Base*>(*it);
        if(mb)
            mangaBase.push_back(mb);
        Deluxe* md = dynamic_cast<Deluxe*>(*it);
        if(md)
            mangaBase.push_back(md);
    }
    return mangaBase;
}

QList<Item*> ItemDatabase::allAnime() const{
    QList<Item*> animeSerie;
    for(auto it = items.begin() ; it != items.end(); ++it){
        Serie* as = dynamic_cast<Serie*>(*it);
        if(as)
            animeSerie.push_back(as);
        Film* af = dynamic_cast<Film*>(*it);
        if(af)
            animeSerie.push_back(af);
    }
    return animeSerie;
}

void ItemDatabase::Load(){
    QFile file("ItemDatabase.xml");

    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QXmlStreamReader xmlReader(&file);
        xmlReader.readNextStartElement();
        while(!xmlReader.atEnd()){
            Item* t=nullptr;
            if(xmlReader.name()=="Manga-Base"){ t=new Base;}
            else if(xmlReader.name()=="Manga-Deluxe"){t=new Deluxe;}
            else if(xmlReader.name()=="Anime-Serie"){t=new Serie;}
            else if(xmlReader.name()=="Anime-Film"){t=new Film;}
            if(t){
                t->loadItem(xmlReader);
                items.push_back(t);
            }
            xmlReader.readNextStartElement();
        }
    }
    else{
        QMessageBox::warning(0,"Database mancante","Creazione database di default degli articoli");
    }
}

void ItemDatabase::SaveAndClose(){
    QFile file("ItemDatabase.xml");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("Articoli");
    auto it=items.begin();
    for( ;it!=items.end();++it){
        (*it)->saveItem(xmlWriter);
    }
    xmlWriter.writeEndElement();
    xmlWriter.writeEndDocument();
    file.close();
}


