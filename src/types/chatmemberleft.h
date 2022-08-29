#ifndef CHATMEMBERLEFT_H
#define CHATMEMBERLEFT_H

#include "chatmember.h"

namespace Telegram
{
struct ChatMemberLeft : public ChatMember
{
    using Ptr = QSharedPointer<ChatMemberLeft>;
    static const QString Status;

    friend bool readJsonObject(ChatMemberLeft::Ptr&, const QJsonObject&, const QString&);

    bool readJsonObject(const QJsonObject& json, const QString& valueName);

protected:
    virtual QJsonObject toJsonValue();
};

bool readJsonObject(ChatMemberLeft::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // CHATMEMBERLEFT_H
