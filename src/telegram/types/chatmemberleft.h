#ifndef CHATMEMBERLEFT_H
#define CHATMEMBERLEFT_H

#include "chatmember.h"

namespace Telegram
{
struct ChatMemberLeft : public ChatMember
{
    typedef QSharedPointer<ChatMemberLeft> Ptr;
};

void readJsonObject(ChatMemberLeft::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // CHATMEMBERLEFT_H
