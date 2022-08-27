#include "botcommandscopechat.h"

namespace Telegram
{
const QString BotCommandScopeChat::Type("chat");

bool readJsonObject(BotCommandScopeChat::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = BotCommandScopeChat::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        if (std::holds_alternative<qint64>(value->m_chat_id))
            readJsonObject(std::get<qint64>(value->m_chat_id), object, "m_chat_id");
        else
            readJsonObject(std::get<QString>(value->m_chat_id), object, "m_chat_id");

        return true;
    }

    return false;
}

QJsonObject toJsonValue(const BotCommandScopeChat::Ptr& value)
{
    QJsonObject jsonObject = toJsonValue(value.staticCast<BotCommandScope>());

    if (std::holds_alternative<qint64>(value->m_chat_id))
        jsonObject.insert("chat_id", std::get<qint64>(value->m_chat_id));
    else
        jsonObject.insert("chat_id", std::get<QString>(value->m_chat_id));

    return jsonObject;
}
}
