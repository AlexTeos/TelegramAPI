#ifndef CALLBACKQUERY_H
#define CALLBACKQUERY_H

#include "message.h"

namespace Telegram
{
struct CallbackQuery
{
    using Ptr = QSharedPointer<CallbackQuery>;

    QString                m_id;
    User::Ptr              m_from;
    Message::Ptr           m_message;
    std::optional<QString> m_inline_message_id;
    std::optional<QString> m_chat_instance;
    std::optional<QString> m_data;
    std::optional<QString> m_game_short_name;
};

bool readJsonObject(CallbackQuery::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // CALLBACKQUERY_H
