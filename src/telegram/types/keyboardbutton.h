#ifndef KEYBOARDBUTTON_H
#define KEYBOARDBUTTON_H

#include "common.h"
#include "keyboardbuttonpolltype.h"

namespace Telegram
{
struct KeyboardButton
{
    typedef QSharedPointer<KeyboardButton> Ptr;

    QString                     m_text;
    std::optional<bool>         m_request_contact;
    std::optional<bool>         m_request_location;
    KeyboardButtonPollType::Ptr m_request_poll;
};

void        readJsonObject(KeyboardButton::Ptr& value, const QJsonObject& json, const QString& valueName);
QJsonObject toJsonValue(const KeyboardButton::Ptr& value);
}

#endif // KEYBOARDBUTTON_H
