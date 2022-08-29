#include "botcommandscopechat.h"

namespace Telegram
{
const QString BotCommandScopeChat::Type("chat");

QJsonObject BotCommandScopeChat::toJsonValue()
{
    QJsonObject jsonObject = BotCommandScope::toJsonValue();

    if (std::holds_alternative<qint64>(m_chat_id))
        jsonObject.insert("chat_id", std::get<qint64>(m_chat_id));
    else
        jsonObject.insert("chat_id", std::get<QString>(m_chat_id));

    return jsonObject;
}

bool BotCommandScopeChat::readJsonObject(const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        BotCommandScope::readJsonObject(json, valueName);

        QJsonObject object = json[valueName].toObject();

        if (std::holds_alternative<qint64>(m_chat_id))
            Telegram::readJsonObject(std::get<qint64>(m_chat_id), object, "chat_id");
        else
            Telegram::readJsonObject(std::get<QString>(m_chat_id), object, "chat_id");

        return true;
    }

    return false;
}

bool readJsonObject(BotCommandScopeChat::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    value = BotCommandScopeChat::Ptr::create();

    return value->readJsonObject(json, valueName);
}
}
