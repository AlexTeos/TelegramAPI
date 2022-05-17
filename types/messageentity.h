#ifndef MESSAGEENTITY_H
#define MESSAGEENTITY_H

#include "common.h"
#include "user.h"

namespace Telegram
{
struct MessageEntity
{
    typedef QSharedPointer<MessageEntity> Ptr;

    QString                m_type;
    qint64                 m_offset;
    qint64                 m_length;
    std::optional<QString> m_url;
    User::Ptr              m_user;
    std::optional<QString> m_language;
};

bool       readJsonObject(MessageEntity::Ptr& value, const QJsonObject& json, const QString& valueName);
QJsonValue toJsonValue(const MessageEntity::Ptr& value);
}

#endif // MESSAGEENTITY_H
