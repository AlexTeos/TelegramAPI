#include "shippingaddress.h"

namespace TelegramApi
{
void readValue(ShippingAddress::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = ShippingAddress::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readValue(value->m_country_code, object, "country_code");
        readValue(value->m_state, object, "state");
        readValue(value->m_city, object, "city");
        readValue(value->m_street_line1, object, "street_line1");
        readValue(value->m_street_line2, object, "street_line2");
        readValue(value->m_post_code, object, "post_code");
    }
}
}
