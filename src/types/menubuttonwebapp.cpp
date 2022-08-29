#include "menubuttonwebapp.h"

namespace Telegram
{
const QString MenuButtonWebApp::Type("web_app");

QJsonObject MenuButtonWebApp::toJsonValue()
{
    QJsonObject jsonObject = MenuButton::toJsonValue();

    jsonObject.insert("text", m_text);
    jsonObject.insert("web_app", Telegram::toJsonValue(m_web_app));

    return jsonObject;
}

bool MenuButtonWebApp::readJsonObject(const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        MenuButtonWebApp::readJsonObject(json, valueName);

        QJsonObject object = json[valueName].toObject();

        Telegram::readJsonObject(m_text, object, "text");
        Telegram::readJsonObject(m_web_app, object, "web_app");

        return true;
    }

    return false;
}

bool readJsonObject(MenuButtonWebApp::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    value = MenuButtonWebApp::Ptr::create();

    return value->readJsonObject(json, valueName);
}
}
