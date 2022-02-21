#include "voice.h"

namespace TelegramApi
{
void readValue(Voice::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = Voice::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readValue(value->m_file_id, object, "file_id");
        readValue(value->m_file_unique_id, object, "file_unique_id");
        readValue(value->m_duration, object, "duration");
        readValue(value->m_mime_type, object, "mime_type");
        readValue(value->m_file_size, object, "file_size");
    }
}
}
