#include "photosize.h"

namespace TelegramApi
{
void readValue(PhotoSize::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = PhotoSize::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readValue(value->m_file_id, object, "file_id");
        readValue(value->m_file_unique_id, object, "file_unique_id");
        readValue(value->m_width, object, "width");
        readValue(value->m_height, object, "height");
        readValue(value->m_file_size, object, "duration");
    }
}
}
