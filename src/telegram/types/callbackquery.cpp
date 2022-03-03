#include "callbackquery.h"

namespace TelegramApi
{
void readValue(CallbackQuery::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = CallbackQuery::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readValue(value->m_id, object, "id");
        readValue(value->m_from, object, "from");
        readValue(value->m_message, object, "message");
        readValue(value->m_inline_message_id, object, "inline_message_id");
        readValue(value->m_chat_instance, object, "chat_instance");
        readValue(value->m_data, object, "data");
        readValue(value->m_game_short_name, object, "game_short_name");
    }
}
}
