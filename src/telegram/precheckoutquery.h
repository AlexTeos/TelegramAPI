#ifndef PRECHECKOUTQUERY_H
#define PRECHECKOUTQUERY_H

#include "common.h"
#include "orderinfo.h"
#include "user.h"

namespace TelegramApi
{
struct PreCheckoutQuery
{
    typedef QSharedPointer<PreCheckoutQuery> Ptr;

    QString        m_id;
    User::Ptr      m_from;
    QString        m_currency;
    int32_t        m_total_amount = 0;
    QString        m_invoice_payload;
    QString        m_shipping_option_id;
    OrderInfo::Ptr m_order_info;
};

void readValue(PreCheckoutQuery::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // PRECHECKOUTQUERY_H
