#ifndef CHATLOCATION_H
#define CHATLOCATION_H

#include "common.h"
#include "location.h"

namespace TelegramApi
{
struct ChatLocation
{
    typedef QSharedPointer<ChatLocation> Ptr;

    Location::Ptr m_location;
    QString       m_address;
};

void readValue(ChatLocation::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // CHATLOCATION_H
