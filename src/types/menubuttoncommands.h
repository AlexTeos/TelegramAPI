#ifndef MENUBUTTONCOMMANDS_H
#define MENUBUTTONCOMMANDS_H

#include "menubutton.h"

namespace Telegram
{
struct MenuButtonCommands : public MenuButton
{
    using Ptr = QSharedPointer<MenuButtonCommands>;
    static const QString Type;
};

bool        readJsonObject(MenuButtonCommands::Ptr& value, const QJsonObject& json, const QString& valueName);
QJsonObject toJsonValue(const MenuButtonCommands::Ptr& value);
}
#endif // MENUBUTTONCOMMANDS_H
