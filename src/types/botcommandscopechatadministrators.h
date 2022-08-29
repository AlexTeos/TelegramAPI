#ifndef BOTCOMMANDSCOPECHATADMINISTRATORS_H
#define BOTCOMMANDSCOPECHATADMINISTRATORS_H

#include "botcommandscope.h"

namespace Telegram
{
struct BotCommandScopeChatAdministrators : public BotCommandScope
{
    using Ptr = QSharedPointer<BotCommandScopeChatAdministrators>;
    static const QString Type;

    bool readJsonObject(const QJsonObject& json, const QString& valueName);

    std::variant<qint64, QString> m_chat_id;

    friend bool readJsonObject(BotCommandScopeChatAdministrators::Ptr&, const QJsonObject&, const QString&);

protected:
    virtual QJsonObject toJsonValue();
};

bool readJsonObject(BotCommandScopeChatAdministrators::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // BOTCOMMANDSCOPECHATADMINISTRATORS_H
