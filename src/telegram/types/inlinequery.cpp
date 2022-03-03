#include "inlinequery.h"

namespace TelegramApi
{
void readValue(InlineQuery::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = InlineQuery::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readValue(value->m_id, object, "id");
        readValue(value->m_from, object, "from");
        readValue(value->m_query, object, "query");
        readValue(value->m_offset, object, "offset");
        readValue(value->m_chat_type, object, "chat_type");
        readValue(value->m_location, object, "location");
    }
}
}
