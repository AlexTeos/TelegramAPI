#ifndef POLLANSWER_H
#define POLLANSWER_H

#include "common.h"
#include "user.h"

namespace TelegramApi
{
struct PollAnswer
{
    typedef QSharedPointer<PollAnswer> Ptr;

    QString          m_poll_id;
    User::Ptr        m_user;
    QVector<int32_t> m_option_ids;
};

void readValue(PollAnswer::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // POLLANSWER_H
