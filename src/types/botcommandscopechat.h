#ifndef BOTCOMMANDSCOPECHAT_H
#define BOTCOMMANDSCOPECHAT_H

#include "botcommandscope.h"

namespace Telegram
{
struct BotCommandScopeChat : public BotCommandScope
{
    using Ptr = QSharedPointer<BotCommandScopeChat>;
    static const QString Type;

    bool readJsonObject(const QJsonObject& json, const QString& valueName);

    std::variant<qint64, QString> m_chat_id;

    friend bool readJsonObject(BotCommandScopeChat::Ptr&, const QJsonObject&, const QString&);

protected:
    virtual QJsonObject toJsonValue();
};

bool readJsonObject(BotCommandScopeChat::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // BOTCOMMANDSCOPECHAT_H
