#ifndef ENCRYPTEDCREDENTIALS_H
#define ENCRYPTEDCREDENTIALS_H

#include "common.h"

namespace Telegram
{
struct EncryptedCredentials
{
    typedef QSharedPointer<EncryptedCredentials> Ptr;

    QString m_data;
    QString m_hash;
    QString m_secret;
};

bool readJsonObject(EncryptedCredentials::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // ENCRYPTEDCREDENTIALS_H
