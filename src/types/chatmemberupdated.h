#ifndef CHATMEMBERUPDATED_H
#define CHATMEMBERUPDATED_H

#include "chat.h"
#include "chatinvitelink.h"
#include "chatmember.h"
#include "common.h"
#include "user.h"

namespace Telegram
{
struct ChatMemberUpdated
{
    using Ptr = QSharedPointer<ChatMemberUpdated>;

    Chat::Ptr           m_chat;
    User::Ptr           m_from;
    qint64              m_date;
    ChatMember::Ptr     m_old_chat_member;
    ChatMember::Ptr     m_new_chat_member;
    ChatInviteLink::Ptr m_invite_link;
};

bool readJsonObject(ChatMemberUpdated::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // CHATMEMBERUPDATED_H
