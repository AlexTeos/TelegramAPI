#ifndef CHAT_H
#define CHAT_H

#include "chatlocation.h"
#include "chatpermissions.h"
#include "chatphoto.h"
#include "common.h"

namespace Telegram
{
struct Message;

struct Chat
{
    typedef QSharedPointer<Chat> Ptr;

    qint64                  m_id;
    QString                 m_type;
    std::optional<QString>  m_title;
    std::optional<QString>  m_username;
    std::optional<QString>  m_first_name;
    std::optional<QString>  m_last_name;
    ChatPhoto::Ptr          m_photo;
    std::optional<QString>  m_bio;
    std::optional<bool>     m_has_private_forwards;
    std::optional<QString>  m_description;
    std::optional<QString>  m_invite_link;
    QSharedPointer<Message> m_pinned_message;
    ChatPermissions::Ptr    m_permissions;
    std::optional<qint64>   m_slow_mode_delay;
    std::optional<qint64>   m_message_auto_delete_time;
    std::optional<bool>     m_has_protected_content;
    std::optional<QString>  m_sticker_set_name;
    std::optional<bool>     m_can_set_sticker_set;
    std::optional<qint64>   m_linked_chat_id;
    ChatLocation::Ptr       m_location;
};

bool readJsonObject(Chat::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // CHAT_H
