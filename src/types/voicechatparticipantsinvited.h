#ifndef VOICECHATPARTICIPANTSINVITED_H
#define VOICECHATPARTICIPANTSINVITED_H

#include "user.h"

namespace Telegram
{
struct VoiceChatParticipantsInvited
{
    using Ptr = QSharedPointer<VoiceChatParticipantsInvited>;

    QVector<User::Ptr> m_users;
};

bool readJsonObject(VoiceChatParticipantsInvited::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // VOICECHATPARTICIPANTSINVITED_H
