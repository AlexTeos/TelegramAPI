#include "botcommandscopeallchatadministrators.h"

namespace Telegram
{
const QString BotCommandScopeAllChatAdministrators::Type("all_chat_administrators");

bool readJsonObject(BotCommandScopeAllChatAdministrators::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = BotCommandScopeAllChatAdministrators::Ptr::create();

        return true;
    }

    return false;
}

QJsonObject toJsonValue(const BotCommandScopeAllChatAdministrators::Ptr& value)
{
    return toJsonValue(value.staticCast<BotCommandScope>());
}
}
