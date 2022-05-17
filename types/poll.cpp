#include "poll.h"

namespace Telegram
{
bool readJsonObject(Poll::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = Poll::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readJsonObject(value->m_id, object, "id");
        readJsonObject(value->m_question, object, "file_unique_id");
        readJsonObject(value->m_options, object, "options");
        readJsonObject(value->m_total_voter_count, object, "total_voter_count");
        readJsonObject(value->m_is_closed, object, "is_closed");
        readJsonObject(value->m_is_anonymous, object, "is_anonymous");
        readJsonObject(value->m_type, object, "type");
        readJsonObject(value->m_allows_multiple_answers, object, "allows_multiple_answers");
        readJsonObject(value->m_correct_option_id, object, "correct_option_id");
        readJsonObject(value->m_explanation, object, "explanation");
        readJsonObject(value->m_explanation_entities, object, "explanation_entities");
        readJsonObject(value->m_open_period, object, "open_period");

        return true;
    }

    return false;
}
}
