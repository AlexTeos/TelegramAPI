#ifndef LOCATION_H
#define LOCATION_H

#include "common.h"

namespace TelegramApi
{
struct Location
{
    typedef QSharedPointer<Location> Ptr;

    float   m_longitude              = 0;
    float   m_latitude               = 0;
    float   m_horizontal_accuracy    = 0;
    int32_t m_live_period            = 0;
    int32_t m_heading                = 0;
    int32_t m_proximity_alert_radius = 0;
};

void readValue(Location::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // LOCATION_H
