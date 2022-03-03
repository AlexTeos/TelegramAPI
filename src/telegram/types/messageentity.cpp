#include "messageentity.h"

namespace TelegramApi
{
void readValue(MessageEntity::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = MessageEntity::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readValue(value->m_type, object, "type");
        readValue(value->m_offset, object, "offset");
        readValue(value->m_length, object, "length");
        readValue(value->m_url, object, "url");
        readValue(value->m_user, object, "user");
        readValue(value->m_language, object, "language");
    }
}
}
