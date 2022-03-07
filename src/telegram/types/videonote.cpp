#include "videonote.h"

namespace Telegram
{
void readJsonObject(VideoNote::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = VideoNote::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readJsonObject(value->m_file_id, object, "file_id");
        readJsonObject(value->m_file_unique_id, object, "file_unique_id");
        readJsonObject(value->m_length, object, "length");
        readJsonObject(value->m_duration, object, "duration");
        readJsonObject(value->m_thumb, object, "thumb");
        readJsonObject(value->m_file_size, object, "file_size");
    }
}
}
