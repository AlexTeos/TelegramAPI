#include "botcommandscopedefault.h"

namespace Telegram
{
const QString BotCommandScopeDefault::Type("default");

QJsonObject BotCommandScopeDefault::toJsonValue()
{
    return BotCommandScope::toJsonValue();
}

bool BotCommandScopeDefault::readJsonObject(const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        BotCommandScope::readJsonObject(json, valueName);

        return true;
    }

    return false;
}

bool readJsonObject(BotCommandScopeDefault::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    value = BotCommandScopeDefault::Ptr::create();

    return value->readJsonObject(json, valueName);
}
}
