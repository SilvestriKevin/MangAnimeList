#ifndef ITEMSETTINGS
#define ITEMSETTINGS

#include <QDialog>
#include <QGridLayout>
#include <QGroupBox>
#include <QDateEdit>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QString>
#include <QComboBox>
#include <QRadioButton>
#include <QCheckBox>
#include"../model/item_database.h"
#include "../model/user.h"
#include "../model/item.h"

class ItemSettings:public QDialog{
    Q_OBJECT
private:
    User *user;
    Item *editedItem;
    /*********** Articolo Generico ***********/
    QGroupBox *generalItem;
    QLabel *labelOriginalName;
    QLabel *labelEnglishName;
    QLabel *labelAuthor;
    QLabel *labelReleaseDate;
    QLabel *labelState;
    QLabel *labelGenre;
    QLabel *labelRating;
    QLineEdit *editOriginalName;
    QLineEdit *editEnglishName;
    QLineEdit *editAuthor;
    QDateEdit *editReleaseDate;
    QComboBox *editState;
    QComboBox *editGenre;
    QComboBox *editRating;
    /*********** Scelta categoria e sottocategoria ***********/
    QLabel * labelItemType;
    QRadioButton * MB;
    QRadioButton * MD;
    QRadioButton * AS;
    QRadioButton * AF;
    /*********** Manga ***********/
    QGroupBox * Manga;
    QLabel * labelDealer;
    QLabel * labelChapters;
    QLabel * labelVolumes;
    QLineEdit * editDealer;
    QLineEdit * editChapters;
    QLineEdit * editVolumes;
    /*********** Anime ***********/
    QGroupBox * Anime;
    QLabel * labelProducer;
    QLabel * labelStudio;
    QLabel * labelSource;
    QLabel * labelDuration;
    QLineEdit * editProducer;
    QLineEdit * editStudio;
    QComboBox * editSource;
    QLineEdit * editDuration;
    /* **********  Manga: Base ********** */
    QGroupBox * MBase;
    QLabel * labelReprint;
    QLineEdit * editReprint;
    /* **********  Manga: Deluxe ********** */
    QGroupBox * MDeluxe;
    QCheckBox * editVariantCover;
    QCheckBox * editPoster;
    QCheckBox * editActionFigure;
    QCheckBox * editAdhesives;
    /* ********** Anime: Serie ********** */
    QGroupBox* ASerie;
    QLabel * labelEpisodes;
    QLabel * labelSeasons;
    QLineEdit * editEpisodes;
    QLineEdit * editSeasons;
    /* ********** Anime: Film ********** */
    QGroupBox* AFilm;
    QCheckBox * editSceneAfterQueueTitles;

    QPushButton *pushSaveChanges;
    QPushButton *pushDelete;
    QPushButton *pushNew;
    QVBoxLayout *layoutItemSettings;
    QGridLayout *gridItem;

public:
    ItemSettings(User *u, Item *it=nullptr);
    void addLayout();
    void setNewLayout();
    void setModLayout();
    void setViewLayout(Item *);
    void hideManga();
    void hideMB();
    void hideMD();
    void hideAnime();
    void hideAS();
    void hideAF();
    void hideALL();
    void showSaveDeleteNew();

public slots:
    void saveItem();
    void saveDELETE();
    void saveNEWITEM();
    void closeWindow();

    void viewTypeMB(bool);
    void gridWidMB();
    void viewTypeMD(bool);
    void gridWidMD();
    void viewTypeAS(bool);
    void gridWidAS();
    void viewTypeAF(bool);
    void gridWidAF();

signals:
    void sendDeleteItem(Item *);
    void sendNewItem(Item *);

    void sendInsertMB(Item*,User*, QString, QString, QString, QString, QString, QString, QString,
                      QString, QString, QString, QString);
    void sendInsertMD(Item*,User*, QString, QString, QString, QString, QString, QString, QString,
                      QString, QString, QString, bool, bool, bool, bool);
    void sendInsertAS(Item*, User*, QString, QString, QString, QString, QString, QString, QString,
                      QString, QString, QString, QString, QString, QString);
    void sendInsertAF(Item*, User*, QString, QString, QString, QString, QString, QString, QString,
                      QString, QString, QString, QString, bool);

};
#endif // ITEMSETTINGS

