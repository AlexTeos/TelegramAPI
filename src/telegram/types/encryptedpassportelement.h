#ifndef ENCRYPTEDPASSPORTELEMENT_H
#define ENCRYPTEDPASSPORTELEMENT_H

#include "common.h"
#include "passportfile.h"

namespace Telegram
{
struct EncryptedPassportElement
{
    typedef QSharedPointer<EncryptedPassportElement> Ptr;

    QString                    m_type;
    QString                    m_data;
    QString                    m_phone_number;
    QString                    m_email;
    QVector<PassportFile::Ptr> m_files;
    PassportFile::Ptr          m_front_side;
    PassportFile::Ptr          m_reverse_side;
    PassportFile::Ptr          m_selfie;
    QVector<PassportFile::Ptr> m_translation;
    QString                    m_hash;
};

void readJsonObject(EncryptedPassportElement::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // ENCRYPTEDPASSPORTELEMENT_H
