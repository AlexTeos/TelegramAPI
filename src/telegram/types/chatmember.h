#ifndef CHATMEMBER_H
#define CHATMEMBER_H

#include "common.h"
#include "user.h"

namespace Telegram
{
struct ChatMember
{
    typedef QSharedPointer<ChatMember> Ptr;

    QString   m_status;
    User::Ptr m_user;
};

void readJsonObject(ChatMember::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // CHATMEMBER_H
