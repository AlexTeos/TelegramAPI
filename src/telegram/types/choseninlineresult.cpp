#include "choseninlineresult.h"

namespace TelegramApi
{
void readValue(ChosenInlineResult::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = ChosenInlineResult::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readValue(value->m_result_id, object, "result_id");
        readValue(value->m_from, object, "from");
        readValue(value->m_location, object, "locatio");
        readValue(value->m_inline_message_id, object, "inline_message_id");
        readValue(value->m_query, object, "query");
    }
}
}
