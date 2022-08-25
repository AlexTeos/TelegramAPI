#ifndef KEYBOARDBUTTONPOLLTYPE_H
#define KEYBOARDBUTTONPOLLTYPE_H

#include "common.h"

namespace Telegram
{
struct KeyboardButtonPollType
{
    using Ptr = QSharedPointer<KeyboardButtonPollType>;

    std::optional<QString> m_type;
};

bool        readJsonObject(KeyboardButtonPollType::Ptr& value, const QJsonObject& json, const QString& valueName);
QJsonObject toJsonValue(const KeyboardButtonPollType::Ptr& value);
}
#endif // KEYBOARDBUTTONPOLLTYPE_H
