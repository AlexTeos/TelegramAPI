#ifndef BOTCOMMANDSCOPEALLCHATADMINISTRATORS_H
#define BOTCOMMANDSCOPEALLCHATADMINISTRATORS_H

#include "botcommandscope.h"

namespace Telegram
{
struct BotCommandScopeAllChatAdministrators : public BotCommandScope
{
    using Ptr = QSharedPointer<BotCommandScopeAllChatAdministrators>;
    static const QString Type;
};

bool        readJsonObject(BotCommandScopeAllChatAdministrators::Ptr& value,
                           const QJsonObject&                         json,
                           const QString&                             valueName);
QJsonObject toJsonValue(const BotCommandScopeAllChatAdministrators::Ptr& value);
}

#endif // BOTCOMMANDSCOPEALLCHATADMINISTRATORS_H
