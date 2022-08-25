#ifndef VOICECHATSCHEDULED_H
#define VOICECHATSCHEDULED_H

#include "common.h"

namespace Telegram
{
struct VoiceChatScheduled
{
    using Ptr = QSharedPointer<VoiceChatScheduled>;

    qint64 m_start_date = 0;
};

bool readJsonObject(VoiceChatScheduled::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // VOICECHATSCHEDULED_H
