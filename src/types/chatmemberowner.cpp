#include "chatmemberowner.h"

namespace Telegram
{
const QString ChatMemberOwner::Status("creator");

QJsonObject ChatMemberOwner::toJsonValue()
{
    QJsonObject jsonObject = ChatMember::toJsonValue();

    jsonObject.insert("is_anonymous", m_is_anonymous);
    if (m_custom_title) jsonObject.insert("custom_title", m_custom_title.value());

    return jsonObject;
}

bool ChatMemberOwner::readJsonObject(const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        ChatMember::readJsonObject(json, valueName);

        QJsonObject object = json[valueName].toObject();

        Telegram::readJsonObject(m_is_anonymous, object, "is_anonymous");
        Telegram::readJsonObject(m_custom_title, object, "custom_title");

        return true;
    }

    return false;
}

bool readJsonObject(ChatMemberOwner::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    value = ChatMemberOwner::Ptr::create();

    return value->readJsonObject(json, valueName);
}
}
