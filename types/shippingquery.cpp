#include "shippingquery.h"

namespace Telegram
{
bool readJsonObject(ShippingQuery::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = ShippingQuery::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readJsonObject(value->m_id, object, "id");
        readJsonObject(value->m_from, object, "from");
        readJsonObject(value->m_invoice_payload, object, "invoice_payload");
        readJsonObject(value->m_shipping_address, object, "shipping_address");

        return true;
    }

    return false;
}
}
