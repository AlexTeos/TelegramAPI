#ifndef CHATPERMISSIONS_H
#define CHATPERMISSIONS_H

#include "common.h"

namespace TelegramApi
{
struct ChatPermissions
{
    typedef QSharedPointer<ChatPermissions> Ptr;

    bool m_can_send_messages;
    bool m_can_send_media_messages;
    bool m_can_send_polls;
    bool m_can_send_other_messages;
    bool m_can_add_web_page_previews;
    bool m_can_change_info;
    bool m_can_invite_users;
    bool m_can_pin_messages;
};

void readValue(ChatPermissions::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // CHATPERMISSIONS_H
