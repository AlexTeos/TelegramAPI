#include "dice.h"

namespace TelegramApi
{
void readValue(Dice::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = Dice::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readValue(value->m_emoji, object, "emoji");
        readValue(value->m_value, object, "value");
    }
}
}
