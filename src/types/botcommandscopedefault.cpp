#include "botcommandscopedefault.h"

namespace Telegram
{
const QString BotCommandScopeDefault::Type("default");

bool readJsonObject(BotCommandScopeDefault::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = BotCommandScopeDefault::Ptr::create();

        return true;
    }

    return false;
}

QJsonObject toJsonValue(const BotCommandScopeDefault::Ptr& value)
{
    return toJsonValue(value.staticCast<BotCommandScope>());
}
}
