#include "chatmembermember.h"

namespace Telegram
{
const QString ChatMemberMember::Status("member");

QJsonObject ChatMemberMember::toJsonValue()
{
    return ChatMember::toJsonValue();
}

bool ChatMemberMember::readJsonObject(const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        ChatMember::readJsonObject(json, valueName);

        return true;
    }

    return false;
}

bool readJsonObject(ChatMemberMember::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    value = ChatMemberMember::Ptr::create();

    return value->readJsonObject(json, valueName);
}
}
