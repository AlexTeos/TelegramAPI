#ifndef INLINEKEYBOARDBUTTON_H
#define INLINEKEYBOARDBUTTON_H

#include "callbackgame.h"
#include "common.h"
#include "loginurl.h"

namespace TelegramApi
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
    bool              m_pay;
};

void readValue(InlineKeyboardButton::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // INLINEKEYBOARDBUTTON_H
