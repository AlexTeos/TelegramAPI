#ifndef INLINEKEYBOARDBUTTON_H
#define INLINEKEYBOARDBUTTON_H

#include "callbackgame.h"
#include "common.h"
#include "loginurl.h"

namespace Telegram
{
struct InlineKeyboardButton
{
    typedef QSharedPointer<InlineKeyboardButton> Ptr;

    QString           m_text;
    QString           m_url;
    LoginUrl::Ptr     m_login_url;
    QString           m_callback_data;
    QString           m_switch_inline_query;
    QString           m_switch_inline_query_current_chat;
    CallbackGame::Ptr m_callback_game;
    bool              m_pay = false;
};

void       readJsonObject(InlineKeyboardButton::Ptr& value, const QJsonObject& json, const QString& valueName);
QJsonValue toJsonValue(const InlineKeyboardButton::Ptr& value);
}

#endif // INLINEKEYBOARDBUTTON_H
