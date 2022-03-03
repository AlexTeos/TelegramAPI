#include "chatmemberadministrator.h"

namespace TelegramApi
{
void readValue(ChatMemberAdministrator::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = ChatMemberAdministrator::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readValue(value->m_can_be_edited, object, "can_be_edited");
        readValue(value->m_is_anonymous, object, "is_anonymous");
        readValue(value->m_can_manage_chat, object, "can_manage_chat");
        readValue(value->m_can_delete_messages, object, "can_delete_messages");
        readValue(value->m_can_manage_voice_chats, object, "can_manage_voice_chats");
        readValue(value->m_can_restrict_members, object, "can_restrict_members");
        readValue(value->m_can_promote_members, object, "can_promote_members");
        readValue(value->m_can_change_info, object, "can_change_info");
        readValue(value->m_can_invite_users, object, "can_invite_users");
        readValue(value->m_can_post_messages, object, "can_post_messages");
        readValue(value->m_can_edit_messages, object, "can_edit_messages");
        readValue(value->m_can_pin_messages, object, "can_pin_messages");
        readValue(value->m_custom_title, object, "custom_title");
    }
}
}
