#ifndef BOTCOMMANDSCOPE_H
#define BOTCOMMANDSCOPE_H

#include "common.h"

namespace Telegram
{
struct BotCommandScope
{
    using Ptr = QSharedPointer<BotCommandScope>;

    QString m_type;

protected:
    virtual bool        readJsonObject(const QJsonObject& json, const QString& valueName);
    virtual QJsonObject toJsonValue();

    friend bool        readJsonObject(BotCommandScope::Ptr&, const QJsonObject&, const QString&);
    friend QJsonObject toJsonValue(const BotCommandScope::Ptr&);
};

bool readJsonObject(BotCommandScope::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // BOTCOMMANDSCOPE_H
