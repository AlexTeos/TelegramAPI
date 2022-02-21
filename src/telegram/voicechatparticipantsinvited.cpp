#include "voicechatparticipantsinvited.h"

namespace TelegramApi
{
void readValue(VoiceChatParticipantsInvited::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = VoiceChatParticipantsInvited::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readArray(value->m_users, object, "users");
    }
}
}
