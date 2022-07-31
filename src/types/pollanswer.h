#ifndef POLLANSWER_H
#define POLLANSWER_H

#include "common.h"
#include "user.h"

namespace Telegram
{
struct PollAnswer
{
    typedef QSharedPointer<PollAnswer> Ptr;

    QString         m_poll_id;
    User::Ptr       m_user;
    QVector<qint64> m_option_ids;
};

bool readJsonObject(PollAnswer::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // POLLANSWER_H
