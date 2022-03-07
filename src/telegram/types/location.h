#ifndef LOCATION_H
#define LOCATION_H

#include "common.h"

namespace Telegram
{
struct Location
{
    typedef QSharedPointer<Location> Ptr;

    double m_longitude              = 0;
    double m_latitude               = 0;
    double m_horizontal_accuracy    = 0;
    qint64 m_live_period            = 0;
    qint64 m_heading                = 0;
    qint64 m_proximity_alert_radius = 0;
};

void readJsonObject(Location::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // LOCATION_H
