#include "orderinfo.h"

namespace TelegramApi
{
void readValue(OrderInfo::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = OrderInfo::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readValue(value->m_name, object, "name");
        readValue(value->m_phone_number, object, "phone_number");
        readValue(value->m_email, object, "email");
        readValue(value->m_shipping_address, object, "shipping_address");
    }
}
}
