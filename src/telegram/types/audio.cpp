#include "audio.h"

namespace Telegram
{
void readJsonObject(Audio::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = Audio::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readJsonObject(value->m_file_id, object, "file_id");
        readJsonObject(value->m_file_unique_id, object, "file_unique_id");
        readJsonObject(value->m_duration, object, "duration");
        readJsonObject(value->m_performer, object, "performer");
        readJsonObject(value->m_title, object, "title");
        readJsonObject(value->m_file_name, object, "file_name");
        readJsonObject(value->m_mime_type, object, "mime_type");
        readJsonObject(value->m_file_size, object, "file_size");
        readJsonObject(value->m_thumb, object, "thumb");
    }
}
}
