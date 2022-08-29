#include "chatmember.h"

namespace Telegram
{
bool ChatMember::readJsonObject(const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        QJsonObject object = json[valueName].toObject();

        Telegram::readJsonObject(m_status, object, "status");
        Telegram::readJsonObject(m_user, object, "user");

        return true;
    }

    return false;
}

QJsonObject ChatMember::toJsonValue()
{
    QJsonObject jsonObject;

    jsonObject.insert("type", m_status);
    jsonObject.insert("user", Telegram::toJsonValue(m_user));

    return jsonObject;
}

QJsonObject toJsonValue(const ChatMember::Ptr& value)
{
    return value->toJsonValue();
}

bool readJsonObject(ChatMember::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    value = ChatMember::Ptr::create();

    return value->readJsonObject(json, valueName);
}
}
