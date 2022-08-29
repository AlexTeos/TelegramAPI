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

    bool readJsonObject(const QJsonObject& json, const QString& valueName);

    QString         m_text;
    WebAppInfo::Ptr m_web_app;

    friend bool readJsonObject(MenuButtonWebApp::Ptr&, const QJsonObject&, const QString&);

protected:
    virtual QJsonObject toJsonValue();
};

bool readJsonObject(MenuButtonWebApp::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // MENUBUTTONWEBAPP_H
