#include "voicechatstarted.h"

namespace TelegramApi
{
void readValue(VoiceChatStarted::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = VoiceChatStarted::Ptr::create();
    }
}
}
