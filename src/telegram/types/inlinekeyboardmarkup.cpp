#include "inlinekeyboardmarkup.h"

namespace Telegram
{
void readJsonObject(InlineKeyboardMarkup::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = InlineKeyboardMarkup::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readJsonObject(value->m_inline_keyboard, object, "inline_keyboard");
    }
}

QJsonValue toJsonValue(const InlineKeyboardMarkup::Ptr& value)
{
    QJsonObject jsonObject;

    jsonObject.insert("inline_keyboard", toJsonValue(value->m_inline_keyboard));

    return jsonObject;
}

}
