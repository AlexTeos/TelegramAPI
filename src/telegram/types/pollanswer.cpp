#include "pollanswer.h"

namespace TelegramApi
{
void readValue(PollAnswer::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = PollAnswer::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readValue(value->m_poll_id, object, "poll_id");
        readValue(value->m_user, object, "user");
        readValue(value->m_option_ids, object, "option_ids");
    }
}
}
