#ifndef CHATINVITELINK_H
#define CHATINVITELINK_H

#include "common.h"
#include "user.h"

namespace TelegramApi
{
struct ChatInviteLink
{
    typedef QSharedPointer<ChatInviteLink> Ptr;

    QString   m_invite_link;
    User::Ptr m_creator;
    bool      m_creates_join_request;
    bool      m_is_primary;
    bool      m_is_revoked;
    QString   m_name;
    int32_t   m_expire_date;
    int32_t   m_member_limit;
    int32_t   m_pending_join_request_count;
};

void readValue(ChatInviteLink::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // CHATINVITELINK_H
