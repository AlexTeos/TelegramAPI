#include "document.h"

namespace Telegram
{
void readJsonObject(Document::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = Document::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readJsonObject(value->m_file_id, object, "file_id");
        readJsonObject(value->m_file_unique_id, object, "file_unique_id");
        readJsonObject(value->m_thumb, object, "thumb");
        readJsonObject(value->m_file_name, object, "file_name");
        readJsonObject(value->m_mime_type, object, "mime_type");
        readJsonObject(value->m_file_size, object, "file_size");
    }
}
}
