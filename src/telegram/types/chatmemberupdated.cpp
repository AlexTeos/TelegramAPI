#include "chatmemberupdated.h"

namespace Telegram
{
void readJsonObject(ChatMemberUpdated::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = ChatMemberUpdated::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readJsonObject(value->m_chat, object, "chat");
        readJsonObject(value->m_from, object, "from");
        readJsonObject(value->m_date, object, "date");
        readJsonObject(value->m_old_chat_member, object, "old_chat_member");
        readJsonObject(value->m_new_chat_member, object, "new_chat_member");
        readJsonObject(value->m_invite_link, object, "invite_link");
    }
}
}
