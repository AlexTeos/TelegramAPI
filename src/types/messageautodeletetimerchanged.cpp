#include "messageautodeletetimerchanged.h"

namespace Telegram
{
bool readJsonObject(MessageAutoDeleteTimerChanged::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = MessageAutoDeleteTimerChanged::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readJsonObject(value->m_message_auto_delete_time, object, "message_auto_delete_time");

        return true;
    }

    return false;
}
}
