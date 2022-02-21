#include "invoice.h"

namespace TelegramApi
{
void readValue(Invoice::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = Invoice::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readValue(value->m_title, object, "title");
        readValue(value->m_description, object, "description");
        readValue(value->m_start_parameter, object, "start_parameter");
        readValue(value->m_currency, object, "currency");
        readValue(value->m_total_amount, object, "total_amount");
    }
}
}
