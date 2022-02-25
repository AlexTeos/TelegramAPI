#ifndef CHAT_H
#define CHAT_H

#include "chatlocation.h"
#include "chatpermissions.h"
#include "chatphoto.h"
#include "common.h"

namespace TelegramApi
{
struct Message;

struct Chat
{
    typedef QSharedPointer<Chat> Ptr;

    int32_t                 m_id;
    QString                 m_type;
    QString                 m_title;
    QString                 m_username;
    QString                 m_first_name;
    QString                 m_last_name;
    ChatPhoto::Ptr          m_photo;
    QString                 m_bio;
    bool                    m_has_private_forwards;
    QString                 m_description;
    QString                 m_invite_link;
    QSharedPointer<Message> m_pinned_message;
    ChatPermissions::Ptr    m_permissions;
    int32_t                 m_slow_mode_delay;
    int32_t                 m_message_auto_delete_time;
    bool                    m_has_protected_content;
    QString                 m_sticker_set_name;
    bool                    m_can_set_sticker_set;
    int32_t                 m_linked_chat_id;
    ChatLocation::Ptr       m_location;
};

void readValue(Chat::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // CHAT_H
