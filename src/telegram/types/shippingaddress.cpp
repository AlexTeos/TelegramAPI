#include "shippingaddress.h"

namespace Telegram
{
void readJsonObject(ShippingAddress::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = ShippingAddress::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readJsonObject(value->m_country_code, object, "country_code");
        readJsonObject(value->m_state, object, "state");
        readJsonObject(value->m_city, object, "city");
        readJsonObject(value->m_street_line1, object, "street_line1");
        readJsonObject(value->m_street_line2, object, "street_line2");
        readJsonObject(value->m_post_code, object, "post_code");
    }
}
}
