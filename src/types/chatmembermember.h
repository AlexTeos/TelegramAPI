#ifndef CHATMEMBERMEMBER_H
#define CHATMEMBERMEMBER_H

#include "chatmember.h"

namespace Telegram
{
struct ChatMemberMember : public ChatMember
{
    using Ptr = QSharedPointer<ChatMemberMember>;
    static const QString Status;

    bool readJsonObject(const QJsonObject& json, const QString& valueName);

    friend bool readJsonObject(ChatMemberMember::Ptr&, const QJsonObject&, const QString&);

protected:
    virtual QJsonObject toJsonValue();
};

bool readJsonObject(ChatMemberMember::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // CHATMEMBERMEMBER_H
