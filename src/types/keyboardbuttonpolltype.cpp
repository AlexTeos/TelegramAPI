#include "keyboardbuttonpolltype.h"

namespace Telegram
{
bool readJsonObject(KeyboardButtonPollType::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = KeyboardButtonPollType::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readJsonObject(value->m_type, object, "type");

        return true;
    }

    return false;
}

QJsonObject toJsonValue(const KeyboardButtonPollType::Ptr& value)
{
    QJsonObject jsonObject;

    if (value->m_type) jsonObject.insert("type", value->m_type.value());

    return jsonObject;
}
}
