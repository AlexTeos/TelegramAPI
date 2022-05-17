#include "location.h"

namespace Telegram
{
bool readJsonObject(Location::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = Location::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readJsonObject(value->m_longitude, object, "longitude");
        readJsonObject(value->m_latitude, object, "latitude");
        readJsonObject(value->m_horizontal_accuracy, object, "horizontal_accuracy");
        readJsonObject(value->m_live_period, object, "live_period");
        readJsonObject(value->m_heading, object, "heading");
        readJsonObject(value->m_proximity_alert_radius, object, "proximity_alert_radius");

        return true;
    }

    return false;
}
}
