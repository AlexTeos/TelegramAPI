#ifndef CHATMEMBERBANNED_H
#define CHATMEMBERBANNED_H

#include "chatmember.h"

namespace Telegram
{
struct ChatMemberBanned : public ChatMember
{
    typedef QSharedPointer<ChatMemberBanned> Ptr;

    qint64 m_until_date;
};

bool readJsonObject(ChatMemberBanned::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // CHATMEMBERBANNED_H
