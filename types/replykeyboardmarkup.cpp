#include "replykeyboardmarkup.h"

namespace Telegram
{
bool readJsonObject(ReplyKeyboardMarkup::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = ReplyKeyboardMarkup::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readJsonObject(value->m_keyboard, object, "keyboard");
        readJsonObject(value->m_resize_keyboard, object, "resize_keyboard");
        readJsonObject(value->m_one_time_keyboard, object, "one_time_keyboard");
        readJsonObject(value->m_input_field_placeholder, object, "input_field_placeholder");
        readJsonObject(value->m_selective, object, "selective");

        return true;
    }

    return false;
}

QJsonValue toJsonValue(const ReplyKeyboardMarkup::Ptr& value)
{
    QJsonObject jsonObject;

    jsonObject.insert("keyboard", toJsonValue(value->m_keyboard));
    if (value->m_resize_keyboard) jsonObject.insert("resize_keyboard", value->m_resize_keyboard.value());
    if (value->m_one_time_keyboard) jsonObject.insert("one_time_keyboard", value->m_one_time_keyboard.value());
    if (value->m_input_field_placeholder)
        jsonObject.insert("input_field_placeholder", value->m_input_field_placeholder.value());
    if (value->m_selective) jsonObject.insert("selective", value->m_selective.value());

    return jsonObject;
}
}
