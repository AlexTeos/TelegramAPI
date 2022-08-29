#include "menubuttoncommands.h"

namespace Telegram
{
const QString MenuButtonCommands::Type("commands");

QJsonObject MenuButtonCommands::toJsonValue()
{
    return MenuButton::toJsonValue();
}

bool readJsonObject(MenuButtonCommands::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    value = MenuButtonCommands::Ptr::create();

    return value->readJsonObject(json, valueName);
}
}
