#include "botcommandscope.h"

#include "botcommandscopeallchatadministrators.h"
#include "botcommandscopeallgroupchats.h"
#include "botcommandscopeallprivatechats.h"
#include "botcommandscopechat.h"
#include "botcommandscopechatadministrators.h"
#include "botcommandscopechatmember.h"
#include "botcommandscopedefault.h"

namespace Telegram
{
bool readJsonObject(BotCommandScope::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        QJsonObject object = json[valueName].toObject();

        QString type;
        readJsonObject(type, object, "type");

        if (type == BotCommandScopeDefault::Type)
        {
            BotCommandScopeDefault::Ptr valuePtr;
            readJsonObject(valuePtr, json, valueName);
            value = valuePtr;
        }
        else if (type == BotCommandScopeAllPrivateChats::Type)
        {
            BotCommandScopeAllPrivateChats::Ptr valuePtr;
            readJsonObject(valuePtr, json, valueName);
            value = valuePtr;
        }
        else if (type == BotCommandScopeAllGroupChats::Type)
        {
            BotCommandScopeAllGroupChats::Ptr valuePtr;
            readJsonObject(valuePtr, json, valueName);
            value = valuePtr;
        }
        else if (type == BotCommandScopeAllChatAdministrators::Type)
        {
            BotCommandScopeAllChatAdministrators::Ptr valuePtr;
            readJsonObject(valuePtr, json, valueName);
            value = valuePtr;
        }
        else if (type == BotCommandScopeChat::Type)
        {
            BotCommandScopeChat::Ptr valuePtr;
            readJsonObject(valuePtr, json, valueName);
            value = valuePtr;
        }
        else if (type == BotCommandScopeChatAdministrators::Type)
        {
            BotCommandScopeChatAdministrators::Ptr valuePtr;
            readJsonObject(valuePtr, json, valueName);
            value = valuePtr;
        }
        else if (type == BotCommandScopeChatMember::Type)
        {
            BotCommandScopeChatMember::Ptr valuePtr;
            readJsonObject(valuePtr, json, valueName);
            value = valuePtr;
        }
        else
            return false;

        readJsonObject(value->m_type, object, "type");

        return true;
    }

    return false;
}

QJsonObject toJsonValue(const BotCommandScope::Ptr& value)
{
    QJsonObject jsonObject;

    jsonObject.insert("type", value->m_type);

    return jsonObject;
}
}
