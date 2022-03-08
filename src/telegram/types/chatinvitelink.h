#ifndef CHATINVITELINK_H
#define CHATINVITELINK_H

#include "common.h"
#include "user.h"

namespace Telegram
{
struct ChatInviteLink
{
    typedef QSharedPointer<ChatInviteLink> Ptr;

    QString                m_invite_link;
    User::Ptr              m_creator;
    bool                   m_creates_join_request;
    bool                   m_is_primary;
    bool                   m_is_revoked;
    std::optional<QString> m_name;
    std::optional<qint64>  m_expire_date;
    std::optional<qint64>  m_member_limit;
    std::optional<qint64>  m_pending_join_request_count;
};

void readJsonObject(ChatInviteLink::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // CHATINVITELINK_H
