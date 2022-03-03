#include "chatmemberleft.h"

namespace TelegramApi
{
void readValue(ChatMemberLeft::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = ChatMemberLeft::Ptr::create();
    }
}
}
