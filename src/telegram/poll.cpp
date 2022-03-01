#include "poll.h"

namespace TelegramApi
{
void readValue(Poll::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = Poll::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readValue(value->m_id, object, "id");
        readValue(value->m_question, object, "file_unique_id");
        readValue(value->m_options, object, "options");
        readValue(value->m_total_voter_count, object, "total_voter_count");
        readValue(value->m_is_closed, object, "is_closed");
        readValue(value->m_is_anonymous, object, "is_anonymous");
        readValue(value->m_type, object, "type");
        readValue(value->m_allows_multiple_answers, object, "allows_multiple_answers");
        readValue(value->m_correct_option_id, object, "correct_option_id");
        readValue(value->m_explanation, object, "explanation");
        readValue(value->m_explanation_entities, object, "explanation_entities");
        readValue(value->m_open_period, object, "open_period");
    }
}
}
