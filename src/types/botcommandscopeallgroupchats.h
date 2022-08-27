#ifndef BOTCOMMANDSCOPEALLGROUPCHATS_H
#define BOTCOMMANDSCOPEALLGROUPCHATS_H

#include "botcommandscope.h"

namespace Telegram
{
struct BotCommandScopeAllGroupChats : public BotCommandScope
{
    using Ptr = QSharedPointer<BotCommandScopeAllGroupChats>;
    static const QString Type;
};

bool        readJsonObject(BotCommandScopeAllGroupChats::Ptr& value, const QJsonObject& json, const QString& valueName);
QJsonObject toJsonValue(const BotCommandScopeAllGroupChats::Ptr& value);
}

#endif // BOTCOMMANDSCOPEALLGROUPCHATS_H
