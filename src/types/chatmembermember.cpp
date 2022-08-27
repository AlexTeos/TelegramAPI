#include "chatmembermember.h"

namespace Telegram
{
const QString ChatMemberMember::Type("member");

bool readJsonObject(ChatMemberMember::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = ChatMemberMember::Ptr::create();

        return true;
    }

    return false;
}
}
