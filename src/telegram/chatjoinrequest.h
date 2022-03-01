#ifndef CHATJOINREQUEST_H
#define CHATJOINREQUEST_H

#include "chat.h"
#include "chatinvitelink.h"
#include "common.h"
#include "user.h"

namespace TelegramApi
{
struct ChatJoinRequest
{
    typedef QSharedPointer<ChatJoinRequest> Ptr;

    Chat::Ptr           m_chat;
    User::Ptr           m_from;
    int32_t             m_date = 0;
    QString             m_bio;
    ChatInviteLink::Ptr m_invite_link;
};

void readValue(ChatJoinRequest::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // CHATJOINREQUEST_H
