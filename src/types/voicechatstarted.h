#ifndef VOICECHATSTARTED_H
#define VOICECHATSTARTED_H

#include "common.h"

namespace Telegram
{
struct VoiceChatStarted
{
    using Ptr = QSharedPointer<VoiceChatStarted>;
};

bool readJsonObject(VoiceChatStarted::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // VOICECHATSTARTED_H
