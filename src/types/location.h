#ifndef LOCATION_H
#define LOCATION_H

#include "common.h"

namespace Telegram
{
struct Location
{
    typedef QSharedPointer<Location> Ptr;

    double                m_longitude;
    double                m_latitude;
    std::optional<double> m_horizontal_accuracy;
    std::optional<qint64> m_live_period;
    std::optional<qint64> m_heading;
    std::optional<qint64> m_proximity_alert_radius;
};

bool readJsonObject(Location::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // LOCATION_H
