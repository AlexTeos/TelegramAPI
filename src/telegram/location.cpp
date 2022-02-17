#include "location.h"

namespace TelegramApi
{
void readValue(Location::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = Location::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readValue(value->m_longitude, object, "longitude");
        readValue(value->m_latitude, object, "latitude");
        readValue(value->m_horizontal_accuracy, object, "horizontal_accuracy");
        readValue(value->m_live_period, object, "live_period");
        readValue(value->m_heading, object, "heading");
        readValue(value->m_proximity_alert_radius, object, "proximity_alert_radius");
    }
}
}
