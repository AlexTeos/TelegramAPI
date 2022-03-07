#include "game.h"

namespace Telegram
{
void readJsonObject(Game::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = Game::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readJsonObject(value->m_title, object, "m_title");
        readJsonObject(value->m_description, object, "m_description");
        readJsonObject(value->m_photo, object, "m_photo");
        readJsonObject(value->m_text, object, "m_text");
        readJsonObject(value->m_text_entities, object, "m_text_entities");
        readJsonObject(value->m_animation, object, "m_animation");
    }
}
}
