#include "voicechatstarted.h"

namespace Telegram
{
bool readJsonObject(VoiceChatStarted::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = VoiceChatStarted::Ptr::create();

        return true;
    }

    return false;
}
}
