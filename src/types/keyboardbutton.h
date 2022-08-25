#ifndef KEYBOARDBUTTON_H
#define KEYBOARDBUTTON_H

#include "keyboardbuttonpolltype.h"

namespace Telegram
{
struct KeyboardButton
{
    using Ptr = QSharedPointer<KeyboardButton>;

    QString                     m_text;
    std::optional<bool>         m_request_contact;
    std::optional<bool>         m_request_location;
    KeyboardButtonPollType::Ptr m_request_poll;
};

bool        readJsonObject(KeyboardButton::Ptr& value, const QJsonObject& json, const QString& valueName);
QJsonObject toJsonValue(const KeyboardButton::Ptr& value);
}

#endif // KEYBOARDBUTTON_H
