#include "dice.h"

namespace Telegram
{
void readJsonObject(Dice::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = Dice::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readJsonObject(value->m_emoji, object, "emoji");
        readJsonObject(value->m_value, object, "value");
    }
}
}
