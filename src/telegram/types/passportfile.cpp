#include "passportfile.h"

namespace TelegramApi
{
void readValue(PassportFile::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = PassportFile::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readValue(value->m_file_id, object, "file_id");
        readValue(value->m_file_unique_id, object, "file_unique_id");
        readValue(value->m_file_size, object, "file_size");
        readValue(value->m_file_date, object, "file_date");
    }
}
}
