#include "maskposition.h"

namespace Telegram
{
bool readJsonObject(MaskPosition::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = MaskPosition::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readJsonObject(value->m_point, object, "point");
        readJsonObject(value->m_x_shift, object, "x_shift");
        readJsonObject(value->m_y_shift, object, "y_shift");
        readJsonObject(value->m_scale, object, "scale");

        return true;
    }

    return false;
}
}
