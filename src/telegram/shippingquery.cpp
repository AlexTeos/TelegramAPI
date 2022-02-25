#include "shippingquery.h"

namespace TelegramApi
{
void readValue(ShippingQuery::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = ShippingQuery::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readValue(value->m_id, object, "id");
        readValue(value->m_from, object, "from");
        readValue(value->m_invoice_payload, object, "invoice_payload");
        readValue(value->m_shipping_address, object, "shipping_address");
    }
}
}
