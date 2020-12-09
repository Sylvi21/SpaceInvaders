QT       += core gui \
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Alien.cpp \
    AlienBullet.cpp \
    AlienFlock.cpp \
    Barrier.cpp \
    Score.cpp \
    Ship.cpp \
    Shoot.cpp \
    main.cpp \
    mainWindow.cpp

HEADERS += \
    Alien.h \
    AlienBullet.h \
    AlienFlock.h \
    Barrier.h \
    Score.h \
    Ship.h \
    Shoot.h \
    mainWindow.h

FORMS += \
    mainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES +=
