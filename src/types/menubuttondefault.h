#ifndef MENUBUTTONDEFAULT_H
#define MENUBUTTONDEFAULT_H

#include "menubutton.h"

namespace Telegram
{
struct MenuButtonDefault : public MenuButton
{
    using Ptr = QSharedPointer<MenuButtonDefault>;
    static const QString Type;
};

bool        readJsonObject(MenuButtonDefault::Ptr& value, const QJsonObject& json, const QString& valueName);
QJsonObject toJsonValue(const MenuButtonDefault::Ptr& value);
}
#endif // MENUBUTTONDEFAULT_H
