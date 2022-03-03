#ifndef VOICECHATSTARTED_H
#define VOICECHATSTARTED_H

#include "common.h"

namespace TelegramApi
{
struct VoiceChatStarted
{
    typedef QSharedPointer<VoiceChatStarted> Ptr;
};

void readValue(VoiceChatStarted::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // VOICECHATSTARTED_H
