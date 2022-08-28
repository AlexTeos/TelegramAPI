#ifndef BOTCOMMANDSCOPEALLPRIVATECHATS_H
#define BOTCOMMANDSCOPEALLPRIVATECHATS_H

#include "botcommandscope.h"

namespace Telegram
{
struct BotCommandScopeAllPrivateChats : public BotCommandScope
{
    using Ptr = QSharedPointer<BotCommandScopeAllPrivateChats>;
    static const QString Type;

    friend bool readJsonObject(BotCommandScopeAllPrivateChats::Ptr&, const QJsonObject&, const QString&);

protected:
    virtual QJsonObject toJsonValue();
};

bool readJsonObject(BotCommandScopeAllPrivateChats::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // BOTCOMMANDSCOPEALLPRIVATECHATS_H
