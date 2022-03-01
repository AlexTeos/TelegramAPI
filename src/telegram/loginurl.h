#ifndef LOGINURL_H
#define LOGINURL_H

#include "common.h"

namespace TelegramApi
{
struct LoginUrl
{
    typedef QSharedPointer<LoginUrl> Ptr;

    QString m_url;
    QString m_forward_text;
    QString m_bot_username;
    bool    m_request_write_access = false;
};

void readValue(LoginUrl::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // LOGINURL_H
