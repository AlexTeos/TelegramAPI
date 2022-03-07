#ifndef GAME_H
#define GAME_H

#include "animation.h"
#include "common.h"
#include "messageentity.h"
#include "photosize.h"

namespace Telegram
{
struct Game
{
    typedef QSharedPointer<Game> Ptr;

    QString                     m_title;
    QString                     m_description;
    QVector<PhotoSize::Ptr>     m_photo;
    QString                     m_text;
    QVector<MessageEntity::Ptr> m_text_entities;
    Animation::Ptr              m_animation;
};

void readJsonObject(Game::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // GAME_H
