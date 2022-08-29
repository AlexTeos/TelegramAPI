#ifndef CHATMEMBERRESTRICTED_H
#define CHATMEMBERRESTRICTED_H

#include "chatmember.h"

namespace Telegram
{
struct ChatMemberRestricted : public ChatMember
{
    using Ptr = QSharedPointer<ChatMemberRestricted>;
    static const QString Status;

    bool readJsonObject(const QJsonObject& json, const QString& valueName);

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

    friend bool readJsonObject(ChatMemberRestricted::Ptr&, const QJsonObject&, const QString&);

protected:
    virtual QJsonObject toJsonValue();
};

bool readJsonObject(ChatMemberRestricted::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // CHATMEMBERRESTRICTED_H
