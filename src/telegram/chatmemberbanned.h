#ifndef CHATMEMBERBANNED_H
#define CHATMEMBERBANNED_H

#include "chatmember.h"

namespace TelegramApi
{
struct ChatMemberBanned : public ChatMember
{
    typedef QSharedPointer<ChatMemberBanned> Ptr;

    int32_t m_until_date = 0;
};

void readValue(ChatMemberBanned::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // CHATMEMBERBANNED_H
