#include "menubutton.h"

namespace Telegram
{
bool MenuButton::readJsonObject(const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        QJsonObject object = json[valueName].toObject();

        Telegram::readJsonObject(m_type, object, "type");

        return true;
    }

    return false;
}

QJsonObject MenuButton::toJsonValue()
{
    QJsonObject jsonObject;

    jsonObject.insert("type", m_type);

    return jsonObject;
}

QJsonObject toJsonValue(const MenuButton::Ptr& value)
{
    return value->toJsonValue();
}

bool readJsonObject(MenuButton::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    value = MenuButton::Ptr::create();

    return value->readJsonObject(json, valueName);
}
}
