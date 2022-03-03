#include "chatmemberowner.h"

namespace TelegramApi
{
void readValue(ChatMemberOwner::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = ChatMemberOwner::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readValue(value->m_is_anonymous, object, "is_anonymous");
        readValue(value->m_custom_title, object, "custom_title");
    }
}
}
