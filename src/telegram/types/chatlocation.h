#ifndef CHATLOCATION_H
#define CHATLOCATION_H

#include "common.h"
#include "location.h"

namespace Telegram
{
struct ChatLocation
{
    typedef QSharedPointer<ChatLocation> Ptr;

    Location::Ptr m_location;
    QString       m_address;
};

void readJsonObject(ChatLocation::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // CHATLOCATION_H
