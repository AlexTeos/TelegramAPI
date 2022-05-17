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

    QString                m_text;
    std::optional<QString> m_url;
    LoginUrl::Ptr          m_login_url;
    std::optional<QString> m_callback_data;
    std::optional<QString> m_switch_inline_query;
    std::optional<QString> m_switch_inline_query_current_chat;
    CallbackGame::Ptr      m_callback_game;
    std::optional<bool>    m_pay;
};

bool       readJsonObject(InlineKeyboardButton::Ptr& value, const QJsonObject& json, const QString& valueName);
QJsonValue toJsonValue(const InlineKeyboardButton::Ptr& value);
}

#endif // INLINEKEYBOARDBUTTON_H
