#ifndef CHATMEMBEROWNER_H
#define CHATMEMBEROWNER_H

#include "chatmember.h"

namespace Telegram
{
struct ChatMemberOwner : public ChatMember
{
    using Ptr = QSharedPointer<ChatMemberOwner>;
    static const QString Status;

    bool readJsonObject(const QJsonObject& json, const QString& valueName);

    bool                   m_is_anonymous;
    std::optional<QString> m_custom_title;

    friend bool readJsonObject(ChatMemberOwner::Ptr&, const QJsonObject&, const QString&);

protected:
    virtual QJsonObject toJsonValue();
};

bool readJsonObject(ChatMemberOwner::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // CHATMEMBEROWNER_H
