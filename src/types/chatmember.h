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
};

bool readJsonObject(ChatMember::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // CHATMEMBER_H
