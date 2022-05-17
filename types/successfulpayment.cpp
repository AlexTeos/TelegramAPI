#include "successfulpayment.h"

namespace Telegram
{
bool readJsonObject(SuccessfulPayment::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = SuccessfulPayment::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readJsonObject(value->m_currency, object, "currency");
        readJsonObject(value->m_total_amount, object, "total_amount");
        readJsonObject(value->m_invoice_payload, object, "invoice_payload");
        readJsonObject(value->m_order_info, object, "order_info");
        readJsonObject(value->m_telegram_payment_charge_id, object, "telegram_payment_charge_id");
        readJsonObject(value->m_provider_payment_charge_id, object, "provider_payment_charge_id");

        return true;
    }

    return false;
}
}
