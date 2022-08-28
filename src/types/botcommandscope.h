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
    BotCommandScope(){};

    virtual bool readJsonObject(const QJsonObject& json, const QString& valueName);

    virtual QJsonObject toJsonValue() = 0;

    friend QJsonObject toJsonValue(const BotCommandScope::Ptr&);
};

}

#endif // BOTCOMMANDSCOPE_H
