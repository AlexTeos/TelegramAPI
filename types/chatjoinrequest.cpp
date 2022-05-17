#include "chatjoinrequest.h"

namespace Telegram
{
bool readJsonObject(ChatJoinRequest::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = ChatJoinRequest::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readJsonObject(value->m_chat, object, "chat");
        readJsonObject(value->m_from, object, "from");
        readJsonObject(value->m_date, object, "date");
        readJsonObject(value->m_bio, object, "bio");
        readJsonObject(value->m_invite_link, object, "invite_link");

        return true;
    }

    return false;
}
}
