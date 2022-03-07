#ifndef VOICECHATPARTICIPANTSINVITED_H
#define VOICECHATPARTICIPANTSINVITED_H

#include "common.h"
#include "user.h"

namespace Telegram
{
struct VoiceChatParticipantsInvited
{
    typedef QSharedPointer<VoiceChatParticipantsInvited> Ptr;

    QVector<User::Ptr> m_users;
};

void readJsonObject(VoiceChatParticipantsInvited::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // VOICECHATPARTICIPANTSINVITED_H
