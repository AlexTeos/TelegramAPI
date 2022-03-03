#include "chatmemberrestricted.h"

namespace TelegramApi
{
void readValue(ChatMemberRestricted::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = ChatMemberRestricted::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readValue(value->m_is_member, object, "is_member");
        readValue(value->m_can_change_info, object, "can_change_info");
        readValue(value->m_can_invite_users, object, "can_invite_users");
        readValue(value->m_can_pin_messages, object, "can_pin_messages");
        readValue(value->m_can_send_messages, object, "can_send_messages");
        readValue(value->m_can_send_media_messages, object, "can_send_media_messages");
        readValue(value->m_can_send_polls, object, "can_send_polls");
        readValue(value->m_can_send_other_messages, object, "can_send_other_messages");
        readValue(value->m_can_add_web_page_previews, object, "can_add_web_page_previews");
        readValue(value->m_until_date, object, "until_date");
    }
}
}
