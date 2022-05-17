#ifndef POLLOPTION_H
#define POLLOPTION_H

#include "common.h"

namespace Telegram
{
struct PollOption
{
    typedef QSharedPointer<PollOption> Ptr;

    QString m_text;
    qint64  m_voter_count;
};

bool readJsonObject(PollOption::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // POLLOPTION_H
