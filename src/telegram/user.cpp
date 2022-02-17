#include "user.h"

namespace TelegramApi
{
void readValue(User::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = User::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readValue(value->m_id, object, "id");
        readValue(value->m_is_bot, object, "ibot");
        readValue(value->m_first_name, object, "first_name");
        readValue(value->m_last_name, object, "last_name");
        readValue(value->m_username, object, "username");
        readValue(value->m_language_code, object, "language_code");
        readValue(value->m_can_join_groups, object, "can_join_groups");
        readValue(value->m_can_read_all_group_messages, object, "can_read_all_group_messages");
        readValue(value->m_supports_inline_queries, object, "supports_inline_queries");
    }
}
}
