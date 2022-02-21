#include "inlinekeyboardmarkup.h"

namespace TelegramApi
{
void readValue(InlineKeyboardMarkup::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = InlineKeyboardMarkup::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readArrayOfArray(value->m_inline_keyboard, object, "inline_keyboard");
    }
}
}
