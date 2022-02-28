#ifndef CHATMEMBERADMINISTRATOR_H
#define CHATMEMBERADMINISTRATOR_H

#include "chatmember.h"

namespace TelegramApi
{
struct ChatMemberAdministrator : public ChatMember
{
    typedef QSharedPointer<ChatMemberAdministrator> Ptr;

    bool    m_can_be_edited;
    bool    m_is_anonymous;
    bool    m_can_manage_chat;
    bool    m_can_delete_messages;
    bool    m_can_manage_voice_chats;
    bool    m_can_restrict_members;
    bool    m_can_promote_members;
    bool    m_can_change_info;
    bool    m_can_invite_users;
    bool    m_can_post_messages;
    bool    m_can_edit_messages;
    bool    m_can_pin_messages;
    QString m_custom_title;
};

void readValue(ChatMemberAdministrator::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // CHATMEMBERADMINISTRATOR_H
