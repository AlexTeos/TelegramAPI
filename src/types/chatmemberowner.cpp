#include "chatmemberowner.h"

namespace Telegram
{
bool readJsonObject(ChatMemberOwner::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = ChatMemberOwner::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readJsonObject(value->m_is_anonymous, object, "is_anonymous");
        readJsonObject(value->m_custom_title, object, "custom_title");

        return true;
    }

    return false;
}
}
