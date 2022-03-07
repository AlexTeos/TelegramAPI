#ifndef CALLBACKGAME_H
#define CALLBACKGAME_H

#include "common.h"

namespace Telegram
{
struct CallbackGame
{
    typedef QSharedPointer<CallbackGame> Ptr;

    qint64  m_user_id              = 0;
    qint64  m_score                = 0;
    bool    m_force                = false;
    bool    m_disable_edit_message = false;
    qint64  m_chat_id              = 0;
    qint64  m_message_id           = 0;
    QString m_inline_message_id;
};

void       readJsonObject(CallbackGame::Ptr& value, const QJsonObject& json, const QString& valueName);
QJsonValue toJsonValue(const CallbackGame::Ptr& value);
}
#endif // CALLBACKGAME_H