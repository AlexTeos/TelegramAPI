#ifndef LOCATION_H
#define LOCATION_H

#include "common.h"

namespace TelegramApi
{
struct Location
{
    typedef QSharedPointer<Location> Ptr;

    float   m_longitude;
    float   m_latitude;
    float   m_horizontal_accuracy;
    int32_t m_live_period;
    int32_t m_heading;
    int32_t m_proximity_alert_radius;
};

void readValue(Location::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // LOCATION_H
