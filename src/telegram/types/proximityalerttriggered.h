#ifndef PROXIMITYALERTTRIGGERED_H
#define PROXIMITYALERTTRIGGERED_H

#include "common.h"
#include "user.h"

namespace TelegramApi
{
struct ProximityAlertTriggered
{
    typedef QSharedPointer<ProximityAlertTriggered> Ptr;

    User::Ptr m_traveler;
    User::Ptr m_watcher;
    qint64    m_distance = 0;
};

void readValue(ProximityAlertTriggered::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // PROXIMITYALERTTRIGGERED_H
