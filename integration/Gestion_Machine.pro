
QT       += core gui sql
QT       += printsupport
QT       += core gui sql charts
QT       +=serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino.cpp \
    commande.cpp \
    connexion.cpp \
    fichesuivi.cpp \
    fournisseur.cpp \
    machine.cpp \
    machinefiche.cpp \
    main.cpp \
    mainwindow.cpp \
    statistiques.cpp

HEADERS += \
    arduino.h \
    commande.h \
    connexion.h \
    fichesuivi.h \
    fournisseur.h \
    machine.h \
    machinefiche.h \
    mainwindow.h \
    statistiques.h

FORMS += \
    mainwindow.ui \
    statistiques.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target