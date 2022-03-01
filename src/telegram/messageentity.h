#ifndef MESSAGEENTITY_H
#define MESSAGEENTITY_H

#include "common.h"
#include "user.h"

namespace TelegramApi
{
struct MessageEntity
{
    typedef QSharedPointer<MessageEntity> Ptr;

    QString   m_type;
    int32_t   m_offset = 0;
    int32_t   m_length = 0;
    QString   m_url;
    User::Ptr m_user;
    QString   m_language;
};

void readValue(MessageEntity::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // MESSAGEENTITY_H
