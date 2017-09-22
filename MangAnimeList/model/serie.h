#ifndef SERIE
#define SERIE

#include "anime.h"

class Serie:public Anime{
private:
    unsigned short int episodes;
    unsigned short int seasons;

public:
    Serie(const QString& OriginalName="",const QString& EnglishName="", const QString& Author="",
          const QDate& ReleaseDate = QDate::currentDate(),const QString& State="",const QString& Genre="",
          const QString& Rating="",const QString& Producer="",const QString& Studio="",const QString& Source="",
          unsigned short int Duration=0, unsigned short int Episodes=0, unsigned short int Seasons=0);

    virtual QString getTypeItem() const;
    virtual void saveItem(QXmlStreamWriter &);
    virtual void loadItem(QXmlStreamReader &);

    unsigned short int getEpisodes() const;
    unsigned short int getSeasons() const;

    void setEpisodes(unsigned short int);
    void setSeasons(unsigned short int);

};

#endif // SERIE

