#ifndef MENUBUTTONDEFAULT_H
#define MENUBUTTONDEFAULT_H

#include "menubutton.h"

namespace Telegram
{
struct MenuButtonDefault : public MenuButton
{
    using Ptr = QSharedPointer<MenuButtonDefault>;
    static const QString Type;

    friend bool readJsonObject(MenuButtonDefault::Ptr&, const QJsonObject&, const QString&);

    QJsonObject toJsonValue();
};

bool readJsonObject(MenuButtonDefault::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // MENUBUTTONDEFAULT_H
