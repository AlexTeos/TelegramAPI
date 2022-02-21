#include "loginurl.h"

namespace TelegramApi
{
void readValue(LoginUrl::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = LoginUrl::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readValue(value->m_url, object, "url");
        readValue(value->m_forward_text, object, "forward_text");
        readValue(value->m_bot_username, object, "bot_username");
        readValue(value->m_request_write_access, object, "request_write_access");
    }
}
}
