#ifndef BOTCOMMANDSCOPEDEFAULT_H
#define BOTCOMMANDSCOPEDEFAULT_H

#include "botcommandscope.h"

namespace Telegram
{
struct BotCommandScopeDefault : public BotCommandScope
{
    using Ptr = QSharedPointer<BotCommandScopeDefault>;
    static const QString Type;

    bool readJsonObject(const QJsonObject& json, const QString& valueName);

    friend bool readJsonObject(BotCommandScopeDefault::Ptr&, const QJsonObject&, const QString&);

protected:
    virtual QJsonObject toJsonValue();
};

bool readJsonObject(BotCommandScopeDefault::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // BOTCOMMANDSCOPEDEFAULT_H
