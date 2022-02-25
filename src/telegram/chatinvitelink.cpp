#include "chatinvitelink.h"

namespace TelegramApi
{
void readValue(ChatInviteLink::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = ChatInviteLink::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readValue(value->m_invite_link, object, "invite_link");
        readValue(value->m_creator, object, "creator");
        readValue(value->m_creates_join_request, object, "creates_join_request");
        readValue(value->m_is_primary, object, "is_primary");
        readValue(value->m_is_revoked, object, "is_revoked");
        readValue(value->m_name, object, "name");
        readValue(value->m_expire_date, object, "expire_date");
        readValue(value->m_member_limit, object, "member_limit");
        readValue(value->m_pending_join_request_count, object, "pending_join_request_count");
    }
}
}
