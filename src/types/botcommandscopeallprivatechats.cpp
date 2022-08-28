#include "botcommandscopeallprivatechats.h"

namespace Telegram
{
const QString BotCommandScopeAllPrivateChats::Type("all_private_chats");

QJsonObject BotCommandScopeAllPrivateChats::toJsonValue()
{
    return BotCommandScope::toJsonValue();
}

bool readJsonObject(BotCommandScopeAllPrivateChats::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    value = BotCommandScopeAllPrivateChats::Ptr::create();

    return value->readJsonObject(json, valueName);
}
}
