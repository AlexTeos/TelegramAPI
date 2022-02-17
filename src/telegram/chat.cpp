#include "chat.h"

namespace TelegramApi
{
void readValue(Chat::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = Chat::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readValue(value->m_id, object, "id");
        readValue(value->m_type, object, "type");
        readValue(value->m_title, object, "title");
        readValue(value->m_username, object, "username");
        readValue(value->m_first_name, object, "first_name");
        readValue(value->m_last_name, object, "last_name");
        readValue(value->m_photo, object, "photo");
        readValue(value->m_bio, object, "bio");
        readValue(value->m_has_private_forwards, object, "has_private_forwards");
        readValue(value->m_description, object, "description");
        readValue(value->m_invite_link, object, "invite_link");
        readValue(value->m_pinned_message, object, "pinned_message");
        readValue(value->m_permissions, object, "permissions");
        readValue(value->m_slow_mode_delay, object, "slow_mode_delay");
        readValue(value->m_message_auto_delete_time, object, "message_auto_delete_time");
        readValue(value->m_has_protected_content, object, "has_protected_content");
        readValue(value->m_sticker_set_name, object, "sticker_set_name");
        readValue(value->m_can_set_sticker_set, object, "can_set_sticker_set");
        readValue(value->m_linked_chat_id, object, "linked_chat_id");
        readValue(value->m_location, object, "location");
    }
}
}
