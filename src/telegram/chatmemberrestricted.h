#ifndef CHATMEMBERRESTRICTED_H
#define CHATMEMBERRESTRICTED_H

#include "chatmember.h"

namespace TelegramApi
{
struct ChatMemberRestricted : public ChatMember
{
    typedef QSharedPointer<ChatMemberRestricted> Ptr;

    bool    m_is_member                 = false;
    bool    m_can_change_info           = false;
    bool    m_can_invite_users          = false;
    bool    m_can_pin_messages          = false;
    bool    m_can_send_messages         = false;
    bool    m_can_send_media_messages   = false;
    bool    m_can_send_polls            = false;
    bool    m_can_send_other_messages   = false;
    bool    m_can_add_web_page_previews = false;
    int32_t m_until_date                = 0;
};

void readValue(ChatMemberRestricted::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // CHATMEMBERRESTRICTED_H
