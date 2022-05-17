#include "voicechatended.h"

namespace Telegram
{
bool readJsonObject(VoiceChatEnded::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = VoiceChatEnded::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readJsonObject(value->m_duration, object, "duration");

        return true;
    }

    return false;
}
}
