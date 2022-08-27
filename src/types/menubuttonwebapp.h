#ifndef MENUBUTTONWEBAPP_H
#define MENUBUTTONWEBAPP_H

#include "menubutton.h"
#include "webappinfo.h"

namespace Telegram
{
struct MenuButtonWebApp : public MenuButton
{
    using Ptr = QSharedPointer<MenuButtonWebApp>;
    static const QString Type;

    QString         m_text;
    WebAppInfo::Ptr m_web_app;
};

bool        readJsonObject(MenuButtonWebApp::Ptr& value, const QJsonObject& json, const QString& valueName);
QJsonObject toJsonValue(const MenuButtonWebApp::Ptr& value);
}

#endif // MENUBUTTONWEBAPP_H
