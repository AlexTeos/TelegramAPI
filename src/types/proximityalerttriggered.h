#ifndef PROXIMITYALERTTRIGGERED_H
#define PROXIMITYALERTTRIGGERED_H

#include "common.h"
#include "user.h"

namespace Telegram
{
struct ProximityAlertTriggered
{
    typedef QSharedPointer<ProximityAlertTriggered> Ptr;

    User::Ptr m_traveler;
    User::Ptr m_watcher;
    qint64    m_distance;
};

bool readJsonObject(ProximityAlertTriggered::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // PROXIMITYALERTTRIGGERED_H
