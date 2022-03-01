#ifndef POLL_H
#define POLL_H

#include "common.h"
#include "messageentity.h"
#include "polloption.h"

namespace TelegramApi
{
struct Poll
{
    typedef QSharedPointer<Poll> Ptr;

    QString                     m_id;
    QString                     m_question;
    QVector<PollOption::Ptr>    m_options;
    int32_t                     m_total_voter_count = 0;
    bool                        m_is_closed         = false;
    bool                        m_is_anonymous      = false;
    QString                     m_type;
    bool                        m_allows_multiple_answers = false;
    int32_t                     m_correct_option_id       = false;
    QString                     m_explanation;
    QVector<MessageEntity::Ptr> m_explanation_entities;
    int32_t                     m_open_period = false;
    int32_t                     m_close_date  = false;
};

void readValue(Poll::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // POLL_H
