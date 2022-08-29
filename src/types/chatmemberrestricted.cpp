#include "chatmemberrestricted.h"

namespace Telegram
{
const QString ChatMemberRestricted::Status("restricted");

QJsonObject ChatMemberRestricted::toJsonValue()
{
    QJsonObject jsonObject = ChatMember::toJsonValue();

    jsonObject.insert("is_member", m_is_member);
    jsonObject.insert("can_change_info", m_can_change_info);
    jsonObject.insert("can_invite_users", m_can_invite_users);
    jsonObject.insert("can_pin_messages", m_can_pin_messages);
    jsonObject.insert("can_send_messages", m_can_send_messages);
    jsonObject.insert("can_send_media_messages", m_can_send_media_messages);
    jsonObject.insert("can_send_polls", m_can_send_polls);
    jsonObject.insert("can_send_other_messages", m_can_send_other_messages);
    jsonObject.insert("can_add_web_page_previews", m_can_add_web_page_previews);
    jsonObject.insert("until_date", m_until_date);

    return jsonObject;
}

bool ChatMemberRestricted::readJsonObject(const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        ChatMember::readJsonObject(json, valueName);

        QJsonObject object = json[valueName].toObject();

        Telegram::readJsonObject(m_is_member, object, "is_member");
        Telegram::readJsonObject(m_can_change_info, object, "can_change_info");
        Telegram::readJsonObject(m_can_invite_users, object, "can_invite_users");
        Telegram::readJsonObject(m_can_pin_messages, object, "can_pin_messages");
        Telegram::readJsonObject(m_can_send_messages, object, "can_send_messages");
        Telegram::readJsonObject(m_can_send_media_messages, object, "can_send_media_messages");
        Telegram::readJsonObject(m_can_send_polls, object, "can_send_polls");
        Telegram::readJsonObject(m_can_send_other_messages, object, "can_send_other_messages");
        Telegram::readJsonObject(m_can_add_web_page_previews, object, "can_add_web_page_previews");
        Telegram::readJsonObject(m_until_date, object, "until_date");

        return true;
    }

    return false;
}

bool readJsonObject(ChatMemberRestricted::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    value = ChatMemberRestricted::Ptr::create();

    return value->readJsonObject(json, valueName);
}
}
