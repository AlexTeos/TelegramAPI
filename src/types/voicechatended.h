#ifndef VOICECHATENDED_H
#define VOICECHATENDED_H

#include "common.h"

namespace Telegram
{
struct VoiceChatEnded
{
    using Ptr = QSharedPointer<VoiceChatEnded>;

    qint64 m_duration;
};

bool readJsonObject(VoiceChatEnded::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // VOICECHATENDED_H
