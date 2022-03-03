#include "animation.h"

namespace TelegramApi
{
void readValue(Animation::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = Animation::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readValue(value->m_file_id, object, "file_id");
        readValue(value->m_file_unique_id, object, "file_unique_id");
        readValue(value->m_width, object, "width");
        readValue(value->m_height, object, "height");
        readValue(value->m_duration, object, "duration");
        readValue(value->m_thumb, object, "thumb");
        readValue(value->m_file_name, object, "file_name");
        readValue(value->m_mime_type, object, "mime_type");
        readValue(value->m_file_size, object, "file_size");
    }
}
}
