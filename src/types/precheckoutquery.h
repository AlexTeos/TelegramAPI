#ifndef PRECHECKOUTQUERY_H
#define PRECHECKOUTQUERY_H

#include "orderinfo.h"
#include "user.h"

namespace Telegram
{
struct PreCheckoutQuery
{
    using Ptr = QSharedPointer<PreCheckoutQuery>;

    QString                m_id;
    User::Ptr              m_from;
    QString                m_currency;
    qint64                 m_total_amount;
    QString                m_invoice_payload;
    std::optional<QString> m_shipping_option_id;
    OrderInfo::Ptr         m_order_info;
};

bool readJsonObject(PreCheckoutQuery::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // PRECHECKOUTQUERY_H
