#ifndef MANGA
#define MANGA

#include "item.h"

class Manga : public Item{
private:
    QString dealer;
    unsigned short int chapters;
    unsigned short int volumes;
public:
    Manga(const QString& OriginalName="",const QString& EnglishName="", const QString& Author="",
          const QDate& ReleaseDate = QDate::currentDate(),const QString& State="",const QString& Genre="",
          const QString& Rating="",const QString& Dealer="",unsigned short int Chapters=0,
          unsigned short int Volumes=0);

    QString getDealer() const;
    unsigned short int getChapters() const;
    unsigned short int getVolumes() const;

    void setDealer(QString);
    void setChapters(unsigned short int);
    void setVolumes(unsigned short int);
};

#endif // MANGA

