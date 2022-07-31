#include "chatlocation.h"

namespace Telegram
{
bool readJsonObject(ChatLocation::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = ChatLocation::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readJsonObject(value->m_location, object, "location");
        readJsonObject(value->m_address, object, "address");

        return true;
    }

    return false;
}
}
