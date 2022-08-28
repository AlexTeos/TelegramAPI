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

    bool readJsonObject(const QJsonObject& json, const QString& valueName);

    friend bool readJsonObject(BotCommandScopeChatMember::Ptr&, const QJsonObject&, const QString&);

protected:
    virtual QJsonObject toJsonValue();
};

bool readJsonObject(BotCommandScopeChatMember::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // BOTCOMMANDSCOPECHATMEMBER_H
