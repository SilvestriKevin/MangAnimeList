#ifndef ITEM_DATABASE
#define ITEM_DATABASE

#include "item.h"
#include "base.h"
#include "deluxe.h"
#include "serie.h"
#include "film.h"
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QList>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QString>

class ItemDatabase{
private:
    QList<Item*> items;
public:
    ItemDatabase();
    ~ItemDatabase();

    void addItemToDB(Item*);
    void removeItemFromDB(Item*);
    Item* getItem(int)const;
    const QList<Item*> getAllItems()const;
    const QList<Item*> searchItems(const QString &,const QString &,const QString &,const QString &) const;
    QList<Item*> allManga() const;
    QList<Item*> allAnime() const;
    void Load();
    void SaveAndClose();
};

#endif // ITEM_DATABASE

