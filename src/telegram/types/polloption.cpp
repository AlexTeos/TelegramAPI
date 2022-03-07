#include "polloption.h"

namespace Telegram
{
void readJsonObject(PollOption::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = PollOption::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readJsonObject(value->m_text, object, "text");
        readJsonObject(value->m_voter_count, object, "voter_count");
    }
}
}
