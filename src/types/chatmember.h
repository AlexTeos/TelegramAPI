#ifndef CHATMEMBER_H
#define CHATMEMBER_H

#include "user.h"

namespace Telegram
{
struct ChatMember
{
    using Ptr = QSharedPointer<ChatMember>;

    QString   m_status;
    User::Ptr m_user;

protected:
    virtual bool        readJsonObject(const QJsonObject& json, const QString& valueName);
    virtual QJsonObject toJsonValue();

    friend bool        readJsonObject(ChatMember::Ptr&, const QJsonObject&, const QString&);
    friend QJsonObject toJsonValue(const ChatMember::Ptr&);
};

bool readJsonObject(ChatMember::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // CHATMEMBER_H
