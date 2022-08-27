#include "chatmemberadministrator.h"

namespace Telegram
{
const QString ChatMemberAdministrator::Type("administrator");

bool readJsonObject(ChatMemberAdministrator::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = ChatMemberAdministrator::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readJsonObject(value->m_can_be_edited, object, "can_be_edited");
        readJsonObject(value->m_is_anonymous, object, "is_anonymous");
        readJsonObject(value->m_can_manage_chat, object, "can_manage_chat");
        readJsonObject(value->m_can_delete_messages, object, "can_delete_messages");
        readJsonObject(value->m_can_manage_voice_chats, object, "can_manage_voice_chats");
        readJsonObject(value->m_can_restrict_members, object, "can_restrict_members");
        readJsonObject(value->m_can_promote_members, object, "can_promote_members");
        readJsonObject(value->m_can_change_info, object, "can_change_info");
        readJsonObject(value->m_can_invite_users, object, "can_invite_users");
        readJsonObject(value->m_can_post_messages, object, "can_post_messages");
        readJsonObject(value->m_can_edit_messages, object, "can_edit_messages");
        readJsonObject(value->m_can_pin_messages, object, "can_pin_messages");
        readJsonObject(value->m_custom_title, object, "custom_title");

        return true;
    }

    return false;
}
}
