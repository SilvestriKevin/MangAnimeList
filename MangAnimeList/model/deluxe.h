#ifndef DELUXE
#define DELUXE

#include "manga.h"

class Deluxe: public Manga {
private:
    bool variantCover;
    bool poster;
    bool actionFigure;
    bool adhesives;

public:
    Deluxe(const QString& OriginalName="",const QString& EnglishName="", const QString& Author="",
           const QDate& ReleaseDate = QDate::currentDate(),const QString& State="",const QString& Genre="",
           const QString& Rating="",const QString& Dealer="",
           unsigned short int Chapters=0,unsigned short int Volumes=0,bool VariantCover=false,bool Poster=false,bool ActionFigure=false,
           bool Adhesives=false);

    virtual QString getTypeItem() const;
    virtual void saveItem(QXmlStreamWriter &);
    virtual void loadItem(QXmlStreamReader &);

    bool getVariantCover() const;
    bool getPoster() const;
    bool getActionFigure() const;
    bool getAdhesives() const;

    void setVariantCover(bool);
    void setPoster(bool);
    void setActionFigure(bool);
    void setAdhesives(bool);

};

#endif // DELUXE


