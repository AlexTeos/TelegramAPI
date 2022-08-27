#include "botcommand.h"

namespace Telegram
{
bool readJsonObject(BotCommand::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = BotCommand::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readJsonObject(value->m_command, object, "command");
        readJsonObject(value->m_description, object, "description");

        return true;
    }

    return false;
}

QJsonObject toJsonValue(const BotCommand::Ptr& value)
{
    QJsonObject jsonObject;

    jsonObject.insert("command", value->m_command);
    jsonObject.insert("description", value->m_description);

    return jsonObject;
}
}
