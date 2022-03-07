#include "chatmemberrestricted.h"

namespace Telegram
{
void readJsonObject(ChatMemberRestricted::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = ChatMemberRestricted::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readJsonObject(value->m_is_member, object, "is_member");
        readJsonObject(value->m_can_change_info, object, "can_change_info");
        readJsonObject(value->m_can_invite_users, object, "can_invite_users");
        readJsonObject(value->m_can_pin_messages, object, "can_pin_messages");
        readJsonObject(value->m_can_send_messages, object, "can_send_messages");
        readJsonObject(value->m_can_send_media_messages, object, "can_send_media_messages");
        readJsonObject(value->m_can_send_polls, object, "can_send_polls");
        readJsonObject(value->m_can_send_other_messages, object, "can_send_other_messages");
        readJsonObject(value->m_can_add_web_page_previews, object, "can_add_web_page_previews");
        readJsonObject(value->m_until_date, object, "until_date");
    }
}
}
