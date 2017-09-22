#include "item.h"

int Item::codeNumber = 0;

Item::Item(const QString& OriginalName,const QString& EnglishName,const QString& Author,
           const QDate& ReleaseDate,const QString& State,const QString& Genre,
           const QString& Rating) : originalName(OriginalName),englishName(EnglishName),
    author(Author), releaseDate(ReleaseDate),state(State),genre(Genre),rating(Rating){
    codeNumber++;
    currentCodeNumber=codeNumber;
}

int Item::getCodeNumber() const {
    return currentCodeNumber;
}
QString Item::getOriginalName() const {
    return originalName;
}
QString Item::getEnglishName() const {
    return englishName;
}
QString Item::getAuthor() const {
    return author;
}
QDate Item::getReleaseDate() const {
    return releaseDate;
}
QString Item::getState() const
{
    return state;
}
QString Item::getGenre() const
{
    return genre;
}
QString Item::getRating() const
{
    return rating;
}

void Item::setOriginalName(const QString &on) {
    originalName=on;
}
void Item::setEnglishName(const QString &en) {
    englishName=en;
}
void Item::setAuthor(const QString& aut) {
    author=aut;
}
void Item::setReleaseDate(const QDate& rd) {
    releaseDate=rd;
}
void Item::setState(const QString& st) {
    state=st;
}
void Item::setGenre(const QString& gn) {
    genre=gn;
}
void Item::setRating(const QString& rt) {
    rating=rt;
}

void Item::saveCommonFieldsItem(QXmlStreamWriter& xmlWriter){
    xmlWriter.writeTextElement("NomeOriginale", getOriginalName());
    xmlWriter.writeTextElement("NomeInglese", getEnglishName());
    xmlWriter.writeTextElement("Autore", getAuthor());
    xmlWriter.writeTextElement("DataPubblicazione", getReleaseDate().toString("dd/MM/yyyy"));
    xmlWriter.writeTextElement("Stato", getState());
    xmlWriter.writeTextElement("Genere", getGenre());
    xmlWriter.writeTextElement("Rating", getRating());
}

void Item::loadCommonFieldsItem(QXmlStreamReader& xmlReader){
    xmlReader.readNextStartElement();
    if(xmlReader.name() == "NomeOriginale"){
        setOriginalName(xmlReader.readElementText());
        xmlReader.readNextStartElement();
    }
    if(xmlReader.name() == "NomeInglese"){
        setEnglishName(xmlReader.readElementText());
        xmlReader.readNextStartElement();
    }
    if(xmlReader.name() == "Autore"){
        setAuthor(xmlReader.readElementText());
        xmlReader.readNextStartElement();
    }
    if(xmlReader.name() == "DataPubblicazione"){
        setReleaseDate(QDate::fromString(xmlReader.readElementText(),"dd/MM/yyyy"));
        xmlReader.readNextStartElement();
    }
    if(xmlReader.name() == "Stato"){
        setState(xmlReader.readElementText());
        xmlReader.readNextStartElement();
    }
    if(xmlReader.name() == "Genere"){
        setGenre(xmlReader.readElementText());
        xmlReader.readNextStartElement();
    }
    if(xmlReader.name() == "Rating"){
        setRating(xmlReader.readElementText());
        xmlReader.readNextStartElement();
    }
}
