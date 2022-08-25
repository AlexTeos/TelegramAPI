#ifndef ORDERINFO_H
#define ORDERINFO_H

#include "shippingaddress.h"

namespace Telegram
{
struct OrderInfo
{
    using Ptr = QSharedPointer<OrderInfo>;

    std::optional<QString> m_name;
    std::optional<QString> m_phone_number;
    std::optional<QString> m_email;
    ShippingAddress::Ptr   m_shipping_address;
};

bool readJsonObject(OrderInfo::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // ORDERINFO_H
