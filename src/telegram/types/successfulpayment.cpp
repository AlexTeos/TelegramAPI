#include "successfulpayment.h"

namespace TelegramApi
{
void readValue(SuccessfulPayment::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = SuccessfulPayment::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readValue(value->m_currency, object, "currency");
        readValue(value->m_total_amount, object, "total_amount");
        readValue(value->m_invoice_payload, object, "invoice_payload");
        readValue(value->m_order_info, object, "order_info");
        readValue(value->m_telegram_payment_charge_id, object, "telegram_payment_charge_id");
        readValue(value->m_provider_payment_charge_id, object, "provider_payment_charge_id");
    }
}
}
