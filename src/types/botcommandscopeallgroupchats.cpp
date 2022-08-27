#include "botcommandscopeallgroupchats.h"

namespace Telegram
{
const QString BotCommandScopeAllGroupChats::Type("all_group_chats");

bool readJsonObject(BotCommandScopeAllGroupChats::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = BotCommandScopeAllGroupChats::Ptr::create();

        return true;
    }

    return false;
}

QJsonObject toJsonValue(const BotCommandScopeAllGroupChats::Ptr& value)
{
    return toJsonValue(value.staticCast<BotCommandScope>());
}
}
