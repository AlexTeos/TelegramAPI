#include "videonote.h"

namespace TelegramApi
{
void readValue(VideoNote::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = VideoNote::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readValue(value->m_file_id, object, "file_id");
        readValue(value->m_file_unique_id, object, "file_unique_id");
        readValue(value->m_length, object, "length");
        readValue(value->m_duration, object, "duration");
        readValue(value->m_thumb, object, "thumb");
        readValue(value->m_file_size, object, "file_size");
    }
}
}
