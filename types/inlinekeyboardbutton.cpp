#include "inlinekeyboardbutton.h"

namespace Telegram
{
bool readJsonObject(InlineKeyboardButton::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = InlineKeyboardButton::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readJsonObject(value->m_text, object, "text");
        readJsonObject(value->m_url, object, "url");
        readJsonObject(value->m_login_url, object, "login_url");
        readJsonObject(value->m_callback_data, object, "callback_data");
        readJsonObject(value->m_switch_inline_query, object, "switch_inline_query");
        readJsonObject(value->m_switch_inline_query_current_chat, object, "switch_inline_query_current_chat");
        readJsonObject(value->m_callback_game, object, "callback_game");
        readJsonObject(value->m_pay, object, "pay");

        return true;
    }
}

QJsonValue toJsonValue(const InlineKeyboardButton::Ptr& value)
{
    QJsonObject jsonObject;

    jsonObject.insert("text", value->m_text);
    if (value->m_url) jsonObject.insert("url", value->m_url.value());
    if (value->m_login_url) jsonObject.insert("login_url", toJsonValue(value->m_login_url));
    if (value->m_callback_data) jsonObject.insert("callback_data", value->m_callback_data.value());
    if (value->m_switch_inline_query) jsonObject.insert("switch_inline_query", value->m_switch_inline_query.value());
    if (value->m_switch_inline_query_current_chat)
        jsonObject.insert("switch_inline_query_current_chat", value->m_switch_inline_query_current_chat.value());
    if (value->m_callback_game) jsonObject.insert("callback_game", toJsonValue(value->m_callback_game));
    if (value->m_pay) jsonObject.insert("pay", value->m_pay.value());

    return jsonObject;
}
}
