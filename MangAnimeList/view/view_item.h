#ifndef VIEWITEM
#define VIEWITEM

#include <QDialog>
#include <QLabel>
#include <QString>
#include <QHBoxLayout>
#include <QComboBox>
#include <QPushButton>
#include "../model/item.h"
#include "../model/base.h"
#include "../model/deluxe.h"
#include "../model/serie.h"
#include "../model/film.h"
#include "../model/user.h"
#include "../model/user_standard.h"

class ViewItem: public QDialog{
private:
    Q_OBJECT
    User * user;
    Item * item;
    /*********** Articolo Generico ***********/
    QLabel *labelOriginalName;
    QLabel *labelEnglishName;
    QLabel *labelAuthor;
    QLabel *labelReleaseDate;
    QLabel *labelState;
    QLabel *labelGenre;
    QLabel *labelRating;
    QLabel *originalName;
    QLabel *englishName;
    QLabel *author;
    QLabel *releaseDate;
    QLabel *state;
    QLabel *genre;
    QLabel *rating;
    /*********** Scelta categoria e sottocategoria ***********/
    QLabel * labelItemType;
    QLabel * ItemType;
    /*********** Manga ***********/
    QLabel * labelDealer;
    QLabel * labelChapters;
    QLabel * labelVolumes;
    QLabel * dealer;
    QLabel * chapters;
    QLabel * volumes;
    /*********** Anime ***********/
    QLabel * labelProducer;
    QLabel * labelStudio;
    QLabel * labelSource;
    QLabel * labelDuration;
    QLabel * producer;
    QLabel * studio;
    QLabel * source;
    QLabel * duration;
    /***********  Manga: Base ***********/
    QLabel * labelReprint;
    QLabel * reprint;
    /***********  Manga: Deluxe ***********/
    QLabel * labelVariantCover;
    QLabel * variantCover;
    QLabel * labelPoster;
    QLabel * poster;
    QLabel * labelActionFigure;
    QLabel * actionFigure;
    QLabel * labelAdhesives;
    QLabel * adhesives;
    /*********** Anime: Serie ***********/
    QLabel * labelEpisodes;
    QLabel * labelSeasons;
    QLabel * episodes;
    QLabel * seasons;
    /*********** Anime: Film ***********/
    QLabel * labelSceneAfterQueueTitles;
    QLabel * sceneAfterQueueTitles;

    QString status;
    QLabel * labelStatus;
    QComboBox * statusFor;
    QPushButton * saveStatus;

    QGridLayout * gridItemLabel;
    QWidget * window;

public:
    ViewItem(User *us,Item *it=nullptr);
    void addLayout();
    void commonLabels();
    void commonLabelsManga();
    void commonLabelsAnime();
    void commonLayoutManga() const;
    void commonLayoutAnime() const;

public slots:
    void saveListItem();

signals:
    void sendInsertStatus(Item*,User*, QString, QString);

};
#endif // VIEWITEM

