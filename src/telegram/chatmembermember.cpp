#include "chatmembermember.h"

namespace TelegramApi
{
void readValue(ChatMemberMember::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = ChatMemberMember::Ptr::create();
    }
}
}
