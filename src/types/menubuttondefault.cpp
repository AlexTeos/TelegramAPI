#include "menubuttondefault.h"

namespace Telegram
{
const QString MenuButtonDefault::Type("default");

QJsonObject MenuButtonDefault::toJsonValue()
{
    return MenuButton::toJsonValue();
}

bool readJsonObject(MenuButtonDefault::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    value = MenuButtonDefault::Ptr::create();

    return value->readJsonObject(json, valueName);
}
}
