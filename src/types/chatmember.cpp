#include "chatmember.h"

#include "chatmemberadministrator.h"
#include "chatmemberbanned.h"
#include "chatmemberleft.h"
#include "chatmembermember.h"
#include "chatmemberowner.h"
#include "chatmemberrestricted.h"

namespace Telegram
{
bool readJsonObject(ChatMember::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        QJsonObject object = json[valueName].toObject();

        QString status;
        readJsonObject(status, object, "status");

        if (status == ChatMemberAdministrator::Type)
        {
            ChatMemberAdministrator::Ptr valuePtr;
            readJsonObject(valuePtr, json, valueName);
            value = valuePtr;
        }
        else if (status == ChatMemberOwner::Type)
        {
            ChatMemberOwner::Ptr valuePtr;
            readJsonObject(valuePtr, json, valueName);
            value = valuePtr;
        }
        else if (status == ChatMemberBanned::Type)
        {
            ChatMemberBanned::Ptr valuePtr;
            readJsonObject(valuePtr, json, valueName);
            value = valuePtr;
        }
        else if (status == ChatMemberLeft::Type)
        {
            ChatMemberLeft::Ptr valuePtr;
            readJsonObject(valuePtr, json, valueName);
            value = valuePtr;
        }
        else if (status == ChatMemberMember::Type)
        {
            ChatMemberMember::Ptr valuePtr;
            readJsonObject(valuePtr, json, valueName);
            value = valuePtr;
        }
        else if (status == ChatMemberRestricted::Type)
        {
            ChatMemberRestricted::Ptr valuePtr;
            readJsonObject(valuePtr, json, valueName);
            value = valuePtr;
        }
        else
            return false;

        readJsonObject(value->m_status, object, "status");
        readJsonObject(value->m_user, object, "user");

        return true;
    }

    return false;
}
}
