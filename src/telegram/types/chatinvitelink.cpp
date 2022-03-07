#include "chatinvitelink.h"

namespace Telegram
{
void readJsonObject(ChatInviteLink::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = ChatInviteLink::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readJsonObject(value->m_invite_link, object, "invite_link");
        readJsonObject(value->m_creator, object, "creator");
        readJsonObject(value->m_creates_join_request, object, "creates_join_request");
        readJsonObject(value->m_is_primary, object, "is_primary");
        readJsonObject(value->m_is_revoked, object, "is_revoked");
        readJsonObject(value->m_name, object, "name");
        readJsonObject(value->m_expire_date, object, "expire_date");
        readJsonObject(value->m_member_limit, object, "member_limit");
        readJsonObject(value->m_pending_join_request_count, object, "pending_join_request_count");
    }
}
}
