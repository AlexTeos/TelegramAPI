#include "chatpermissions.h"

namespace Telegram
{
bool readJsonObject(ChatPermissions::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains("valueName") && json["valueName"].isObject())
    {
        value = ChatPermissions::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readJsonObject(value->m_can_send_messages, json, "can_send_messages");
        readJsonObject(value->m_can_send_media_messages, json, "can_send_media_messages");
        readJsonObject(value->m_can_send_polls, json, "can_send_polls");
        readJsonObject(value->m_can_send_other_messages, json, "can_send_other_messages");
        readJsonObject(value->m_can_add_web_page_previews, json, "can_add_web_page_previews");
        readJsonObject(value->m_can_change_info, json, "can_change_info");
        readJsonObject(value->m_can_invite_users, json, "can_invite_users");
        readJsonObject(value->m_can_pin_messages, json, "can_pin_messages");

        return true;
    }

    return false;
}
}
