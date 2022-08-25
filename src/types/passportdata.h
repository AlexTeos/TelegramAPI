#ifndef PASSPORTDATA_H
#define PASSPORTDATA_H

#include "encryptedcredentials.h"
#include "encryptedpassportelement.h"

namespace Telegram
{
struct PassportData
{
    using Ptr = QSharedPointer<PassportData>;

    QVector<EncryptedPassportElement::Ptr> m_data;
    EncryptedCredentials::Ptr              m_credentials;
};

bool readJsonObject(PassportData::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // PASSPORTDATA_H
