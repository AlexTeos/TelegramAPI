#ifndef POLL_H
#define POLL_H

#include "common.h"
#include "messageentity.h"
#include "polloption.h"

namespace Telegram
{
struct Poll
{
    typedef QSharedPointer<Poll> Ptr;

    QString                     m_id;
    QString                     m_question;
    QVector<PollOption::Ptr>    m_options;
    qint64                      m_total_voter_count = 0;
    bool                        m_is_closed         = false;
    bool                        m_is_anonymous      = false;
    QString                     m_type;
    bool                        m_allows_multiple_answers = false;
    qint64                      m_correct_option_id       = false;
    QString                     m_explanation;
    QVector<MessageEntity::Ptr> m_explanation_entities;
    qint64                      m_open_period = false;
    qint64                      m_close_date  = false;
};

void readJsonObject(Poll::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // POLL_H
