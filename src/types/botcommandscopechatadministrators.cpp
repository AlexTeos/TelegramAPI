#include "botcommandscopechatadministrators.h"

namespace Telegram
{
const QString BotCommandScopeChatAdministrators::Type("chat_administrators");

bool readJsonObject(BotCommandScopeChatAdministrators::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = BotCommandScopeChatAdministrators::Ptr::create();

        return true;
    }

    return false;
}

QJsonObject toJsonValue(const BotCommandScopeChatAdministrators::Ptr& value)
{
    QJsonObject jsonObject = toJsonValue(value.staticCast<BotCommandScope>());

    if (std::holds_alternative<qint64>(value->m_chat_id))
        jsonObject.insert("chat_id", std::get<qint64>(value->m_chat_id));
    else
        jsonObject.insert("chat_id", std::get<QString>(value->m_chat_id));

    return jsonObject;
}
}
