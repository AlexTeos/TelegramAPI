#include "encryptedcredentials.h"

namespace TelegramApi
{
void readValue(EncryptedCredentials::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = EncryptedCredentials::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readValue(value->m_data, object, "data");
        readValue(value->m_hash, object, "hash");
        readValue(value->m_secret, object, "secret");
    }
}
}
