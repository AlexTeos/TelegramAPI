#ifndef PASSPORTDATA_H
#define PASSPORTDATA_H

#include "common.h"
#include "encryptedcredentials.h"
#include "encryptedpassportelement.h"

namespace TelegramApi
{
struct PassportData
{
    typedef QSharedPointer<PassportData> Ptr;

    QVector<EncryptedPassportElement::Ptr> m_data;
    EncryptedCredentials::Ptr              m_credentials;
};

void readValue(PassportData::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // PASSPORTDATA_H
