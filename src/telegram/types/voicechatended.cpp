#include "voicechatended.h"

namespace TelegramApi
{
void readValue(VoiceChatEnded::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = VoiceChatEnded::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readValue(value->m_duration, object, "duration");
    }
}
}
