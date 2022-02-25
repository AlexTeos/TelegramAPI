#ifndef CALLBACKQUERY_H
#define CALLBACKQUERY_H

#include "common.h"
#include "message.h"

namespace TelegramApi
{
struct CallbackQuery
{
    typedef QSharedPointer<CallbackQuery> Ptr;

    QString      m_id;
    User::Ptr    m_from;
    Message::Ptr m_message;
    QString      m_inline_message_id;
    QString      m_chat_instance;
    QString      m_data;
    QString      m_game_short_name;
};

void readValue(CallbackQuery::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // CALLBACKQUERY_H
