#include "chatjoinrequest.h"

namespace TelegramApi
{
void readValue(ChatJoinRequest::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = ChatJoinRequest::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readValue(value->m_chat, object, "chat");
        readValue(value->m_from, object, "from");
        readValue(value->m_date, object, "date");
        readValue(value->m_bio, object, "bio");
        readValue(value->m_invite_link, object, "invite_link");
    }
}
}
