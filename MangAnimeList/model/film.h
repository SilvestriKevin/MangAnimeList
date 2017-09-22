#ifndef FILM
#define FILM

#include "anime.h"

class Film: public Anime{
private:
    bool sceneAfterQueueTitles;

public:
    Film(const QString& OriginalName="",const QString& EnglishName="", const QString& Author="",
         const QDate& ReleaseDate = QDate::currentDate(),const QString& State="",const QString& Genre="",
         const QString& Rating="",const QString& Producer="",const QString& Studio="",const QString& Source="",
         unsigned short int Duration=0,bool SceneAfterQueueTitles=false);

    virtual QString getTypeItem() const;
    virtual void saveItem(QXmlStreamWriter &);
    virtual void loadItem(QXmlStreamReader &);

    bool getSceneAfterQueueTitles() const;

    void setSceneAfterQueueTitles(bool);
};

#endif // FILM

