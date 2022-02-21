#include "game.h"

namespace TelegramApi
{
void readValue(Game::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = Game::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readValue(value->m_title, object, "m_title");
        readValue(value->m_description, object, "m_description");
        readArray(value->m_photo, object, "m_photo");
        readValue(value->m_text, object, "m_text");
        readArray(value->m_text_entities, object, "m_text_entities");
        readValue(value->m_animation, object, "m_animation");
    }
}
}
