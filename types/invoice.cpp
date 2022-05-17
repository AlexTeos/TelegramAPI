#include "invoice.h"

namespace Telegram
{
bool readJsonObject(Invoice::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = Invoice::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readJsonObject(value->m_title, object, "title");
        readJsonObject(value->m_description, object, "description");
        readJsonObject(value->m_start_parameter, object, "start_parameter");
        readJsonObject(value->m_currency, object, "currency");
        readJsonObject(value->m_total_amount, object, "total_amount");

        return true;
    }

    return false;
}
}
