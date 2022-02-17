QT -= gui
QT += network

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        telegram/chat.cpp \
        telegram/chatlocation.cpp \
        telegram/chatpermissions.cpp \
        telegram/chatphoto.cpp \
        telegram/common.cpp \
        telegram/location.cpp \
        main.cpp \
        telegram/message.cpp \
        telegram/user.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    telegram/chat.h \
    telegram/chatlocation.h \
    telegram/chatpermissions.h \
    telegram/chatphoto.h \
    telegram/common.h \
    telegram/location.h \
    telegram/message.h \
    telegram/user.h
