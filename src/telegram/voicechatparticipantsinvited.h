#ifndef VOICECHATPARTICIPANTSINVITED_H
#define VOICECHATPARTICIPANTSINVITED_H

#include "common.h"
#include "user.h"

namespace TelegramApi
{
struct VoiceChatParticipantsInvited
{
    typedef QSharedPointer<VoiceChatParticipantsInvited> Ptr;

    QVector<User::Ptr> m_users;
};

void readValue(VoiceChatParticipantsInvited::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // VOICECHATPARTICIPANTSINVITED_H
