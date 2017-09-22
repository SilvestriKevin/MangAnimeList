#ifndef ANIME
#define ANIME

#include "item.h"

class Anime: public Item{
private:
    QString producer;
    QString studio;
    QString source;
    unsigned short int duration; //in minuti

public:
    Anime(const QString& OriginalName="",const QString& EnglishName="", const QString& Author="",
          const QDate& ReleaseDate = QDate::currentDate(),const QString& State="",const QString& Genre="",
          const QString& Rating="",const QString& Producer="",const QString& Studio="",const QString& Source="",
          unsigned short int Duration=0);

    QString getProducer() const;
    QString getStudio() const;
    QString getSource() const;
    unsigned short int getDuration() const;

    void setProducer(QString);
    void setStudio(QString);
    void setSource(QString);
    void setDuration(unsigned short int);

};

#endif // ANIME

