#include "base.h"

Base::Base(const QString& OriginalName,const QString& EnglishName,const QString& Author,
           const QDate& ReleaseDate,const QString& State,const QString& Genre,
           const QString& Rating,const QString& Dealer,unsigned short int Chapters,
           unsigned short int Volumes,unsigned short int Reprint) :
    Manga(OriginalName,EnglishName,Author,ReleaseDate,State,Genre,Rating,Dealer,Chapters,Volumes),reprint(Reprint){}

QString Base::getTypeItem() const{
    return "Manga - Base";
}
void Base::saveItem(QXmlStreamWriter & w){
    w.writeStartElement("Manga-Base");
    saveCommonFieldsItem(w);
    w.writeTextElement("Distributore", getDealer());
    w.writeTextElement("Capitoli", QString::number(getChapters()));
    w.writeTextElement("Volumi", QString::number(getVolumes()));
    w.writeTextElement("Ristampa",QString::number(getReprint()));
    w.writeEndElement();
}
void Base::loadItem(QXmlStreamReader & q){
    loadCommonFieldsItem(q);
    if(q.name() == "Distributore"){
        setDealer(q.readElementText());
        q.readNextStartElement();
    }
    if(q.name() == "Capitoli"){
        setChapters((q.readElementText()).toInt());
        q.readNextStartElement();
    }
    if(q.name() == "Volumi"){
        setVolumes((q.readElementText()).toInt());
        q.readNextStartElement();
    }
    if(q.name() == "Ristampa"){
        setReprint((q.readElementText()).toInt());
        q.readNextStartElement();
    }
}

unsigned short int Base::getReprint() const{
    return reprint;
}

void Base::setReprint(unsigned short int rp){
    reprint=rp;
}


