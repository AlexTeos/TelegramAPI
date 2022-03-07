#include "contact.h"

namespace Telegram
{
void readJsonObject(Contact::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = Contact::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readJsonObject(value->m_phone_number, object, "phone_number");
        readJsonObject(value->m_first_name, object, "first_name");
        readJsonObject(value->m_last_name, object, "last_name");
        readJsonObject(value->m_user_id, object, "user_id");
        readJsonObject(value->m_vcard, object, "vcard");
    }
}
}
