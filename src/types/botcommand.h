#ifndef BOTCOMMAND_H
#define BOTCOMMAND_H

#include "common.h"

namespace Telegram
{
struct BotCommand
{
    using Ptr = QSharedPointer<BotCommand>;

    QString m_command;
    QString m_description;
};

bool        readJsonObject(BotCommand::Ptr& value, const QJsonObject& json, const QString& valueName);
QJsonObject toJsonValue(const BotCommand::Ptr& value);
}

#endif // BOTCOMMAND_H
