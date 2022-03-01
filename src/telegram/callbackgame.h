#ifndef CALLBACKGAME_H
#define CALLBACKGAME_H

#include "common.h"

namespace TelegramApi
{
struct CallbackGame
{
    typedef QSharedPointer<CallbackGame> Ptr;

    int32_t m_user_id              = 0;
    int32_t m_score                = 0;
    bool    m_force                = false;
    bool    m_disable_edit_message = false;
    int32_t m_chat_id              = 0;
    int32_t m_message_id           = 0;
    QString m_inline_message_id;
};

void readValue(CallbackGame::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // CALLBACKGAME_H
