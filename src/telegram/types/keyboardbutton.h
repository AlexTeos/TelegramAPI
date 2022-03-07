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
    bool                        m_request_contact  = false;
    bool                        m_request_location = false;
    KeyboardButtonPollType::Ptr m_request_poll;
};

void        readJsonObject(KeyboardButton::Ptr& value, const QJsonObject& json, const QString& valueName);
QJsonObject toJsonValue(const KeyboardButton::Ptr& value);
}

#endif // KEYBOARDBUTTON_H
