#include "chatmembermember.h"

namespace Telegram
{
void readJsonObject(ChatMemberMember::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = ChatMemberMember::Ptr::create();
    }
}
}
