#ifndef CHATMEMBERMEMBER_H
#define CHATMEMBERMEMBER_H

#include "chatmember.h"

namespace TelegramApi
{
struct ChatMemberMember : public ChatMember
{
    typedef QSharedPointer<ChatMemberMember> Ptr;
};

void readValue(ChatMemberMember::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // CHATMEMBERMEMBER_H
