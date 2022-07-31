#ifndef VOICECHATSCHEDULED_H
#define VOICECHATSCHEDULED_H

#include "common.h"
#include "photosize.h"

namespace Telegram
{
struct VoiceChatScheduled
{
    typedef QSharedPointer<VoiceChatScheduled> Ptr;

    qint64 m_start_date = 0;
};

bool readJsonObject(VoiceChatScheduled::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // VOICECHATSCHEDULED_H
