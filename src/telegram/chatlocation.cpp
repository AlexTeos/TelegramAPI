#include "chatlocation.h"

namespace TelegramApi
{
void readValue(ChatLocation::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = ChatLocation::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readValue(value->m_location, object, "location");
        readValue(value->m_address, object, "address");
    }
}
}
