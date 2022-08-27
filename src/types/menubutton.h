#ifndef MENUBUTTON_H
#define MENUBUTTON_H

#include "common.h"

namespace Telegram
{
struct MenuButton
{
    using Ptr = QSharedPointer<MenuButton>;

    QString m_type;
};

bool        readJsonObject(MenuButton::Ptr& value, const QJsonObject& json, const QString& valueName);
QJsonObject toJsonValue(const MenuButton::Ptr& value);
}

#endif // MENUBUTTON_H
