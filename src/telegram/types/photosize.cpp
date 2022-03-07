#include "photosize.h"

namespace Telegram
{
void readJsonObject(PhotoSize::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = PhotoSize::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readJsonObject(value->m_file_id, object, "file_id");
        readJsonObject(value->m_file_unique_id, object, "file_unique_id");
        readJsonObject(value->m_width, object, "width");
        readJsonObject(value->m_height, object, "height");
        readJsonObject(value->m_file_size, object, "duration");
    }
}
}
