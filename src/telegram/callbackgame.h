#ifndef CALLBACKGAME_H
#define CALLBACKGAME_H

#include "common.h"

namespace TelegramApi
{
struct CallbackGame
{
    typedef QSharedPointer<CallbackGame> Ptr;

    int32_t m_user_id;
    int32_t m_score;
    bool    m_force;
    bool    m_disable_edit_message;
    int32_t m_chat_id;
    int32_t m_message_id;
    QString m_inline_message_id;
};

void readValue(CallbackGame::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // CALLBACKGAME_H
