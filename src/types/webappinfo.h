#ifndef WEBAPPINFO_H
#define WEBAPPINFO_H

#include "common.h"

namespace Telegram
{
struct WebAppInfo
{
    using Ptr = QSharedPointer<WebAppInfo>;

    QString m_url;
};

bool        readJsonObject(WebAppInfo::Ptr& value, const QJsonObject& json, const QString& valueName);
QJsonObject toJsonValue(const WebAppInfo::Ptr& value);
}
#endif // WEBAPPINFO_H
