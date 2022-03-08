#ifndef VOICECHATENDED_H
#define VOICECHATENDED_H

#include "common.h"

namespace Telegram
{
struct VoiceChatEnded
{
    typedef QSharedPointer<VoiceChatEnded> Ptr;

    qint64 m_duration;
};

void readJsonObject(VoiceChatEnded::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // VOICECHATENDED_H
