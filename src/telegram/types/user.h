#ifndef USER_H
#define USER_H

#include "common.h"

namespace Telegram
{
struct User
{
    typedef QSharedPointer<User> Ptr;

    qint64  m_id     = 0;
    bool    m_is_bot = false;
    QString m_first_name;
    QString m_last_name;
    QString m_username;
    QString m_language_code;
    bool    m_can_join_groups             = false;
    bool    m_can_read_all_group_messages = false;
    bool    m_supports_inline_queries     = false;
};

void       readJsonObject(User::Ptr& value, const QJsonObject& json, const QString& valueName);
QJsonValue toJsonValue(const User::Ptr& value);
}

#endif // USER_H
