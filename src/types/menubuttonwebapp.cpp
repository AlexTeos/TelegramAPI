#include "menubuttonwebapp.h"

namespace Telegram
{
const QString MenuButtonWebApp::Type("web_app");

bool readJsonObject(MenuButtonWebApp::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = MenuButtonWebApp::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readJsonObject(value->m_text, object, "text");
        readJsonObject(value->m_web_app, object, "web_app");

        return true;
    }

    return false;
}

QJsonObject toJsonValue(const MenuButtonWebApp::Ptr& value)
{
    QJsonObject jsonObject = toJsonValue(value.staticCast<MenuButton>());

    jsonObject.insert("text", value->m_text);
    jsonObject.insert("web_app", toJsonValue(value->m_web_app));

    return jsonObject;
}
}
