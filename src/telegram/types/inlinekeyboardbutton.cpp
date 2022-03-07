#include "inlinekeyboardbutton.h"

namespace Telegram
{
void readJsonObject(InlineKeyboardButton::Ptr& value, const QJsonObject& json, const QString& valueName)
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
    }
}

QJsonValue toJsonValue(const InlineKeyboardButton::Ptr& value)
{
    QJsonObject jsonObject;

    jsonObject.insert("text", value->m_text);
    jsonObject.insert("url", value->m_url);
    jsonObject.insert("login_url", toJsonValue(value->m_login_url));
    jsonObject.insert("callback_data", value->m_callback_data);
    jsonObject.insert("switch_inline_query", value->m_switch_inline_query);
    jsonObject.insert("switch_inline_query_current_chat", value->m_switch_inline_query_current_chat);
    jsonObject.insert("callback_game", toJsonValue(value->m_callback_game));
    jsonObject.insert("pay", value->m_pay);

    return jsonObject;
}
}
