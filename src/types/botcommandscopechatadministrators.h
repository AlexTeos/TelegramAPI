#ifndef BOTCOMMANDSCOPECHATADMINISTRATORS_H
#define BOTCOMMANDSCOPECHATADMINISTRATORS_H

#include "botcommandscope.h"

namespace Telegram
{
struct BotCommandScopeChatAdministrators : public BotCommandScope
{
    using Ptr = QSharedPointer<BotCommandScopeChatAdministrators>;
    static const QString Type;

    std::variant<qint64, QString> m_chat_id;
};

bool readJsonObject(BotCommandScopeChatAdministrators::Ptr& value, const QJsonObject& json, const QString& valueName);
QJsonObject toJsonValue(const BotCommandScopeChatAdministrators::Ptr& value);
}

#endif // BOTCOMMANDSCOPECHATADMINISTRATORS_H
