#include "chatmemberbanned.h"

namespace Telegram
{
void readJsonObject(ChatMemberBanned::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = ChatMemberBanned::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readJsonObject(value->m_until_date, object, "until_date");
    }
}
}
