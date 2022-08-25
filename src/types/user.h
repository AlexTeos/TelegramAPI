#ifndef USER_H
#define USER_H

#include "common.h"

namespace Telegram
{
struct User
{
    using Ptr = QSharedPointer<User>;

    qint64                 m_id;
    bool                   m_is_bot;
    QString                m_first_name;
    std::optional<QString> m_last_name;
    std::optional<QString> m_username;
    std::optional<QString> m_language_code;
    std::optional<bool>    m_can_join_groups;
    std::optional<bool>    m_can_read_all_group_messages;
    std::optional<bool>    m_supports_inline_queries;
};

bool       readJsonObject(User::Ptr& value, const QJsonObject& json, const QString& valueName);
QJsonValue toJsonValue(const User::Ptr& value);
}

#endif // USER_H
