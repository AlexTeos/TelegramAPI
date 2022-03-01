#ifndef VOICECHATSCHEDULED_H
#define VOICECHATSCHEDULED_H

#include "common.h"
#include "photosize.h"

namespace TelegramApi
{
struct VoiceChatScheduled
{
    typedef QSharedPointer<VoiceChatScheduled> Ptr;

    int32_t m_start_date = 0;
};

void readValue(VoiceChatScheduled::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // VOICECHATSCHEDULED_H
