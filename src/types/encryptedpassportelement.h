#ifndef ENCRYPTEDPASSPORTELEMENT_H
#define ENCRYPTEDPASSPORTELEMENT_H

#include "passportfile.h"

namespace Telegram
{
struct EncryptedPassportElement
{
    using Ptr = QSharedPointer<EncryptedPassportElement>;

    QString                    m_type;
    std::optional<QString>     m_data;
    std::optional<QString>     m_phone_number;
    std::optional<QString>     m_email;
    QVector<PassportFile::Ptr> m_files;
    PassportFile::Ptr          m_front_side;
    PassportFile::Ptr          m_reverse_side;
    PassportFile::Ptr          m_selfie;
    QVector<PassportFile::Ptr> m_translation;
    QString                    m_hash;
};

bool readJsonObject(EncryptedPassportElement::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // ENCRYPTEDPASSPORTELEMENT_H
