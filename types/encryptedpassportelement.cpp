#include "encryptedpassportelement.h"

namespace Telegram
{
bool readJsonObject(EncryptedPassportElement::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = EncryptedPassportElement::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readJsonObject(value->m_type, object, "type");
        readJsonObject(value->m_data, object, "data");
        readJsonObject(value->m_phone_number, object, "phone_number");
        readJsonObject(value->m_email, object, "email");
        readJsonObject(value->m_files, object, "files");
        readJsonObject(value->m_front_side, object, "front_side");
        readJsonObject(value->m_reverse_side, object, "reverse_side");
        readJsonObject(value->m_selfie, object, "selfie");
        readJsonObject(value->m_translation, object, "translation");
        readJsonObject(value->m_hash, object, "hash");

        return true;
    }

    return false;
}
}
