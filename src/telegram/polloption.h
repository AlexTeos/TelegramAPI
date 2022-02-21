#ifndef POLLOPTION_H
#define POLLOPTION_H

#include "common.h"

namespace TelegramApi
{
struct PollOption
{
    typedef QSharedPointer<PollOption> Ptr;

    QString m_text;
    int32_t m_voter_count;
};

void readValue(PollOption::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // POLLOPTION_H
