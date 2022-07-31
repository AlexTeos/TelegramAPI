#ifndef CHATMEMBERADMINISTRATOR_H
#define CHATMEMBERADMINISTRATOR_H

#include "chatmember.h"

namespace Telegram
{
struct ChatMemberAdministrator : public ChatMember
{
    typedef QSharedPointer<ChatMemberAdministrator> Ptr;

    bool                   m_can_be_edited;
    bool                   m_is_anonymous;
    bool                   m_can_manage_chat;
    bool                   m_can_delete_messages;
    bool                   m_can_manage_voice_chats;
    bool                   m_can_restrict_members;
    bool                   m_can_promote_members;
    bool                   m_can_change_info;
    bool                   m_can_invite_users;
    std::optional<bool>    m_can_post_messages;
    std::optional<bool>    m_can_edit_messages;
    std::optional<bool>    m_can_pin_messages;
    std::optional<QString> m_custom_title;
};

bool readJsonObject(ChatMemberAdministrator::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // CHATMEMBERADMINISTRATOR_H
