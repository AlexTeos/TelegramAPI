#include "callbackquery.h"

namespace Telegram
{
void readJsonObject(CallbackQuery::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = CallbackQuery::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readJsonObject(value->m_id, object, "id");
        readJsonObject(value->m_from, object, "from");
        readJsonObject(value->m_message, object, "message");
        readJsonObject(value->m_inline_message_id, object, "inline_message_id");
        readJsonObject(value->m_chat_instance, object, "chat_instance");
        readJsonObject(value->m_data, object, "data");
        readJsonObject(value->m_game_short_name, object, "game_short_name");
    }
}
}
