#include "menubuttondefault.h"

namespace Telegram
{
const QString MenuButtonDefault::Type("default");

bool readJsonObject(MenuButtonDefault::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = MenuButtonDefault::Ptr::create();

        return true;
    }

    return false;
}

QJsonObject toJsonValue(const MenuButtonDefault::Ptr& value)
{
    return toJsonValue(value.staticCast<MenuButton>());
}
}
