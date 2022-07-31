#include "orderinfo.h"

namespace Telegram
{
bool readJsonObject(OrderInfo::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = OrderInfo::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readJsonObject(value->m_name, object, "name");
        readJsonObject(value->m_phone_number, object, "phone_number");
        readJsonObject(value->m_email, object, "email");
        readJsonObject(value->m_shipping_address, object, "shipping_address");

        return true;
    }

    return false;
}
}
