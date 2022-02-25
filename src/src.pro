QT -= gui
QT += network

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        telegram/animation.cpp \
        telegram/audio.cpp \
        telegram/callbackgame.cpp \
        telegram/callbackquery.cpp \
        telegram/chat.cpp \
        telegram/chatinvitelink.cpp \
        telegram/chatjoinrequest.cpp \
        telegram/chatlocation.cpp \
        telegram/chatpermissions.cpp \
        telegram/chatphoto.cpp \
        telegram/choseninlineresult.cpp \
        telegram/common.cpp \
        telegram/contact.cpp \
        telegram/dice.cpp \
        telegram/document.cpp \
        telegram/encryptedcredentials.cpp \
        telegram/encryptedpassportelement.cpp \
        telegram/game.cpp \
        telegram/inlinekeyboardbutton.cpp \
        telegram/inlinekeyboardmarkup.cpp \
        telegram/inlinequery.cpp \
        telegram/invoice.cpp \
        telegram/location.cpp \
        main.cpp \
        telegram/loginurl.cpp \
        telegram/maskposition.cpp \
        telegram/message.cpp \
        telegram/messageautodeletetimerchanged.cpp \
        telegram/messageentity.cpp \
        telegram/orderinfo.cpp \
        telegram/passportdata.cpp \
        telegram/passportfile.cpp \
        telegram/photosize.cpp \
        telegram/poll.cpp \
        telegram/pollanswer.cpp \
        telegram/polloption.cpp \
        telegram/precheckoutquery.cpp \
        telegram/proximityalerttriggered.cpp \
        telegram/shippingaddress.cpp \
        telegram/shippingquery.cpp \
        telegram/sticker.cpp \
        telegram/successfulpayment.cpp \
        telegram/update.cpp \
        telegram/user.cpp \
        telegram/venue.cpp \
        telegram/video.cpp \
        telegram/videonote.cpp \
        telegram/voice.cpp \
        telegram/voicechatended.cpp \
        telegram/voicechatparticipantsinvited.cpp \
        telegram/voicechatscheduled.cpp \
        telegram/voicechatstarted.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    telegram/animation.h \
    telegram/audio.h \
    telegram/callbackgame.h \
    telegram/callbackquery.h \
    telegram/chat.h \
    telegram/chatinvitelink.h \
    telegram/chatjoinrequest.h \
    telegram/chatlocation.h \
    telegram/chatpermissions.h \
    telegram/chatphoto.h \
    telegram/choseninlineresult.h \
    telegram/common.h \
    telegram/contact.h \
    telegram/dice.h \
    telegram/document.h \
    telegram/encryptedcredentials.h \
    telegram/encryptedpassportelement.h \
    telegram/game.h \
    telegram/inlinekeyboardbutton.h \
    telegram/inlinekeyboardmarkup.h \
    telegram/inlinequery.h \
    telegram/invoice.h \
    telegram/location.h \
    telegram/loginurl.h \
    telegram/maskposition.h \
    telegram/message.h \
    telegram/messageautodeletetimerchanged.h \
    telegram/messageentity.h \
    telegram/orderinfo.h \
    telegram/passportdata.h \
    telegram/passportfile.h \
    telegram/photosize.h \
    telegram/poll.h \
    telegram/pollanswer.h \
    telegram/polloption.h \
    telegram/precheckoutquery.h \
    telegram/proximityalerttriggered.h \
    telegram/shippingaddress.h \
    telegram/shippingquery.h \
    telegram/sticker.h \
    telegram/successfulpayment.h \
    telegram/update.h \
    telegram/user.h \
    telegram/venue.h \
    telegram/video.h \
    telegram/videonote.h \
    telegram/voice.h \
    telegram/voicechatended.h \
    telegram/voicechatparticipantsinvited.h \
    telegram/voicechatscheduled.h \
    telegram/voicechatstarted.h
