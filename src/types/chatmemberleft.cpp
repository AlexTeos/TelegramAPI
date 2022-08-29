#include "chatmemberleft.h"

namespace Telegram
{
const QString ChatMemberLeft::Status("left");

QJsonObject ChatMemberLeft::toJsonValue()
{
    return ChatMember::toJsonValue();
}

bool ChatMemberLeft::readJsonObject(const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        ChatMember::readJsonObject(json, valueName);

        return true;
    }

    return false;
}

bool readJsonObject(ChatMemberLeft::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    value = ChatMemberLeft::Ptr::create();

    return value->readJsonObject(json, valueName);
}
}
