#include "voicechatparticipantsinvited.h"

namespace Telegram
{
bool readJsonObject(VoiceChatParticipantsInvited::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = VoiceChatParticipantsInvited::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readJsonObject(value->m_users, object, "users");

        return true;
    }

    return false;
}
}
