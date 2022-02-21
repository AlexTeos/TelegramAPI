#include "proximityalerttriggered.h"

namespace TelegramApi
{
void readValue(ProximityAlertTriggered::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = ProximityAlertTriggered::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readValue(value->m_traveler, object, "traveler");
        readValue(value->m_watcher, object, "watcher");
        readValue(value->m_distance, object, "distance");
    }
}
}
