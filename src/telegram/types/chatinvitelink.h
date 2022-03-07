#ifndef CHATINVITELINK_H
#define CHATINVITELINK_H

#include "common.h"
#include "user.h"

namespace Telegram
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
    qint64    m_expire_date                = 0;
    qint64    m_member_limit               = 0;
    qint64    m_pending_join_request_count = 0;
};

void readJsonObject(ChatInviteLink::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // CHATINVITELINK_H
