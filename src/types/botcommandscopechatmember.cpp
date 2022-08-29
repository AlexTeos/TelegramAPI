#include "botcommandscopechatmember.h"

namespace Telegram
{
const QString BotCommandScopeChatMember::Type("chat_member");

QJsonObject BotCommandScopeChatMember::toJsonValue()
{
    QJsonObject jsonObject = BotCommandScope::toJsonValue();

    if (std::holds_alternative<qint64>(m_chat_id))
        jsonObject.insert("chat_id", std::get<qint64>(m_chat_id));
    else
        jsonObject.insert("chat_id", std::get<QString>(m_chat_id));

    jsonObject.insert("user_id", m_user_id);

    return jsonObject;
}

bool BotCommandScopeChatMember::readJsonObject(const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        BotCommandScope::readJsonObject(json, valueName);

        QJsonObject object = json[valueName].toObject();

        if (std::holds_alternative<qint64>(m_chat_id))
            Telegram::readJsonObject(std::get<qint64>(m_chat_id), object, "chat_id");
        else
            Telegram::readJsonObject(std::get<QString>(m_chat_id), object, "chat_id");

        Telegram::readJsonObject(m_user_id, object, "user_id");

        return true;
    }

    return false;
}

bool readJsonObject(BotCommandScopeChatMember::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    value = BotCommandScopeChatMember::Ptr::create();

    return value->readJsonObject(json, valueName);
}
}
