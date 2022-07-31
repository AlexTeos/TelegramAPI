#include "user.h"

namespace Telegram
{
bool readJsonObject(User::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = User::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readJsonObject(value->m_id, object, "id");
        readJsonObject(value->m_is_bot, object, "ibot");
        readJsonObject(value->m_first_name, object, "first_name");
        readJsonObject(value->m_last_name, object, "last_name");
        readJsonObject(value->m_username, object, "username");
        readJsonObject(value->m_language_code, object, "language_code");
        readJsonObject(value->m_can_join_groups, object, "can_join_groups");
        readJsonObject(value->m_can_read_all_group_messages, object, "can_read_all_group_messages");
        readJsonObject(value->m_supports_inline_queries, object, "supports_inline_queries");

        return true;
    }

    return false;
}

QJsonValue toJsonValue(const User::Ptr& value)
{
    QJsonObject jsonObject;

    jsonObject.insert("id", value->m_id);
    jsonObject.insert("is_bot", value->m_is_bot);
    jsonObject.insert("first_name", value->m_first_name);
    if (value->m_last_name) jsonObject.insert("last_name", value->m_last_name.value());
    if (value->m_username) jsonObject.insert("username", value->m_username.value());
    if (value->m_language_code) jsonObject.insert("language_code", value->m_language_code.value());
    if (value->m_can_join_groups) jsonObject.insert("can_join_groups", value->m_can_join_groups.value());
    if (value->m_can_read_all_group_messages)
        jsonObject.insert("can_read_all_group_messages", value->m_can_read_all_group_messages.value());
    if (value->m_supports_inline_queries)
        jsonObject.insert("supports_inline_queries", value->m_supports_inline_queries.value());

    return jsonObject;
}
}
