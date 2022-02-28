#ifndef CHATMEMBERLEFT_H
#define CHATMEMBERLEFT_H

#include "chatmember.h"

namespace TelegramApi
{
struct ChatMemberLeft : public ChatMember
{
    typedef QSharedPointer<ChatMemberLeft> Ptr;
};

void readValue(ChatMemberLeft::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // CHATMEMBERLEFT_H
