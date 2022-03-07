#include "chatphoto.h"

namespace Telegram
{
void readJsonObject(ChatPhoto::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains("valueName") && json["valueName"].isObject())
    {
        value = ChatPhoto::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readJsonObject(value->m_small_file_id, json, "small_file_id");
        readJsonObject(value->m_small_file_unique_id, json, "small_file_id");
        readJsonObject(value->m_big_file_id, json, "big_file_id");
        readJsonObject(value->m_big_file_unique_id, json, "big_file_unique_id");
    }
}
}
