#include "chatmemberadministrator.h"

namespace Telegram
{
const QString ChatMemberAdministrator::Status("administrator");

QJsonObject ChatMemberAdministrator::toJsonValue()
{
    QJsonObject jsonObject = ChatMember::toJsonValue();

    jsonObject.insert("can_be_edited", m_can_be_edited);
    jsonObject.insert("is_anonymous", m_is_anonymous);
    jsonObject.insert("can_manage_chat", m_can_manage_chat);
    jsonObject.insert("can_delete_messages", m_can_delete_messages);
    jsonObject.insert("can_manage_voice_chats", m_can_manage_voice_chats);
    jsonObject.insert("can_restrict_members", m_can_restrict_members);
    jsonObject.insert("can_promote_members", m_can_promote_members);
    jsonObject.insert("can_change_info", m_can_change_info);
    jsonObject.insert("can_invite_users", m_can_invite_users);
    if (m_can_post_messages) jsonObject.insert("can_post_messages", Telegram::toJsonValue(m_can_post_messages.value()));
    if (m_can_edit_messages) jsonObject.insert("can_edit_messages", Telegram::toJsonValue(m_can_edit_messages.value()));
    if (m_can_pin_messages) jsonObject.insert("can_pin_messages", Telegram::toJsonValue(m_can_pin_messages.value()));
    if (m_custom_title) jsonObject.insert("custom_title", Telegram::toJsonValue(m_custom_title.value()));

    return jsonObject;
}

bool ChatMemberAdministrator::readJsonObject(const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        ChatMember::readJsonObject(json, valueName);

        QJsonObject object = json[valueName].toObject();

        Telegram::readJsonObject(m_can_be_edited, object, "can_be_edited");
        Telegram::readJsonObject(m_is_anonymous, object, "is_anonymous");
        Telegram::readJsonObject(m_can_manage_chat, object, "can_manage_chat");
        Telegram::readJsonObject(m_can_delete_messages, object, "can_delete_messages");
        Telegram::readJsonObject(m_can_manage_voice_chats, object, "can_manage_voice_chats");
        Telegram::readJsonObject(m_can_restrict_members, object, "can_restrict_members");
        Telegram::readJsonObject(m_can_promote_members, object, "can_promote_members");
        Telegram::readJsonObject(m_can_change_info, object, "can_change_info");
        Telegram::readJsonObject(m_can_invite_users, object, "can_invite_users");
        Telegram::readJsonObject(m_can_post_messages, object, "can_post_messages");
        Telegram::readJsonObject(m_can_edit_messages, object, "can_edit_messages");
        Telegram::readJsonObject(m_can_pin_messages, object, "can_pin_messages");
        Telegram::readJsonObject(m_custom_title, object, "custom_title");

        return true;
    }

    return false;
}

bool readJsonObject(ChatMemberAdministrator::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    value = ChatMemberAdministrator::Ptr::create();

    return value->readJsonObject(json, valueName);
}
}
