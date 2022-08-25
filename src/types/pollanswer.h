#ifndef POLLANSWER_H
#define POLLANSWER_H

#include "user.h"

namespace Telegram
{
struct PollAnswer
{
    using Ptr = QSharedPointer<PollAnswer>;

    QString         m_poll_id;
    User::Ptr       m_user;
    QVector<qint64> m_option_ids;
};

bool readJsonObject(PollAnswer::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // POLLANSWER_H
