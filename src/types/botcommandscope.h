#ifndef BOTCOMMANDSCOPE_H
#define BOTCOMMANDSCOPE_H

#include "common.h"

namespace Telegram
{
struct BotCommandScope
{
    using Ptr = QSharedPointer<BotCommandScope>;

    QString m_type;
};

bool        readJsonObject(BotCommandScope::Ptr& value, const QJsonObject& json, const QString& valueName);
QJsonObject toJsonValue(const BotCommandScope::Ptr& value);
}

#endif // BOTCOMMANDSCOPE_H
