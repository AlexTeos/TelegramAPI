QT -= gui
QT += network

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
    telegram/api.cpp \
    telegram/types/animation.cpp \
    telegram/types/audio.cpp \
    telegram/types/callbackgame.cpp \
    telegram/types/callbackquery.cpp \
    telegram/types/chat.cpp \
    telegram/types/chatinvitelink.cpp \
    telegram/types/chatjoinrequest.cpp \
    telegram/types/chatlocation.cpp \
    telegram/types/chatmember.cpp \
    telegram/types/chatmemberadministrator.cpp \
    telegram/types/chatmemberbanned.cpp \
    telegram/types/chatmemberleft.cpp \
    telegram/types/chatmembermember.cpp \
    telegram/types/chatmemberowner.cpp \
    telegram/types/chatmemberrestricted.cpp \
    telegram/types/chatmemberupdated.cpp \
    telegram/types/chatpermissions.cpp \
    telegram/types/chatphoto.cpp \
    telegram/types/choseninlineresult.cpp \
    telegram/types/common.cpp \
    telegram/types/contact.cpp \
    telegram/types/dice.cpp \
    telegram/types/document.cpp \
    telegram/types/encryptedcredentials.cpp \
    telegram/types/encryptedpassportelement.cpp \
    telegram/types/forcereply.cpp \
    telegram/types/game.cpp \
    telegram/types/inlinekeyboardbutton.cpp \
    telegram/types/inlinekeyboardmarkup.cpp \
    telegram/types/inlinequery.cpp \
    telegram/types/invoice.cpp \
    telegram/types/keyboardbutton.cpp \
    telegram/types/keyboardbuttonpolltype.cpp \
    telegram/types/location.cpp \
    telegram/types/loginurl.cpp \
    telegram/types/maskposition.cpp \
    telegram/types/message.cpp \
    telegram/types/messageautodeletetimerchanged.cpp \
    telegram/types/messageentity.cpp \
    telegram/types/orderinfo.cpp \
    telegram/types/passportdata.cpp \
    telegram/types/passportfile.cpp \
    telegram/types/photosize.cpp \
    telegram/types/poll.cpp \
    telegram/types/pollanswer.cpp \
    telegram/types/polloption.cpp \
    telegram/types/precheckoutquery.cpp \
    telegram/types/proximityalerttriggered.cpp \
    telegram/types/replykeyboardmarkup.cpp \
    telegram/types/replykeyboardremove.cpp \
    telegram/types/shippingaddress.cpp \
    telegram/types/shippingquery.cpp \
    telegram/types/sticker.cpp \
    telegram/types/successfulpayment.cpp \
    telegram/types/update.cpp \
    telegram/types/user.cpp \
    telegram/types/venue.cpp \
    telegram/types/video.cpp \
    telegram/types/videonote.cpp \
    telegram/types/voice.cpp \
    telegram/types/voicechatended.cpp \
    telegram/types/voicechatparticipantsinvited.cpp \
    telegram/types/voicechatscheduled.cpp \
    telegram/types/voicechatstarted.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    telegram/api.h \
    telegram/types/animation.h \
    telegram/types/audio.h \
    telegram/types/callbackgame.h \
    telegram/types/callbackquery.h \
    telegram/types/chat.h \
    telegram/types/chatinvitelink.h \
    telegram/types/chatjoinrequest.h \
    telegram/types/chatlocation.h \
    telegram/types/chatmember.h \
    telegram/types/chatmemberadministrator.h \
    telegram/types/chatmemberbanned.h \
    telegram/types/chatmemberleft.h \
    telegram/types/chatmembermember.h \
    telegram/types/chatmemberowner.h \
    telegram/types/chatmemberrestricted.h \
    telegram/types/chatmemberupdated.h \
    telegram/types/chatpermissions.h \
    telegram/types/chatphoto.h \
    telegram/types/choseninlineresult.h \
    telegram/types/common.h \
    telegram/types/contact.h \
    telegram/types/dice.h \
    telegram/types/document.h \
    telegram/types/encryptedcredentials.h \
    telegram/types/encryptedpassportelement.h \
    telegram/types/forcereply.h \
    telegram/types/game.h \
    telegram/types/inlinekeyboardbutton.h \
    telegram/types/inlinekeyboardmarkup.h \
    telegram/types/inlinequery.h \
    telegram/types/invoice.h \
    telegram/types/keyboardbutton.h \
    telegram/types/keyboardbuttonpolltype.h \
    telegram/types/location.h \
    telegram/types/loginurl.h \
    telegram/types/maskposition.h \
    telegram/types/message.h \
    telegram/types/messageautodeletetimerchanged.h \
    telegram/types/messageentity.h \
    telegram/types/orderinfo.h \
    telegram/types/passportdata.h \
    telegram/types/passportfile.h \
    telegram/types/photosize.h \
    telegram/types/poll.h \
    telegram/types/pollanswer.h \
    telegram/types/polloption.h \
    telegram/types/precheckoutquery.h \
    telegram/types/proximityalerttriggered.h \
    telegram/types/replykeyboardmarkup.h \
    telegram/types/replykeyboardremove.h \
    telegram/types/shippingaddress.h \
    telegram/types/shippingquery.h \
    telegram/types/sticker.h \
    telegram/types/successfulpayment.h \
    telegram/types/update.h \
    telegram/types/user.h \
    telegram/types/venue.h \
    telegram/types/video.h \
    telegram/types/videonote.h \
    telegram/types/voice.h \
    telegram/types/voicechatended.h \
    telegram/types/voicechatparticipantsinvited.h \
    telegram/types/voicechatscheduled.h \
    telegram/types/voicechatstarted.h
