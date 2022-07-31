#ifndef CHATPERMISSIONS_H
#define CHATPERMISSIONS_H

#include "common.h"

namespace Telegram
{
struct ChatPermissions
{
    typedef QSharedPointer<ChatPermissions> Ptr;

    std::optional<bool> m_can_send_messages;
    std::optional<bool> m_can_send_media_messages;
    std::optional<bool> m_can_send_polls;
    std::optional<bool> m_can_send_other_messages;
    std::optional<bool> m_can_add_web_page_previews;
    std::optional<bool> m_can_change_info;
    std::optional<bool> m_can_invite_users;
    std::optional<bool> m_can_pin_messages;
};

bool readJsonObject(ChatPermissions::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // CHATPERMISSIONS_H
