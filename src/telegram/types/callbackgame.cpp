#include "callbackgame.h"

namespace TelegramApi
{
void readValue(CallbackGame::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = CallbackGame::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readValue(value->m_user_id, object, "user_id");
        readValue(value->m_score, object, "score");
        readValue(value->m_force, object, "force");
        readValue(value->m_disable_edit_message, object, "disable_edit_message");
        readValue(value->m_chat_id, object, "chat_id");
        readValue(value->m_message_id, object, "message_id");
        readValue(value->m_inline_message_id, object, "inline_message_id");
    }
}
}
