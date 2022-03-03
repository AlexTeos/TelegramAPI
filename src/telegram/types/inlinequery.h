#ifndef INLINEQUERY_H
#define INLINEQUERY_H

#include "common.h"
#include "location.h"
#include "user.h"

namespace TelegramApi
{
struct InlineQuery
{
    typedef QSharedPointer<InlineQuery> Ptr;

    QString       m_id;
    User::Ptr     m_from;
    QString       m_query;
    QString       m_offset;
    QString       m_chat_type;
    Location::Ptr m_location;
};

void readValue(InlineQuery::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // INLINEQUERY_H
