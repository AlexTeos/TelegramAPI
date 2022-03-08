#ifndef INLINEQUERY_H
#define INLINEQUERY_H

#include "common.h"
#include "location.h"
#include "user.h"

namespace Telegram
{
struct InlineQuery
{
    typedef QSharedPointer<InlineQuery> Ptr;

    QString                m_id;
    User::Ptr              m_from;
    QString                m_query;
    QString                m_offset;
    std::optional<QString> m_chat_type;
    Location::Ptr          m_location;
};

void readJsonObject(InlineQuery::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // INLINEQUERY_H
