#include "chatmember.h"

#include "chatmemberadministrator.h"
#include "chatmemberbanned.h"
#include "chatmemberleft.h"
#include "chatmembermember.h"
#include "chatmemberowner.h"
#include "chatmemberrestricted.h"

namespace TelegramApi
{
void readValue(ChatMember::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        QJsonObject object = json[valueName].toObject();

        QString status;
        readValue(status, object, "status");

        if (status == "administrator")
        {
            ChatMemberAdministrator::Ptr valuePtr;
            readValue(valuePtr, json, valueName);
            value = valuePtr;
        }
        else if (status == "creator")
        {
            ChatMemberOwner::Ptr valuePtr;
            readValue(valuePtr, json, valueName);
            value = valuePtr;
        }
        else if (status == "kicked")
        {
            ChatMemberBanned::Ptr valuePtr;
            readValue(valuePtr, json, valueName);
            value = valuePtr;
        }
        else if (status == "left")
        {
            ChatMemberLeft::Ptr valuePtr;
            readValue(valuePtr, json, valueName);
            value = valuePtr;
        }
        else if (status == "member")
        {
            ChatMemberMember::Ptr valuePtr;
            readValue(valuePtr, json, valueName);
            value = valuePtr;
        }
        else if (status == "restricted")
        {
            ChatMemberRestricted::Ptr valuePtr;
            readValue(valuePtr, json, valueName);
            value = valuePtr;
        }
        else
            return;

        readValue(value->m_status, object, "status");
        readValue(value->m_user, object, "user");
    }
}
}
