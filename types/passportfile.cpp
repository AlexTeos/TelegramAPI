#include "passportfile.h"

namespace Telegram
{
bool readJsonObject(PassportFile::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = PassportFile::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readJsonObject(value->m_file_id, object, "file_id");
        readJsonObject(value->m_file_unique_id, object, "file_unique_id");
        readJsonObject(value->m_file_size, object, "file_size");
        readJsonObject(value->m_file_date, object, "file_date");

        return true;
    }

    return false;
}
}
