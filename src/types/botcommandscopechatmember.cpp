#include "botcommandscopechatmember.h"

namespace Telegram
{
const QString BotCommandScopeChatMember::Type("chat_member");

bool readJsonObject(BotCommandScopeChatMember::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = BotCommandScopeChatMember::Ptr::create();

        return true;
    }

    return false;
}

QJsonObject toJsonValue(const BotCommandScopeChatMember::Ptr& value)
{
    QJsonObject jsonObject = toJsonValue(value.staticCast<BotCommandScope>());

    if (std::holds_alternative<qint64>(value->m_chat_id))
        jsonObject.insert("chat_id", std::get<qint64>(value->m_chat_id));
    else
        jsonObject.insert("chat_id", std::get<QString>(value->m_chat_id));

    jsonObject.insert("user_id", value->m_user_id);

    return jsonObject;
}
}
