QT += testlib network
QT -= gui

CONFIG += qt c++17 console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    main.cpp \
    tst_telegrammethods.cpp \
    tst_telegramtypes.cpp

HEADERS += \
    tst_telegrammethods.h \
    tst_telegramtypes.h

CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../src/release/ -ltelegramapi
else:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../src/debug/ -ltelegramapi
else:unix:!macx: LIBS += -L$$OUT_PWD/../src/ -ltelegramapi

INCLUDEPATH += $$PWD/../src
DEPENDPATH += $$PWD/../src
