#include "chat.h"

#include "message.h"

namespace Telegram
{
bool readJsonObject(Chat::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = Chat::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readJsonObject(value->m_id, object, "id");
        readJsonObject(value->m_type, object, "type");
        readJsonObject(value->m_title, object, "title");
        readJsonObject(value->m_username, object, "username");
        readJsonObject(value->m_first_name, object, "first_name");
        readJsonObject(value->m_last_name, object, "last_name");
        readJsonObject(value->m_photo, object, "photo");
        readJsonObject(value->m_bio, object, "bio");
        readJsonObject(value->m_has_private_forwards, object, "has_private_forwards");
        readJsonObject(value->m_description, object, "description");
        readJsonObject(value->m_invite_link, object, "invite_link");
        readJsonObject(value->m_pinned_message, object, "pinned_message");
        readJsonObject(value->m_permissions, object, "permissions");
        readJsonObject(value->m_slow_mode_delay, object, "slow_mode_delay");
        readJsonObject(value->m_message_auto_delete_time, object, "message_auto_delete_time");
        readJsonObject(value->m_has_protected_content, object, "has_protected_content");
        readJsonObject(value->m_sticker_set_name, object, "sticker_set_name");
        readJsonObject(value->m_can_set_sticker_set, object, "can_set_sticker_set");
        readJsonObject(value->m_linked_chat_id, object, "linked_chat_id");
        readJsonObject(value->m_location, object, "location");

        return true;
    }

    return false;
}
}
