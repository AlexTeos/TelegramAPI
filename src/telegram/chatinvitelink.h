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
    bool      m_creates_join_request = false;
    bool      m_is_primary           = false;
    bool      m_is_revoked           = false;
    QString   m_name;
    int32_t   m_expire_date                = 0;
    int32_t   m_member_limit               = 0;
    int32_t   m_pending_join_request_count = 0;
};

void readValue(ChatInviteLink::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // CHATINVITELINK_H
