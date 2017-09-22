#include "manga.h"

Manga::Manga(const QString& OriginalName,const QString& EnglishName,const QString& Author,
             const QDate& ReleaseDate,const QString& State,const QString& Genre,
             const QString& Rating,const QString& Dealer,unsigned short int Chapters,
             unsigned short int Volumes) : Item(OriginalName,EnglishName,Author,ReleaseDate,State,Genre,Rating),
    dealer(Dealer),chapters(Chapters), volumes(Volumes) {}

QString Manga::getDealer() const {
    return dealer;
}
unsigned short int Manga::getChapters() const{
    return chapters;
}
unsigned short int Manga::getVolumes() const{
    return volumes;
}

void Manga::setDealer(QString deal) {
    dealer=deal;
}
void Manga::setChapters(unsigned short c) {
    chapters=c;
}
void Manga::setVolumes(unsigned short v) {
    volumes=v;
}



