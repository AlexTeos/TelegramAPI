QT += network
CONFIG += qt c++17

TEMPLATE = lib
TARGET = telegramapi

DEFINES += QT_MESSAGELOGCONTEXT

SOURCES += \
    telegramapi.cpp \
    types/animation.cpp \
    types/audio.cpp \
    types/botcommand.cpp \
    types/botcommandscope.cpp \
    types/botcommandscopeallchatadministrators.cpp \
    types/botcommandscopeallgroupchats.cpp \
    types/botcommandscopeallprivatechats.cpp \
    types/botcommandscopechat.cpp \
    types/botcommandscopechatadministrators.cpp \
    types/botcommandscopechatmember.cpp \
    types/botcommandscopedefault.cpp \
    types/callbackgame.cpp \
    types/callbackquery.cpp \
    types/chat.cpp \
    types/chatinvitelink.cpp \
    types/chatjoinrequest.cpp \
    types/chatlocation.cpp \
    types/chatmember.cpp \
    types/chatmemberadministrator.cpp \
    types/chatmemberbanned.cpp \
    types/chatmemberleft.cpp \
    types/chatmembermember.cpp \
    types/chatmemberowner.cpp \
    types/chatmemberrestricted.cpp \
    types/chatmemberupdated.cpp \
    types/chatpermissions.cpp \
    types/chatphoto.cpp \
    types/choseninlineresult.cpp \
    types/common.cpp \
    types/contact.cpp \
    types/dice.cpp \
    types/document.cpp \
    types/encryptedcredentials.cpp \
    types/encryptedpassportelement.cpp \
    types/forcereply.cpp \
    types/game.cpp \
    types/inlinekeyboardbutton.cpp \
    types/inlinekeyboardmarkup.cpp \
    types/inlinequery.cpp \
    types/invoice.cpp \
    types/keyboardbutton.cpp \
    types/keyboardbuttonpolltype.cpp \
    types/location.cpp \
    types/loginurl.cpp \
    types/maskposition.cpp \
    types/menubutton.cpp \
    types/menubuttoncommands.cpp \
    types/menubuttondefault.cpp \
    types/menubuttonwebapp.cpp \
    types/message.cpp \
    types/messageautodeletetimerchanged.cpp \
    types/messageentity.cpp \
    types/orderinfo.cpp \
    types/passportdata.cpp \
    types/passportfile.cpp \
    types/photosize.cpp \
    types/poll.cpp \
    types/pollanswer.cpp \
    types/polloption.cpp \
    types/precheckoutquery.cpp \
    types/proximityalerttriggered.cpp \
    types/replykeyboardmarkup.cpp \
    types/replykeyboardremove.cpp \
    types/shippingaddress.cpp \
    types/shippingquery.cpp \
    types/sticker.cpp \
    types/successfulpayment.cpp \
    types/update.cpp \
    types/user.cpp \
    types/venue.cpp \
    types/video.cpp \
    types/videonote.cpp \
    types/voice.cpp \
    types/voicechatended.cpp \
    types/voicechatparticipantsinvited.cpp \
    types/voicechatscheduled.cpp \
    types/voicechatstarted.cpp \
    types/webappinfo.cpp

HEADERS += \
    telegramapi.h \
    types/animation.h \
    types/audio.h \
    types/botcommand.h \
    types/botcommandscope.h \
    types/botcommandscopeallchatadministrators.h \
    types/botcommandscopeallgroupchats.h \
    types/botcommandscopeallprivatechats.h \
    types/botcommandscopechat.h \
    types/botcommandscopechatadministrators.h \
    types/botcommandscopechatmember.h \
    types/botcommandscopedefault.h \
    types/callbackgame.h \
    types/callbackquery.h \
    types/chat.h \
    types/chatinvitelink.h \
    types/chatjoinrequest.h \
    types/chatlocation.h \
    types/chatmember.h \
    types/chatmemberadministrator.h \
    types/chatmemberbanned.h \
    types/chatmemberleft.h \
    types/chatmembermember.h \
    types/chatmemberowner.h \
    types/chatmemberrestricted.h \
    types/chatmemberupdated.h \
    types/chatpermissions.h \
    types/chatphoto.h \
    types/choseninlineresult.h \
    types/common.h \
    types/contact.h \
    types/dice.h \
    types/document.h \
    types/encryptedcredentials.h \
    types/encryptedpassportelement.h \
    types/forcereply.h \
    types/game.h \
    types/inlinekeyboardbutton.h \
    types/inlinekeyboardmarkup.h \
    types/inlinequery.h \
    types/invoice.h \
    types/keyboardbutton.h \
    types/keyboardbuttonpolltype.h \
    types/location.h \
    types/loginurl.h \
    types/maskposition.h \
    types/menubutton.h \
    types/menubuttoncommands.h \
    types/menubuttondefault.h \
    types/menubuttonwebapp.h \
    types/message.h \
    types/messageautodeletetimerchanged.h \
    types/messageentity.h \
    types/orderinfo.h \
    types/passportdata.h \
    types/passportfile.h \
    types/photosize.h \
    types/poll.h \
    types/pollanswer.h \
    types/polloption.h \
    types/precheckoutquery.h \
    types/proximityalerttriggered.h \
    types/replykeyboardmarkup.h \
    types/replykeyboardremove.h \
    types/shippingaddress.h \
    types/shippingquery.h \
    types/sticker.h \
    types/successfulpayment.h \
    types/update.h \
    types/user.h \
    types/venue.h \
    types/video.h \
    types/videonote.h \
    types/voice.h \
    types/voicechatended.h \
    types/voicechatparticipantsinvited.h \
    types/voicechatscheduled.h \
    types/voicechatstarted.h \
    types/webappinfo.h
