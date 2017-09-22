TEMPLATE = app
TARGET   = MangAnimeList
QT       += core gui
QT       += xml
QT       += widgets
QMAKE_CXXFLAGS += -std=c++11
RESOURCES = resources.qrc

SOURCES += main.cpp \
    model/base.cpp \
    model/user.cpp \
    model/user_admin.cpp \
    model/user_database.cpp \
    view/list.cpp \
    controller/user_controller.cpp \
    model/item.cpp \
    model/manga.cpp \
    model/deluxe.cpp \
    model/anime.cpp \
    model/serie.cpp \
    model/film.cpp \
    model/item_database.cpp \
    model/user_pro.cpp \
    model/user_standard.cpp \
    controller/item_controller.cpp \
    controller/main_window_controller.cpp \
    view/login_window.cpp \
    view/main_window.cpp \
    view/item_settings.cpp \
    view/view_item.cpp \
    view/user_settings.cpp \
    view/search_window.cpp

HEADERS  += \
    model/base.h \
    model/user.h \
    model/user_admin.h \
    model/user_database.h \
    view/list.h \
    controller/user_controller.h \
    model/item.h \
    model/manga.h \
    model/deluxe.h \
    model/anime.h \
    model/serie.h \
    model/film.h \
    model/item_database.h \
    model/user_pro.h \
    model/user_standard.h \
    controller/item_controller.h \
    controller/main_window_controller.h \
    view/login_window.h \
    view/main_window.h \
    view/item_settings.h \
    view/view_item.h \
    view/user_settings.h \
    view/search_window.h


