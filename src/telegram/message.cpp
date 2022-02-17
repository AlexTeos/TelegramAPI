#include "message.h"

namespace TelegramApi
{
void readValue(Message::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = Message::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readValue(value->m_message_id, object, "message_id");
        readValue(value->m_from, object, "from");
    }
}
}
