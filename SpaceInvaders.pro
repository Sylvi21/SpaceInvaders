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
    Barrier.cpp \
    BossAlien.cpp \
    EasyAlien.cpp \
    EasyLevel.cpp \
    HardAlien.cpp \
    HardLevel.cpp \
    Level.cpp \
    MediumAlien.cpp \
    MediumLevel.cpp \
    MultishootBuff.cpp \
    Score.cpp \
    ShieldBuff.cpp \
    Ship.cpp \
    Shoot.cpp \
    StartWindow.cpp \
    main.cpp \
    mainWindow.cpp

HEADERS += \
    Alien.h \
    AlienBullet.h \
    AnimationState.h \
    Barrier.h \
    BossAlien.h \
    EasyAlien.h \
    EasyLevel.h \
    HardAlien.h \
    HardLevel.h \
    Level.h \
    LevelState.h \
    MediumAlien.h \
    MediumLevel.h \
    MultishootBuff.h \
    Score.h \
    ShieldBuff.h \
    Ship.h \
    Shoot.h \
    StartWindow.h \
    mainWindow.h

FORMS += \
    StartWindow.ui \
    mainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES +=
