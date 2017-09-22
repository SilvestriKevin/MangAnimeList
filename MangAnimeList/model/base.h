#ifndef BASE
#define BASE

#include "manga.h"

class Base: public Manga{
private:
    unsigned short int reprint;

public:
    Base(const QString& OriginalName="",const QString& EnglishName="", const QString& Author="",
         const QDate& ReleaseDate = QDate::currentDate(),const QString& State="",
         const QString& Genre="",const QString& Rating="",const QString& Dealer="",
         unsigned short int Chapters=0,unsigned short int Volumes=0,unsigned short int Reprint=0);

    virtual QString getTypeItem() const;
    virtual void saveItem(QXmlStreamWriter &);
    virtual void loadItem(QXmlStreamReader &);

    unsigned short int getReprint() const;

    void setReprint(unsigned short int);

};

#endif // BASE

