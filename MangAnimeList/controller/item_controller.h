#ifndef ITEM_CONTROLLER
#define ITEM_CONTROLLER

#include "../model/item_database.h"
#include "../view/item_settings.h"
#include <QObject>
#include <QMessageBox>

class Item_Controller:public QObject{
private:
    Q_OBJECT
    ItemDatabase * allItems;
    ItemSettings * viewItems;
public:
    Item_Controller(ItemDatabase * dbItem, QObject* parent=0);
    void updateItemView(ItemSettings*);
    bool checkCommonFields(Item*, QString, QString, QString, QString, QString, QString, QString, bool);

public slots:
    //Manga Base
    void getChangesMB(Item*,User*, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString);

    //Manga Deluxe
    void getChangesMD(Item*,User*, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, bool, bool, bool, bool);

    //Anime Serie
    void getChangesAS(Item*, User*, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString);

    //Anime Film
    void getChangesAF(Item*, User*, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, bool);

    void getDelete(Item*);
    void getNewItem(Item*);
};

#endif // ITEM_CONTROLLER
