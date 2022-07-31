#include "encryptedcredentials.h"

namespace Telegram
{
bool readJsonObject(EncryptedCredentials::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = EncryptedCredentials::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readJsonObject(value->m_data, object, "data");
        readJsonObject(value->m_hash, object, "hash");
        readJsonObject(value->m_secret, object, "secret");

        return true;
    }

    return false;
}
}
