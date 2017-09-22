#include "anime.h"

Anime::Anime(const QString& OriginalName,const QString& EnglishName,const QString& Author,
             const QDate& ReleaseDate,const QString& State,const QString& Genre,
             const QString& Rating,const QString& Producer,const QString& Studio,const QString& Source,
             unsigned short int Duration) : Item(OriginalName,EnglishName,Author,ReleaseDate,State,Genre,Rating),
    producer(Producer),studio(Studio),source(Source),duration(Duration) {}

QString Anime::getProducer() const{
    return producer;
}
QString Anime::getStudio() const{
    return studio;
}
QString Anime::getSource() const{
    return source;
}
unsigned short int Anime::getDuration() const{
    return duration;
}

void Anime::setProducer(QString pr){
    producer = pr;
}
void Anime::setStudio(QString st){
    studio = st;
}
void Anime::setSource(QString sr){
    source = sr;
}
void Anime::setDuration(unsigned short int dr){
    duration = dr;
}


