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
bool BotCommandScope::readJsonObject(const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        QJsonObject object = json[valueName].toObject();

        Telegram::readJsonObject(m_type, object, "type");

        return true;
    }

    return false;
}

QJsonObject BotCommandScope::toJsonValue()
{
    QJsonObject jsonObject;

    jsonObject.insert("type", m_type);

    return jsonObject;
}

QJsonObject toJsonValue(const BotCommandScope::Ptr& value)
{
    return value->toJsonValue();
}

}
