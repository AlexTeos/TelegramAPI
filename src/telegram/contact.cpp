#include "contact.h"

namespace TelegramApi
{
void readValue(Contact::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = Contact::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readValue(value->m_phone_number, object, "phone_number");
        readValue(value->m_first_name, object, "first_name");
        readValue(value->m_last_name, object, "last_name");
        readValue(value->m_user_id, object, "user_id");
        readValue(value->m_vcard, object, "vcard");
    }
}
}
