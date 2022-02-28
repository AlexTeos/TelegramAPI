#include "chatmemberbanned.h"

namespace TelegramApi
{
void readValue(ChatMemberBanned::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = ChatMemberBanned::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readValue(value->m_until_date, object, "until_date");
    }
}
}
