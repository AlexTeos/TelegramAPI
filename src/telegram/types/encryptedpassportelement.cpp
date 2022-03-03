#include "encryptedpassportelement.h"

namespace TelegramApi
{
void readValue(EncryptedPassportElement::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = EncryptedPassportElement::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readValue(value->m_type, object, "type");
        readValue(value->m_data, object, "data");
        readValue(value->m_phone_number, object, "phone_number");
        readValue(value->m_email, object, "email");
        readValue(value->m_files, object, "files");
        readValue(value->m_front_side, object, "front_side");
        readValue(value->m_reverse_side, object, "reverse_side");
        readValue(value->m_selfie, object, "selfie");
        readValue(value->m_translation, object, "translation");
        readValue(value->m_hash, object, "hash");
    }
}
}
