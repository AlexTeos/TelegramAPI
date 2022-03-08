#include "messageentity.h"

namespace Telegram
{
void readJsonObject(MessageEntity::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = MessageEntity::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readJsonObject(value->m_type, object, "type");
        readJsonObject(value->m_offset, object, "offset");
        readJsonObject(value->m_length, object, "length");
        readJsonObject(value->m_url, object, "url");
        readJsonObject(value->m_user, object, "user");
        readJsonObject(value->m_language, object, "language");
    }
}

QJsonValue toJsonValue(const MessageEntity::Ptr& value)
{
    QJsonObject jsonObject;

    jsonObject.insert("type", value->m_type);
    jsonObject.insert("offset", value->m_offset);
    jsonObject.insert("length", value->m_length);
    if (value->m_url) jsonObject.insert("url", value->m_url.value());
    if (value->m_user) jsonObject.insert("user", toJsonValue(value->m_user));
    if (value->m_language) jsonObject.insert("language", value->m_language.value());

    return jsonObject;
}
}
