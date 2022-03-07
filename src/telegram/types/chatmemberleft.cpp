#include "chatmemberleft.h"

namespace Telegram
{
void readJsonObject(ChatMemberLeft::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = ChatMemberLeft::Ptr::create();
    }
}
}
