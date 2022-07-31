#include "pollanswer.h"

namespace Telegram
{
bool readJsonObject(PollAnswer::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = PollAnswer::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readJsonObject(value->m_poll_id, object, "poll_id");
        readJsonObject(value->m_user, object, "user");
        readJsonObject(value->m_option_ids, object, "option_ids");

        return true;
    }

    return false;
}
}
