#include "audio.h"

namespace TelegramApi
{
void readValue(Audio::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = Audio::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readValue(value->m_file_id, object, "file_id");
        readValue(value->m_file_unique_id, object, "file_unique_id");
        readValue(value->m_duration, object, "duration");
        readValue(value->m_performer, object, "performer");
        readValue(value->m_title, object, "title");
        readValue(value->m_file_name, object, "file_name");
        readValue(value->m_mime_type, object, "mime_type");
        readValue(value->m_file_size, object, "file_size");
        readValue(value->m_thumb, object, "thumb");
    }
}
}
