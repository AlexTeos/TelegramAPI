#include "sticker.h"

namespace Telegram
{
void readJsonObject(Sticker::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = Sticker::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readJsonObject(value->m_file_id, object, "file_id");
        readJsonObject(value->m_file_unique_id, object, "file_unique_id");
        readJsonObject(value->m_width, object, "width");
        readJsonObject(value->m_height, object, "height");
        readJsonObject(value->m_is_animated, object, "is_animated");
        readJsonObject(value->m_is_video, object, "is_video");
        readJsonObject(value->m_thumb, object, "thumb");
        readJsonObject(value->m_emoji, object, "emoji");
        readJsonObject(value->m_set_name, object, "set_name");
        readJsonObject(value->m_mask_position, object, "mask_position");
        readJsonObject(value->m_file_size, object, "file_size");
    }
}
}
