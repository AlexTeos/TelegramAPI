#include "choseninlineresult.h"

namespace Telegram
{
void readJsonObject(ChosenInlineResult::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = ChosenInlineResult::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readJsonObject(value->m_result_id, object, "result_id");
        readJsonObject(value->m_from, object, "from");
        readJsonObject(value->m_location, object, "locatio");
        readJsonObject(value->m_inline_message_id, object, "inline_message_id");
        readJsonObject(value->m_query, object, "query");
    }
}
}
