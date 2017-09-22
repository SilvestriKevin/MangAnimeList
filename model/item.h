#ifndef ITEM
#define ITEM

#include <QString>
#include <QDate>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>

class Item{
private:
    static int codeNumber;
    int currentCodeNumber;
    QString originalName;
    QString englishName;
    QString author;
    QDate releaseDate;
    QString state;
    QString genre;
    QString rating;

public:
    Item(const QString& OriginalName="",const QString& EnglishName="", const QString& Author="",
         const QDate& ReleaseDate = QDate::currentDate(),const QString& State="",
         const QString& Genre="",const QString& Rating="");
    virtual ~Item()=default;

    virtual QString getTypeItem() const=0;
    virtual void saveItem(QXmlStreamWriter &)=0;
    virtual void loadItem(QXmlStreamReader &)=0;

    int getCodeNumber()const;
    QString getOriginalName()const;
    QString getEnglishName()const;
    QString getAuthor()const;
    QDate getReleaseDate()const;
    QString getState()const;
    QString getGenre()const;
    QString getRating()const;

    void setOriginalName(const QString&);
    void setEnglishName(const QString&);
    void setAuthor(const QString&);
    void setReleaseDate(const QDate&);
    void setState(const QString&);
    void setGenre(const QString&);
    void setRating(const QString&);

    void saveCommonFieldsItem(QXmlStreamWriter& xmlWriter);
    void loadCommonFieldsItem(QXmlStreamReader& xmlReader);

};
#endif // ITEM

