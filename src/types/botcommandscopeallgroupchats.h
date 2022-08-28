#ifndef BOTCOMMANDSCOPEALLGROUPCHATS_H
#define BOTCOMMANDSCOPEALLGROUPCHATS_H

#include "botcommandscope.h"

namespace Telegram
{
struct BotCommandScopeAllGroupChats : public BotCommandScope
{
    using Ptr = QSharedPointer<BotCommandScopeAllGroupChats>;
    static const QString Type;

    friend bool readJsonObject(BotCommandScopeAllGroupChats::Ptr&, const QJsonObject&, const QString&);

protected:
    virtual QJsonObject toJsonValue();
};

bool readJsonObject(BotCommandScopeAllGroupChats::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // BOTCOMMANDSCOPEALLGROUPCHATS_H
