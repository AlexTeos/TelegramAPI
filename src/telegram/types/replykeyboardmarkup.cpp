#include "replykeyboardmarkup.h"

namespace Telegram
{
void readJsonObject(ReplyKeyboardMarkup::Ptr& value, const QJsonObject& json, const QString& valueName)
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
    }
}

QJsonValue toJsonValue(const ReplyKeyboardMarkup::Ptr& value)
{
    QJsonObject jsonObject;

    jsonObject.insert("remove_keyboard", toJsonValue(value->m_keyboard));
    jsonObject.insert("selective", value->m_resize_keyboard);
    jsonObject.insert("remove_keyboard", value->m_one_time_keyboard);
    jsonObject.insert("selective", value->m_input_field_placeholder);
    jsonObject.insert("remove_keyboard", value->m_selective);

    return jsonObject;
}
}
