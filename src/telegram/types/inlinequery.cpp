#include "inlinequery.h"

namespace Telegram
{
void readJsonObject(InlineQuery::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = InlineQuery::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readJsonObject(value->m_id, object, "id");
        readJsonObject(value->m_from, object, "from");
        readJsonObject(value->m_query, object, "query");
        readJsonObject(value->m_offset, object, "offset");
        readJsonObject(value->m_chat_type, object, "chat_type");
        readJsonObject(value->m_location, object, "location");
    }
}
}
