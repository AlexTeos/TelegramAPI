#include "chatmemberleft.h"

namespace Telegram
{
bool readJsonObject(ChatMemberLeft::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = ChatMemberLeft::Ptr::create();

        return true;
    }

    return false;
}
}
