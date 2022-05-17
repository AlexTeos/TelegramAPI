#include "keyboardbutton.h"

namespace Telegram
{
bool readJsonObject(KeyboardButton::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = KeyboardButton::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readJsonObject(value->m_text, object, "text");
        readJsonObject(value->m_request_contact, object, "request_contact");
        readJsonObject(value->m_request_location, object, "request_location");
        readJsonObject(value->m_request_poll, object, "request_poll");

        return true;
    }

    return false;
}

QJsonObject toJsonValue(const KeyboardButton::Ptr& value)
{
    QJsonObject jsonObject;

    jsonObject.insert("text", value->m_text);
    if (value->m_request_contact) jsonObject.insert("request_contact", value->m_request_contact.value());
    if (value->m_request_location) jsonObject.insert("request_location", value->m_request_location.value());
    if (value->m_request_poll) jsonObject.insert("request_poll", toJsonValue(value->m_request_poll));

    return jsonObject;
}
}
