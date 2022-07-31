#include "voicechatscheduled.h"

namespace Telegram
{
bool readJsonObject(VoiceChatScheduled::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = VoiceChatScheduled::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readJsonObject(value->m_start_date, object, "start_date");

        return true;
    }

    return false;
}
}
