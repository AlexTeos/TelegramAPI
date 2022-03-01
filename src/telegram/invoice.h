#ifndef INVOICE_H
#define INVOICE_H

#include "common.h"

namespace TelegramApi
{
struct Invoice
{
    typedef QSharedPointer<Invoice> Ptr;

    QString m_title;
    QString m_description;
    QString m_start_parameter;
    QString m_currency;
    int32_t m_total_amount = 0;
};

void readValue(Invoice::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // INVOICE_H
