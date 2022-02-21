#include "passportdata.h"

namespace TelegramApi
{
void readValue(PassportData::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = PassportData::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readArray(value->m_data, object, "data");
        readValue(value->m_credentials, object, "credentials");
    }
}
}
