#include "proximityalerttriggered.h"

namespace Telegram
{
void readJsonObject(ProximityAlertTriggered::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = ProximityAlertTriggered::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readJsonObject(value->m_traveler, object, "traveler");
        readJsonObject(value->m_watcher, object, "watcher");
        readJsonObject(value->m_distance, object, "distance");
    }
}
}
