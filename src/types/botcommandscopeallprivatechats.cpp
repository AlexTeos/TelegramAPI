#include "botcommandscopeallprivatechats.h"

namespace Telegram
{
const QString BotCommandScopeAllPrivateChats::Type("all_private_chats");

bool readJsonObject(BotCommandScopeAllPrivateChats::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = BotCommandScopeAllPrivateChats::Ptr::create();

        return true;
    }

    return false;
}

QJsonObject toJsonValue(const BotCommandScopeAllPrivateChats::Ptr& value)
{
    return toJsonValue(value.staticCast<BotCommandScope>());
}
}
