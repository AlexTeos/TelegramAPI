#ifndef ORDERINFO_H
#define ORDERINFO_H

#include "common.h"
#include "shippingaddress.h"

namespace Telegram
{
struct OrderInfo
{
    typedef QSharedPointer<OrderInfo> Ptr;

    QString              m_name;
    QString              m_phone_number;
    QString              m_email;
    ShippingAddress::Ptr m_shipping_address;
};

void readJsonObject(OrderInfo::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // ORDERINFO_H
