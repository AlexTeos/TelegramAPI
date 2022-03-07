#include "chatmember.h"

#include "chatmemberadministrator.h"
#include "chatmemberbanned.h"
#include "chatmemberleft.h"
#include "chatmembermember.h"
#include "chatmemberowner.h"
#include "chatmemberrestricted.h"

namespace Telegram
{
void readJsonObject(ChatMember::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        QJsonObject object = json[valueName].toObject();

        QString status;
        readJsonObject(status, object, "status");

        if (status == "administrator")
        {
            ChatMemberAdministrator::Ptr valuePtr;
            readJsonObject(valuePtr, json, valueName);
            value = valuePtr;
        }
        else if (status == "creator")
        {
            ChatMemberOwner::Ptr valuePtr;
            readJsonObject(valuePtr, json, valueName);
            value = valuePtr;
        }
        else if (status == "kicked")
        {
            ChatMemberBanned::Ptr valuePtr;
            readJsonObject(valuePtr, json, valueName);
            value = valuePtr;
        }
        else if (status == "left")
        {
            ChatMemberLeft::Ptr valuePtr;
            readJsonObject(valuePtr, json, valueName);
            value = valuePtr;
        }
        else if (status == "member")
        {
            ChatMemberMember::Ptr valuePtr;
            readJsonObject(valuePtr, json, valueName);
            value = valuePtr;
        }
        else if (status == "restricted")
        {
            ChatMemberRestricted::Ptr valuePtr;
            readJsonObject(valuePtr, json, valueName);
            value = valuePtr;
        }
        else
            return;

        readJsonObject(value->m_status, object, "status");
        readJsonObject(value->m_user, object, "user");
    }
}
}
