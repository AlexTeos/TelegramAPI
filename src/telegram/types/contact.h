#ifndef CONTACT_H
#define CONTACT_H

#include "common.h"

namespace Telegram
{
struct Contact
{
    typedef QSharedPointer<Contact> Ptr;

    QString m_phone_number;
    QString m_first_name;
    QString m_last_name;
    qint64  m_user_id = 0;
    QString m_vcard;
};

void readJsonObject(Contact::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // CONTACT_H
