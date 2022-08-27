#ifndef BOTCOMMANDSCOPECHAT_H
#define BOTCOMMANDSCOPECHAT_H

#include "botcommandscope.h"

namespace Telegram
{
struct BotCommandScopeChat : public BotCommandScope
{
    using Ptr = QSharedPointer<BotCommandScopeChat>;
    static const QString Type;

    std::variant<qint64, QString> m_chat_id;
};

bool        readJsonObject(BotCommandScopeChat::Ptr& value, const QJsonObject& json, const QString& valueName);
QJsonObject toJsonValue(const BotCommandScopeChat::Ptr& value);
}

#endif // BOTCOMMANDSCOPECHAT_H
