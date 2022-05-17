#include "callbackgame.h"

namespace Telegram
{
bool readJsonObject(CallbackGame::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = CallbackGame::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readJsonObject(value->m_user_id, object, "user_id");
        readJsonObject(value->m_score, object, "score");
        readJsonObject(value->m_force, object, "force");
        readJsonObject(value->m_disable_edit_message, object, "disable_edit_message");
        readJsonObject(value->m_chat_id, object, "chat_id");
        readJsonObject(value->m_message_id, object, "message_id");
        readJsonObject(value->m_inline_message_id, object, "inline_message_id");

        return true;
    }

    return false;
}

QJsonValue toJsonValue(const CallbackGame::Ptr& value)
{
    QJsonObject jsonObject;

    jsonObject.insert("user_id", value->m_user_id);
    jsonObject.insert("score", value->m_score);
    if (value->m_force) jsonObject.insert("force", value->m_force.value());
    if (value->m_disable_edit_message) jsonObject.insert("disable_edit_message", value->m_disable_edit_message.value());
    if (value->m_chat_id) jsonObject.insert("chat_id", value->m_chat_id.value());
    if (value->m_message_id) jsonObject.insert("message_id", value->m_message_id.value());
    if (value->m_inline_message_id) jsonObject.insert("inline_message_id", value->m_inline_message_id.value());

    return jsonObject;
}
}
