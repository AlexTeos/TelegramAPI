#ifndef MESSAGEAUTODELETETIMERCHANGED_H
#define MESSAGEAUTODELETETIMERCHANGED_H

#include "common.h"

namespace TelegramApi
{
struct MessageAutoDeleteTimerChanged
{
    typedef QSharedPointer<MessageAutoDeleteTimerChanged> Ptr;

    int32_t m_message_auto_delete_time = 0;
};

void readValue(MessageAutoDeleteTimerChanged::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // MESSAGEAUTODELETETIMERCHANGED_H
