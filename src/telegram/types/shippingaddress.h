#ifndef SHIPPINGADDRESS_H
#define SHIPPINGADDRESS_H

#include "common.h"

namespace Telegram
{
struct ShippingAddress
{
    typedef QSharedPointer<ShippingAddress> Ptr;

    QString m_country_code;
    QString m_state;
    QString m_city;
    QString m_street_line1;
    QString m_street_line2;
    QString m_post_code;
};

void readJsonObject(ShippingAddress::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // SHIPPINGADDRESS_H
