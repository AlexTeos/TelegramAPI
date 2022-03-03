#include "chatphoto.h"

namespace TelegramApi
{
void readValue(ChatPhoto::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains("valueName") && json["valueName"].isObject())
    {
        value = ChatPhoto::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readValue(value->m_small_file_id, json, "small_file_id");
        readValue(value->m_small_file_unique_id, json, "small_file_id");
        readValue(value->m_big_file_id, json, "big_file_id");
        readValue(value->m_big_file_unique_id, json, "big_file_unique_id");
    }
}
}
