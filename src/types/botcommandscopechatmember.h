#ifndef BOTCOMMANDSCOPECHATMEMBER_H
#define BOTCOMMANDSCOPECHATMEMBER_H

#include "botcommandscope.h"

namespace Telegram
{
struct BotCommandScopeChatMember : public BotCommandScope
{
    using Ptr = QSharedPointer<BotCommandScopeChatMember>;
    static const QString Type;

    std::variant<qint64, QString> m_chat_id;
    qint64                        m_user_id;
};

bool        readJsonObject(BotCommandScopeChatMember::Ptr& value, const QJsonObject& json, const QString& valueName);
QJsonObject toJsonValue(const BotCommandScopeChatMember::Ptr& value);
}

#endif // BOTCOMMANDSCOPECHATMEMBER_H
