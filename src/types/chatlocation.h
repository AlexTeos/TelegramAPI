#ifndef CHATLOCATION_H
#define CHATLOCATION_H

#include "location.h"

namespace Telegram
{
struct ChatLocation
{
    using Ptr = QSharedPointer<ChatLocation>;

    Location::Ptr m_location;
    QString       m_address;
};

bool readJsonObject(ChatLocation::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // CHATLOCATION_H
