#ifndef CHATMEMBERBANNED_H
#define CHATMEMBERBANNED_H

#include "chatmember.h"

namespace Telegram
{
struct ChatMemberBanned : public ChatMember
{
    using Ptr = QSharedPointer<ChatMemberBanned>;
    static const QString Status;

    bool readJsonObject(const QJsonObject& json, const QString& valueName);

    qint64 m_until_date;

    friend bool readJsonObject(ChatMemberBanned::Ptr&, const QJsonObject&, const QString&);

protected:
    virtual QJsonObject toJsonValue();
};

bool readJsonObject(ChatMemberBanned::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // CHATMEMBERBANNED_H
