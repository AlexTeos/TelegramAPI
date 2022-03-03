#include "sticker.h"

namespace TelegramApi
{
void readValue(Sticker::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = Sticker::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readValue(value->m_file_id, object, "file_id");
        readValue(value->m_file_unique_id, object, "file_unique_id");
        readValue(value->m_width, object, "width");
        readValue(value->m_height, object, "height");
        readValue(value->m_is_animated, object, "is_animated");
        readValue(value->m_is_video, object, "is_video");
        readValue(value->m_thumb, object, "thumb");
        readValue(value->m_emoji, object, "emoji");
        readValue(value->m_set_name, object, "set_name");
        readValue(value->m_mask_position, object, "mask_position");
        readValue(value->m_file_size, object, "file_size");
    }
}
}
