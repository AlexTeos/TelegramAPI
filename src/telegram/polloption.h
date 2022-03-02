#ifndef POLLOPTION_H
#define POLLOPTION_H

#include "common.h"

namespace TelegramApi
{
struct PollOption
{
    typedef QSharedPointer<PollOption> Ptr;

    QString m_text;
    qint64  m_voter_count = 0;
};

void readValue(PollOption::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // POLLOPTION_H
