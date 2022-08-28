#include "botcommandscopeallchatadministrators.h"

namespace Telegram
{
const QString BotCommandScopeAllChatAdministrators::Type("all_chat_administrators");

QJsonObject BotCommandScopeAllChatAdministrators::toJsonValue()
{
    return BotCommandScope::toJsonValue();
}

bool readJsonObject(BotCommandScopeAllChatAdministrators::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    value = BotCommandScopeAllChatAdministrators::Ptr::create();

    return value->readJsonObject(json, valueName);
}
}
