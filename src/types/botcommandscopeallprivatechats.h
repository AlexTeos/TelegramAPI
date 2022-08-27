#ifndef BOTCOMMANDSCOPEALLPRIVATECHATS_H
#define BOTCOMMANDSCOPEALLPRIVATECHATS_H

#include "botcommandscope.h"

namespace Telegram
{
struct BotCommandScopeAllPrivateChats : public BotCommandScope
{
    using Ptr = QSharedPointer<BotCommandScopeAllPrivateChats>;
    static const QString Type;
};

bool readJsonObject(BotCommandScopeAllPrivateChats::Ptr& value, const QJsonObject& json, const QString& valueName);
QJsonObject toJsonValue(const BotCommandScopeAllPrivateChats::Ptr& value);
}

#endif // BOTCOMMANDSCOPEALLPRIVATECHATS_H
