#ifndef CHATINVITELINK_H
#define CHATINVITELINK_H

#include "user.h"

namespace Telegram
{
struct ChatInviteLink
{
    using Ptr = QSharedPointer<ChatInviteLink>;

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

bool readJsonObject(ChatInviteLink::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // CHATINVITELINK_H
