#ifndef LOGINURL_H
#define LOGINURL_H

#include "common.h"

namespace Telegram
{
struct LoginUrl
{
    typedef QSharedPointer<LoginUrl> Ptr;

    QString m_url;
    QString m_forward_text;
    QString m_bot_username;
    bool    m_request_write_access = false;
};

void       readJsonObject(LoginUrl::Ptr& value, const QJsonObject& json, const QString& valueName);
QJsonValue toJsonValue(const LoginUrl::Ptr& value);
}
#endif // LOGINURL_H
