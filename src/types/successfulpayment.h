#ifndef SUCCESSFULPAYMENT_H
#define SUCCESSFULPAYMENT_H

#include "orderinfo.h"

namespace Telegram
{
struct SuccessfulPayment
{
    using Ptr = QSharedPointer<SuccessfulPayment>;

    QString                m_currency;
    qint64                 m_total_amount = 0;
    QString                m_invoice_payload;
    std::optional<QString> m_shipping_option_id;
    OrderInfo::Ptr         m_order_info;
    QString                m_telegram_payment_charge_id;
    QString                m_provider_payment_charge_id;
};

bool readJsonObject(SuccessfulPayment::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // SUCCESSFULPAYMENT_H
