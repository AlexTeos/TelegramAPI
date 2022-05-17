#ifndef CHATMEMBERMEMBER_H
#define CHATMEMBERMEMBER_H

#include "chatmember.h"

namespace Telegram
{
struct ChatMemberMember : public ChatMember
{
    typedef QSharedPointer<ChatMemberMember> Ptr;
};

bool readJsonObject(ChatMemberMember::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // CHATMEMBERMEMBER_H
