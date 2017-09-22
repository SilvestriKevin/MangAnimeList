#include "serie.h"

Serie::Serie(const QString& OriginalName,const QString& EnglishName,const QString& Author,
             const QDate& ReleaseDate,const QString& State,const QString& Genre,
             const QString& Rating,const QString& Producer,const QString& Studio,const QString& Source,
             unsigned short int Duration, unsigned short int Episodes, unsigned short int Seasons):
    Anime(OriginalName,EnglishName,Author,ReleaseDate,State,Genre,Rating,Producer,Studio,Source,Duration),
    episodes(Episodes),seasons(Seasons){}

QString Serie::getTypeItem() const{
    return "Anime - Serie";
}
void Serie::saveItem(QXmlStreamWriter &w){
    w.writeStartElement("Anime-Serie");
    saveCommonFieldsItem(w);
    w.writeTextElement("Produttore", getProducer());
    w.writeTextElement("Studio", getStudio());
    w.writeTextElement("Origine", getSource());
    w.writeTextElement("Durata",QString::number(getDuration()));
    w.writeTextElement("Episodi",QString::number(getEpisodes()));
    w.writeTextElement("Stagioni",QString::number(getSeasons()));
    w.writeEndElement();
}

void Serie::loadItem(QXmlStreamReader &q){
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
    if(q.name() == "Episodi"){
        setEpisodes((q.readElementText()).toInt());
        q.readNextStartElement();
    }
    if(q.name() == "Stagioni"){
        setSeasons((q.readElementText()).toInt());
        q.readNextStartElement();
    }
}

unsigned short int Serie::getEpisodes() const{
    return episodes;
}
unsigned short int Serie::getSeasons() const{
    return seasons;
}

void Serie::setEpisodes(unsigned short int ep){
    episodes=ep;
}
void Serie::setSeasons(unsigned short int se){
    seasons=se;
}
