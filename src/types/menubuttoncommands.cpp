#include "menubuttoncommands.h"

namespace Telegram
{
const QString MenuButtonCommands::Type("commands");

bool readJsonObject(MenuButtonCommands::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = MenuButtonCommands::Ptr::create();

        return true;
    }

    return false;
}

QJsonObject toJsonValue(const MenuButtonCommands::Ptr& value)
{
    return toJsonValue(value.staticCast<MenuButton>());
}
}
