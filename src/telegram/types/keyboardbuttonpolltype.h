#ifndef KEYBOARDBUTTONPOLLTYPE_H
#define KEYBOARDBUTTONPOLLTYPE_H

#include "common.h"

namespace Telegram
{
struct KeyboardButtonPollType
{
    typedef QSharedPointer<KeyboardButtonPollType> Ptr;

    std::optional<QString> m_type;
};

void        readJsonObject(KeyboardButtonPollType::Ptr& value, const QJsonObject& json, const QString& valueName);
QJsonObject toJsonValue(const KeyboardButtonPollType::Ptr& value);
}
#endif // KEYBOARDBUTTONPOLLTYPE_H
