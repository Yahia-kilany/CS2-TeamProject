QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    BooyerMooreMatcherQT.cpp \
    BruteForceMatcherQT.cpp \
    CorpusQT.cpp \
    DocumentQT.cpp \
    MatcherQT.cpp \
    RabinKarpMatcherQT.cpp \
    kmpMatcherQT.cpp \
    main.cpp \
    mainwindow.cpp \
    viewcorpus.cpp

HEADERS += \
    BooyerMooreMatcherQT.h \
    BruteForceMatcherQT.h \
    CorpusQT.h \
    DocumentQT.h \
    MatcherQT.h \
    RabinKarpMatcherQT.h \
    kmpMatcherQT.h \
    mainwindow.h \
    viewcorpus.h

FORMS += \
    mainwindow.ui \
    viewcorpus.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
