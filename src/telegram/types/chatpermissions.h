#ifndef CHATPERMISSIONS_H
#define CHATPERMISSIONS_H

#include "common.h"

namespace Telegram
{
struct ChatPermissions
{
    typedef QSharedPointer<ChatPermissions> Ptr;

    bool m_can_send_messages         = false;
    bool m_can_send_media_messages   = false;
    bool m_can_send_polls            = false;
    bool m_can_send_other_messages   = false;
    bool m_can_add_web_page_previews = false;
    bool m_can_change_info           = false;
    bool m_can_invite_users          = false;
    bool m_can_pin_messages          = false;
};

void readJsonObject(ChatPermissions::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // CHATPERMISSIONS_H
