#include "menubutton.h"

#include "menubuttoncommands.h"
#include "menubuttondefault.h"
#include "menubuttonwebapp.h"

namespace Telegram
{
bool readJsonObject(MenuButton::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        QJsonObject object = json[valueName].toObject();

        QString type;
        readJsonObject(type, object, "type");

        if (type == "commands")
        {
            MenuButtonCommands::Ptr valuePtr;
            readJsonObject(valuePtr, json, valueName);
            value = valuePtr;
        }
        else if (type == "web_app")
        {
            MenuButtonWebApp::Ptr valuePtr;
            readJsonObject(valuePtr, json, valueName);
            value = valuePtr;
        }
        else if (type == "default")
        {
            MenuButtonDefault::Ptr valuePtr;
            readJsonObject(valuePtr, json, valueName);
            value = valuePtr;
        }
        else
            return false;

        readJsonObject(value->m_type, object, "type");

        return true;
    }

    return false;
}

QJsonObject toJsonValue(const MenuButton::Ptr& value)
{
    QJsonObject jsonObject;

    jsonObject.insert("type", value->m_type);

    return jsonObject;
}
}
