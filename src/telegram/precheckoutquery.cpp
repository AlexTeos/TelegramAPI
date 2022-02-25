#include "precheckoutquery.h"

namespace TelegramApi
{
void readValue(PreCheckoutQuery::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = PreCheckoutQuery::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readValue(value->m_id, object, "id");
        readValue(value->m_from, object, "from");
        readValue(value->m_currency, object, "currency");
        readValue(value->m_total_amount, object, "total_amount");
        readValue(value->m_invoice_payload, object, "invoice_payload");
        readValue(value->m_shipping_option_id, object, "shipping_option_id");
        readValue(value->m_order_info, object, "order_info");
    }
}
}
