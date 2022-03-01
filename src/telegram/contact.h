#ifndef CONTACT_H
#define CONTACT_H

#include "common.h"

namespace TelegramApi
{
struct Contact
{
    typedef QSharedPointer<Contact> Ptr;

    QString m_phone_number;
    QString m_first_name;
    QString m_last_name;
    int32_t m_user_id = 0;
    QString m_vcard;
};

void readValue(Contact::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // CONTACT_H
