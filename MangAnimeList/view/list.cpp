#include "list.h"

DBList::DBList(ItemDatabase *itemdb, UserDatabase *userdb, QWidget *parent):
    QTableWidget(parent), itemlist(itemdb), userlist(userdb){
    setSelectionMode(QAbstractItemView::SingleSelection);
    setSelectionBehavior(QAbstractItemView::SelectRows);
}

void DBList::viewUsers(){
    this->setRowCount(0);
    QStringList tableHeader;
    setColumnCount(4);
    setColumnWidth(0,255);
    setColumnWidth(1,210);
    setColumnWidth(2,200);
    setColumnWidth(3,265);
    setMaximumWidth(933);
    tableHeader<<"Username"<<"Nome"<<"Cognome"<<"Tipologia Account";
    setHorizontalHeaderLabels(tableHeader);
    setEditTriggers(QAbstractItemView::NoEditTriggers);

}

void DBList::addListUsers(User* user){
    int row=0;
    if(user){
        setRowCount(row+1);
        addItemUser(row,user);
    }
    else
        QMessageBox::warning(0,"Utente", "Utente non trovato, riprova!");
}

void DBList::addListUsers(QList<User*> p){
    int row=0;
    auto it=p.begin();
    for( ; it != p.end(); ++it){
        if(*it){
            setRowCount(row+1);
            addItemUser(row,*it);
            row++;
        }
    }
}

void DBList::addListAllUsers(){
    int row=0;
    QList<User*> userList= userlist->getAllUsers();
    QList<User*>::const_iterator it=userList.begin();
    for(; it!=userList.end() ;it++){
        if(*it){
            setRowCount(row+1);
            addItemUser(row,*it);
            row++;
        }
    }
}

void DBList::addItemUser(int row, User* u){
    setItem(row,0,new QTableWidgetItem(u->getUsername()));
    setItem(row,1,new QTableWidgetItem(u->getName()));
    setItem(row,2,new QTableWidgetItem(u->getSurname()));
    setItem(row,3,new QTableWidgetItem(u->getLabel()));
}

void DBList::viewItems(){
    this->setRowCount(0);
    QStringList tableHeader;
    setColumnCount(8);
    setColumnWidth(0,50);
    setColumnWidth(1,130);
    setColumnWidth(2,130);
    setColumnWidth(3,130);
    setColumnWidth(4,150);
    setColumnWidth(5,90);
    setColumnWidth(6,120);
    setColumnWidth(7,130);
    setMaximumWidth(933);
    tableHeader<<"Cod."<<"Nome Originale"<<"Nome Inglese"<<"Autore"<<"Data Pubblicazione"<<"Stato"<<"Categoria"<<"Tipo";
    setHorizontalHeaderLabels(tableHeader);
}

void DBList::addListItems(Item *p){
    int row=0;
    if(p){
        setRowCount(row+1);
        addItemItem(row,p);
    }
    else
        QMessageBox::warning(0,"Articolo", "Articolo non trovato, riprova!");

}

void DBList::addListItems(QList<Item*> p){
    int row=0;
    auto it=p.begin();
    for( ; it != p.end(); ++it){
        if(*it){
            setRowCount(row+1);
            addItemItem(row,*it);
            row++;
        }
    }
}

void DBList::addListAllItems(){
    int row=0;
    QList<Item*> mainlist=itemlist->getAllItems();
    QList<Item*>::const_iterator it=mainlist.begin();
    for(; it!=mainlist.end(); it++){
        if(*it){
            setRowCount(row+1);
            addItemItem(row,*it);
            row++;
        }
    }
}

void DBList::addItemItem(int r, Item* p){
    setItem(r,0,new QTableWidgetItem(QString::number(p->getCodeNumber())));
    setItem(r,1,new QTableWidgetItem(p->getOriginalName()));
    setItem(r,2,new QTableWidgetItem(p->getEnglishName()));
    setItem(r,3,new QTableWidgetItem(p->getAuthor()));
    setItem(r,4,new QTableWidgetItem(p->getReleaseDate().toString("d MMM yyyy")));
    setItem(r,5,new QTableWidgetItem(p->getState()));
    setItem(r,6,new QTableWidgetItem(p->getGenre()));
    setItem(r,7,new QTableWidgetItem(p->getTypeItem()));
}


