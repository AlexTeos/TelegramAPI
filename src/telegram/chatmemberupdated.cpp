#include "chatmemberupdated.h"

namespace TelegramApi
{
void readValue(ChatMemberUpdated::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = ChatMemberUpdated::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readValue(value->m_chat, object, "chat");
        readValue(value->m_from, object, "from");
        readValue(value->m_date, object, "date");
        readValue(value->m_old_chat_member, object, "old_chat_member");
        readValue(value->m_new_chat_member, object, "new_chat_member");
        readValue(value->m_invite_link, object, "invite_link");
    }
}
}
