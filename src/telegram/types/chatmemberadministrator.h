#ifndef CHATMEMBERADMINISTRATOR_H
#define CHATMEMBERADMINISTRATOR_H

#include "chatmember.h"

namespace Telegram
{
struct ChatMemberAdministrator : public ChatMember
{
    typedef QSharedPointer<ChatMemberAdministrator> Ptr;

    bool    m_can_be_edited          = false;
    bool    m_is_anonymous           = false;
    bool    m_can_manage_chat        = false;
    bool    m_can_delete_messages    = false;
    bool    m_can_manage_voice_chats = false;
    bool    m_can_restrict_members   = false;
    bool    m_can_promote_members    = false;
    bool    m_can_change_info        = false;
    bool    m_can_invite_users       = false;
    bool    m_can_post_messages      = false;
    bool    m_can_edit_messages      = false;
    bool    m_can_pin_messages       = false;
    QString m_custom_title;
};

void readJsonObject(ChatMemberAdministrator::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // CHATMEMBERADMINISTRATOR_H
