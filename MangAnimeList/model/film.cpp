#include "film.h"
#include <typeinfo>

Film::Film(const QString& OriginalName,const QString& EnglishName,const QString& Author,
           const QDate& ReleaseDate,const QString& State,const QString& Genre,
           const QString& Rating,const QString& Producer,const QString& Studio,const QString& Source,
           unsigned short int Duration,bool SceneAfterQueueTitles) :
    Anime(OriginalName,EnglishName,Author,ReleaseDate,State,Genre,Rating,Producer,Studio,Source,Duration),
    sceneAfterQueueTitles(SceneAfterQueueTitles) {}

QString Film::getTypeItem() const{
    return "Anime - Film";
}

void Film::saveItem(QXmlStreamWriter &w){
    w.writeStartElement("Anime-Film");
    saveCommonFieldsItem(w);
    w.writeTextElement("Produttore", getProducer());
    w.writeTextElement("Studio", getStudio());
    w.writeTextElement("Origine", getSource());
    w.writeTextElement("Durata",QString::number(getDuration()));
    w.writeTextElement("ScenaDopoITitoliDiCoda",getSceneAfterQueueTitles() ? "1" : "0");
    w.writeEndElement();
}

void Film::loadItem(QXmlStreamReader &q){
    loadCommonFieldsItem(q);
    if(q.name() == "Produttore"){
        setProducer(q.readElementText());
        q.readNextStartElement();
    }
    if(q.name() == "Studio"){
        setStudio((q.readElementText()));
        q.readNextStartElement();
    }
    if(q.name() == "Origine"){
        setSource(q.readElementText());
        q.readNextStartElement();
    }
    if(q.name() == "Durata"){
        setDuration((q.readElementText()).toInt());
        q.readNextStartElement();
    }
    if(q.name() == "ScenaDopoITitoliDiCoda"){
        setSceneAfterQueueTitles((q.readElementText() =="1")? true:false);
        q.readNextStartElement();
    }
}

bool Film::getSceneAfterQueueTitles() const{
    return sceneAfterQueueTitles;
}

void Film::setSceneAfterQueueTitles(bool saqt){
    sceneAfterQueueTitles=saqt;
}
