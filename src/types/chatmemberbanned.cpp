#include "chatmemberbanned.h"

namespace Telegram
{
const QString ChatMemberBanned::Status("kicked");

QJsonObject ChatMemberBanned::toJsonValue()
{
    QJsonObject jsonObject = ChatMember::toJsonValue();

    jsonObject.insert("until_date", m_until_date);

    return jsonObject;
}

bool ChatMemberBanned::readJsonObject(const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        ChatMember::readJsonObject(json, valueName);

        QJsonObject object = json[valueName].toObject();

        Telegram::readJsonObject(m_until_date, object, "until_date");

        return true;
    }

    return false;
}

bool readJsonObject(ChatMemberBanned::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    value = ChatMemberBanned::Ptr::create();

    return value->readJsonObject(json, valueName);
}
}
