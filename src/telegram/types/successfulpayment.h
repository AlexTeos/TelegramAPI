#ifndef SUCCESSFULPAYMENT_H
#define SUCCESSFULPAYMENT_H

#include "common.h"
#include "orderinfo.h"

namespace TelegramApi
{
struct SuccessfulPayment
{
    typedef QSharedPointer<SuccessfulPayment> Ptr;

    QString        m_currency;
    qint64         m_total_amount = 0;
    QString        m_invoice_payload;
    QString        m_shipping_option_id;
    OrderInfo::Ptr m_order_info;
    QString        m_telegram_payment_charge_id;
    QString        m_provider_payment_charge_id;
};

void readValue(SuccessfulPayment::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // SUCCESSFULPAYMENT_H
