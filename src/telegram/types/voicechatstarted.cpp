#include "voicechatstarted.h"

namespace Telegram
{
void readJsonObject(VoiceChatStarted::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = VoiceChatStarted::Ptr::create();
    }
}
}
