#ifndef ENCRYPTEDCREDENTIALS_H
#define ENCRYPTEDCREDENTIALS_H

#include "common.h"

namespace TelegramApi
{
struct EncryptedCredentials
{
    typedef QSharedPointer<EncryptedCredentials> Ptr;

    QString m_data;
    QString m_hash;
    QString m_secret;
};

void readValue(EncryptedCredentials::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // ENCRYPTEDCREDENTIALS_H
