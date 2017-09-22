#ifndef LIST
#define LIST

#include <QWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QVBoxLayout>
#include "../model/user_database.h"
#include "../model/item_database.h"
#include "user_settings.h"


class DBList:public QTableWidget{
private:
    Q_OBJECT
    ItemDatabase * itemlist;
    UserDatabase * userlist;

public:
    DBList(ItemDatabase *itemdb, UserDatabase *userdb, QWidget *parent=0);
    void viewUsers();
    void addListUsers(User*);
    void addListUsers(QList<User*>);
    void addListAllUsers();
    void addItemUser(int, User*);

    void viewItems();
    void addListItems(Item*);
    void addListItems(QList<Item*>);
    void addListAllItems();
    void addItemItem(int, Item*);

signals:
    void clicked(int,int);
};
#endif //LIST
