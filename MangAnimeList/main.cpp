#include <QApplication>
#include "model/user_database.h"
#include "model/item_database.h"
#include "controller/main_window_controller.h"


int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    MainWindowController mvc;
    mvc.Login();
    return a.exec();
}

