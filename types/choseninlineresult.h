#ifndef CHOSENINLINERESULT_H
#define CHOSENINLINERESULT_H

#include "common.h"
#include "location.h"
#include "user.h"

namespace Telegram
{
struct ChosenInlineResult
{
    typedef QSharedPointer<ChosenInlineResult> Ptr;

    QString                m_result_id;
    User::Ptr              m_from;
    Location::Ptr          m_location;
    std::optional<QString> m_inline_message_id;
    QString                m_query;
};

bool readJsonObject(ChosenInlineResult::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // CHOSENINLINERESULT_H
