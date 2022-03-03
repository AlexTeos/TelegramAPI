#include "inlinekeyboardbutton.h"

namespace TelegramApi
{
void readValue(InlineKeyboardButton::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = InlineKeyboardButton::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readValue(value->m_text, object, "text");
        readValue(value->m_url, object, "url");
        readValue(value->m_login_url, object, "login_url");
        readValue(value->m_callback_data, object, "callback_data");
        readValue(value->m_switch_inline_query, object, "switch_inline_query");
        readValue(value->m_switch_inline_query_current_chat, object, "switch_inline_query_current_chat");
        readValue(value->m_callback_game, object, "callback_game");
        readValue(value->m_pay, object, "pay");
    }
}
}
