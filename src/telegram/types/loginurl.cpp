#include "loginurl.h"

namespace Telegram
{
void readJsonObject(LoginUrl::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = LoginUrl::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readJsonObject(value->m_url, object, "url");
        readJsonObject(value->m_forward_text, object, "forward_text");
        readJsonObject(value->m_bot_username, object, "bot_username");
        readJsonObject(value->m_request_write_access, object, "request_write_access");
    }
}

QJsonValue toJsonValue(const LoginUrl::Ptr& value)
{
    QJsonObject jsonObject;

    jsonObject.insert("url", value->m_url);
    if (value->m_forward_text) jsonObject.insert("forward_text", value->m_forward_text.value());
    if (value->m_bot_username) jsonObject.insert("bot_username", value->m_bot_username.value());
    if (value->m_request_write_access) jsonObject.insert("request_write_access", value->m_request_write_access.value());

    return jsonObject;
}
}
