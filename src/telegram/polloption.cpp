#include "polloption.h"

namespace TelegramApi
{
void readValue(PollOption::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = PollOption::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readValue(value->m_text, object, "text");
        readValue(value->m_voter_count, object, "voter_count");
    }
}
}
