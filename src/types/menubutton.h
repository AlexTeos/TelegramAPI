#ifndef MENUBUTTON_H
#define MENUBUTTON_H

#include "common.h"

namespace Telegram
{
struct MenuButton
{
    using Ptr = QSharedPointer<MenuButton>;

    QString m_type;

protected:
    virtual bool        readJsonObject(const QJsonObject& json, const QString& valueName);
    virtual QJsonObject toJsonValue();

    friend bool        readJsonObject(MenuButton::Ptr&, const QJsonObject&, const QString&);
    friend QJsonObject toJsonValue(const MenuButton::Ptr&);
};

bool readJsonObject(MenuButton::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // MENUBUTTON_H
