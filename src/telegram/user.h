#ifndef USER_H
#define USER_H

#include "common.h"

namespace TelegramApi
{
struct User
{
    typedef QSharedPointer<User> Ptr;

    int32_t m_id;
    bool    m_is_bot;
    QString m_first_name;
    QString m_last_name;
    QString m_username;
    QString m_language_code;
    bool    m_can_join_groups;
    bool    m_can_read_all_group_messages;
    bool    m_supports_inline_queries;
};

void readValue(User::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // USER_H
