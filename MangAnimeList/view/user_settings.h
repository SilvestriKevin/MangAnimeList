#ifndef USERSETTINGS
#define USERSETTINGS

#include <QDialog>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QString>
#include <QComboBox>
#include"../model/user_database.h"

class UserSettings:public QDialog{
private:
    Q_OBJECT
    QLabel *labelUsername;
    QLabel *labelPassword;
    QLabel *labelName;
    QLabel *labelSurname;
    QLabel *Type;
    QLabel *labelType;
    QComboBox *selectType;

    QLineEdit *textUsername;
    QLineEdit *textPassword;
    QLineEdit *textName;
    QLineEdit *textSurname;

    QPushButton *pushModify;
    QPushButton *pushDelete;
    QPushButton *pushAdd;

    QVBoxLayout *layoutUserSettings;
    QGridLayout *gridUserSettings;

    User *user;
    User *editeduser;

public:
    UserSettings(User* user, User *editedus);
    void addModLayout();
    void setModLayout();
    void changeUsername();
    void empty();
    void setLayoutAdd();

public slots:
    void save_change_user();
    void save_delete();
    void addUser();

signals:
    void sendChanges(User*,QString,QString,QString,QString, QString);
    void sendDelete(User*);
    void logout();
    void thisUser(User*);
};
#endif // USERSETTINGS

