#ifndef LOGINWINDOW
#define LOGINWINDOW

#include <QString>
#include <QDialog>
#include <QMessageBox>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QRegExpValidator>
#include <QPixmap>

class LoginWindow: public QDialog{
private:
    Q_OBJECT
    QLabel * windowIcon;

    QLabel * labelLogin;
    QLabel * labelUsernameLogin;
    QLabel * labelPasswordLogin;
    QLineEdit * textUsernameLogin;
    QLineEdit * textPasswordLogin;
    QPushButton * pushLogin;
    QGridLayout * gridLogin;

    QLabel * labelRegister;
    QLabel * labelName;
    QLabel * labelSurname;
    QLabel * labelUsernameRegister;
    QLabel * labelPasswordRegister;
    QLineEdit * textName;
    QLineEdit * textSurname;
    QLineEdit * textUsernameRegister;
    QLineEdit * textPasswordRegister;
    QPushButton * pushRegister;
    QGridLayout * gridRegister;

    QVBoxLayout * layoutLogin;

public:
    LoginWindow();
    void empty();

public slots:
    void login();
    void register_user();

signals:
    void doLogin(const QString&, const QString&);
    void doRegister(const QString&, const QString&, const QString&, const QString&);
};
#endif // LOGINWINDOW

