#ifndef MENUBUTTONCOMMANDS_H
#define MENUBUTTONCOMMANDS_H

#include "menubutton.h"

namespace Telegram
{
struct MenuButtonCommands : public MenuButton
{
    using Ptr = QSharedPointer<MenuButtonCommands>;
    static const QString Type;

    friend bool readJsonObject(MenuButtonCommands::Ptr&, const QJsonObject&, const QString&);

    QJsonObject toJsonValue();
};

bool readJsonObject(MenuButtonCommands::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // MENUBUTTONCOMMANDS_H
