#include "maskposition.h"

namespace TelegramApi
{
void readValue(MaskPosition::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = MaskPosition::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readValue(value->m_point, object, "point");
        readValue(value->m_x_shift, object, "x_shift");
        readValue(value->m_y_shift, object, "y_shift");
        readValue(value->m_scale, object, "scale");
    }
}
}
