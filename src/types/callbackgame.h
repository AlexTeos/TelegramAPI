#ifndef CALLBACKGAME_H
#define CALLBACKGAME_H

#include "common.h"

namespace Telegram
{
struct CallbackGame
{
    typedef QSharedPointer<CallbackGame> Ptr;

    qint64                 m_user_id;
    qint64                 m_score;
    std::optional<bool>    m_force;
    std::optional<bool>    m_disable_edit_message;
    std::optional<qint64>  m_chat_id;
    std::optional<qint64>  m_message_id;
    std::optional<QString> m_inline_message_id;
};

bool       readJsonObject(CallbackGame::Ptr& value, const QJsonObject& json, const QString& valueName);
QJsonValue toJsonValue(const CallbackGame::Ptr& value);
}
#endif // CALLBACKGAME_H
