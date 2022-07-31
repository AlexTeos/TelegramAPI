#ifndef PASSPORTDATA_H
#define PASSPORTDATA_H

#include "common.h"
#include "encryptedcredentials.h"
#include "encryptedpassportelement.h"

namespace Telegram
{
struct PassportData
{
    typedef QSharedPointer<PassportData> Ptr;

    QVector<EncryptedPassportElement::Ptr> m_data;
    EncryptedCredentials::Ptr              m_credentials;
};

bool readJsonObject(PassportData::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // PASSPORTDATA_H
