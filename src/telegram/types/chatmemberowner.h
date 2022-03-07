#ifndef CHATMEMBEROWNER_H
#define CHATMEMBEROWNER_H

#include "chatmember.h"

namespace Telegram
{
struct ChatMemberOwner : public ChatMember
{
    typedef QSharedPointer<ChatMemberOwner> Ptr;

    bool    m_is_anonymous = false;
    QString m_custom_title;
};

void readJsonObject(ChatMemberOwner::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // CHATMEMBEROWNER_H
