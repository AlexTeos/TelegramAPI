#include "voicechatscheduled.h"

namespace TelegramApi
{
void readValue(VoiceChatScheduled::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = VoiceChatScheduled::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readValue(value->m_start_date, object, "start_date");
    }
}
}
