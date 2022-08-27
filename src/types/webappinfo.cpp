#include "webappinfo.h"

namespace Telegram
{
bool readJsonObject(WebAppInfo::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = WebAppInfo::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readJsonObject(value->m_url, object, "url");

        return true;
    }

    return false;
}

QJsonObject toJsonValue(const WebAppInfo::Ptr& value)
{
    QJsonObject jsonObject;

    jsonObject.insert("url", value->m_url);

    return jsonObject;
}
}
