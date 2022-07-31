#include "passportdata.h"

namespace Telegram
{
bool readJsonObject(PassportData::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = PassportData::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readJsonObject(value->m_data, object, "data");
        readJsonObject(value->m_credentials, object, "credentials");

        return true;
    }

    return false;
}
}
