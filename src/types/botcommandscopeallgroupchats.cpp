#include "botcommandscopeallgroupchats.h"

namespace Telegram
{
const QString BotCommandScopeAllGroupChats::Type("all_group_chats");

QJsonObject BotCommandScopeAllGroupChats::toJsonValue()
{
    return BotCommandScope::toJsonValue();
}

bool readJsonObject(BotCommandScopeAllGroupChats::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    value = BotCommandScopeAllGroupChats::Ptr::create();

    return value->readJsonObject(json, valueName);
}

}
