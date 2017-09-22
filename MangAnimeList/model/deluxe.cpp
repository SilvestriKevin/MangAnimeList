#include "deluxe.h"

Deluxe::Deluxe(const QString& OriginalName,const QString& EnglishName,const QString& Author,const QDate& ReleaseDate,
               const QString& State,const QString& Genre,const QString& Rating,const QString& Dealer,
               unsigned short int Chapters,unsigned short int Volumes,bool VariantCover,bool Poster,
               bool ActionFigure,bool Adhesives) :
    Manga(OriginalName,EnglishName,Author,ReleaseDate,State,Genre,Rating,Dealer,Chapters,Volumes),
    variantCover(VariantCover), poster(Poster), actionFigure(ActionFigure), adhesives(Adhesives){}

QString Deluxe::getTypeItem() const{
    return "Manga - Deluxe";
}

void Deluxe::saveItem(QXmlStreamWriter &w){
    w.writeStartElement("Manga-Deluxe");
    saveCommonFieldsItem(w);
    w.writeTextElement("Distributore", getDealer());
    w.writeTextElement("Capitoli", QString::number(getChapters()));
    w.writeTextElement("Volumi", QString::number(getVolumes()));
    w.writeTextElement("VariantCover", getVariantCover() ? "1" : "0");
    w.writeTextElement("Poster", getPoster() ? "1" : "0");
    w.writeTextElement("ActionFigure", getActionFigure() ? "1" : "0");
    w.writeTextElement("Adhesives", getAdhesives() ? "1" : "0");
    w.writeEndElement();
}

void Deluxe::loadItem(QXmlStreamReader &q){
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
    if(q.name() == "VariantCover"){
        setVariantCover((q.readElementText() == "1")? true:false);
        q.readNextStartElement();
    }
    if(q.name() == "Poster"){
        setPoster((q.readElementText() == "1")? true:false);
        q.readNextStartElement();
    }
    if(q.name() == "ActionFigure"){
        setActionFigure((q.readElementText() == "1")? true:false);
        q.readNextStartElement();
    }
    if(q.name() == "Adhesives"){
        setAdhesives((q.readElementText()  == "1")? true:false);
        q.readNextStartElement();
    }
}

bool Deluxe::getVariantCover() const{
    return variantCover;
}
bool Deluxe::getPoster() const{
    return poster;
}
bool Deluxe::getActionFigure() const{
    return actionFigure;
}
bool Deluxe::getAdhesives() const{
    return adhesives;
}

void Deluxe::setVariantCover(bool vc){
    variantCover=vc;
}
void Deluxe::setPoster(bool p){
    poster=p;
}
void Deluxe::setActionFigure(bool af){
    actionFigure=af;
}
void Deluxe::setAdhesives(bool ad){
    adhesives=ad;
}
