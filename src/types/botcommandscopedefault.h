#ifndef BOTCOMMANDSCOPEDEFAULT_H
#define BOTCOMMANDSCOPEDEFAULT_H

#include "botcommandscope.h"

namespace Telegram
{
struct BotCommandScopeDefault : public BotCommandScope
{
    using Ptr = QSharedPointer<BotCommandScopeDefault>;
    static const QString Type;
};

bool        readJsonObject(BotCommandScopeDefault::Ptr& value, const QJsonObject& json, const QString& valueName);
QJsonObject toJsonValue(const BotCommandScopeDefault::Ptr& value);
}

#endif // BOTCOMMANDSCOPEDEFAULT_H
