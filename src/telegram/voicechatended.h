#ifndef VOICECHATENDED_H
#define VOICECHATENDED_H

#include "common.h"

namespace TelegramApi
{
struct VoiceChatEnded
{
    typedef QSharedPointer<VoiceChatEnded> Ptr;

    int32_t m_duration;
};

void readValue(VoiceChatEnded::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // VOICECHATENDED_H
