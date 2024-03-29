#ifndef SHIPPINGQUERY_H
#define SHIPPINGQUERY_H

#include "shippingaddress.h"
#include "user.h"

namespace Telegram
{
struct ShippingQuery
{
    using Ptr = QSharedPointer<ShippingQuery>;

    QString              m_id;
    User::Ptr            m_from;
    QString              m_invoice_payload;
    ShippingAddress::Ptr m_shipping_address;
};

bool readJsonObject(ShippingQuery::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // SHIPPINGQUERY_H
