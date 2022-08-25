#ifndef MESSAGEAUTODELETETIMERCHANGED_H
#define MESSAGEAUTODELETETIMERCHANGED_H

#include "common.h"

namespace Telegram
{
struct MessageAutoDeleteTimerChanged
{
    using Ptr = QSharedPointer<MessageAutoDeleteTimerChanged>;

    qint64 m_message_auto_delete_time;
};

bool readJsonObject(MessageAutoDeleteTimerChanged::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // MESSAGEAUTODELETETIMERCHANGED_H
