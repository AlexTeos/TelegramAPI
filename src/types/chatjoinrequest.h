#ifndef CHATJOINREQUEST_H
#define CHATJOINREQUEST_H

#include "chat.h"
#include "chatinvitelink.h"
#include "user.h"

namespace Telegram
{
struct ChatJoinRequest
{
    using Ptr = QSharedPointer<ChatJoinRequest>;

    Chat::Ptr              m_chat;
    User::Ptr              m_from;
    qint64                 m_date;
    std::optional<QString> m_bio;
    ChatInviteLink::Ptr    m_invite_link;
};

bool readJsonObject(ChatJoinRequest::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // CHATJOINREQUEST_H
