#ifndef CHATMEMBERRESTRICTED_H
#define CHATMEMBERRESTRICTED_H

#include "chatmember.h"

namespace Telegram
{
struct ChatMemberRestricted : public ChatMember
{
    typedef QSharedPointer<ChatMemberRestricted> Ptr;

    bool   m_is_member;
    bool   m_can_change_info;
    bool   m_can_invite_users;
    bool   m_can_pin_messages;
    bool   m_can_send_messages;
    bool   m_can_send_media_messages;
    bool   m_can_send_polls;
    bool   m_can_send_other_messages;
    bool   m_can_add_web_page_previews;
    qint64 m_until_date;
};

void readJsonObject(ChatMemberRestricted::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // CHATMEMBERRESTRICTED_H
