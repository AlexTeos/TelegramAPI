#ifndef BOTCOMMANDSCOPEALLCHATADMINISTRATORS_H
#define BOTCOMMANDSCOPEALLCHATADMINISTRATORS_H

#include "botcommandscope.h"

namespace Telegram
{
struct BotCommandScopeAllChatAdministrators : public BotCommandScope
{
    using Ptr = QSharedPointer<BotCommandScopeAllChatAdministrators>;
    static const QString Type;

    friend bool readJsonObject(BotCommandScopeAllChatAdministrators::Ptr&, const QJsonObject&, const QString&);

    QJsonObject toJsonValue();
};

bool readJsonObject(BotCommandScopeAllChatAdministrators::Ptr& value,
                    const QJsonObject&                         json,
                    const QString&                             valueName);
}

#endif // BOTCOMMANDSCOPEALLCHATADMINISTRATORS_H
