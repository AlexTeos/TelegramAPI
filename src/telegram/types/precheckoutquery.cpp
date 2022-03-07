#include "precheckoutquery.h"

namespace Telegram
{
void readJsonObject(PreCheckoutQuery::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = PreCheckoutQuery::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readJsonObject(value->m_id, object, "id");
        readJsonObject(value->m_from, object, "from");
        readJsonObject(value->m_currency, object, "currency");
        readJsonObject(value->m_total_amount, object, "total_amount");
        readJsonObject(value->m_invoice_payload, object, "invoice_payload");
        readJsonObject(value->m_shipping_option_id, object, "shipping_option_id");
        readJsonObject(value->m_order_info, object, "order_info");
    }
}
}
