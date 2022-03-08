#include "forcereply.h"

namespace Telegram
{
void readJsonObject(ForceReply::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = ForceReply::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readJsonObject(value->m_input_field_placeholder, object, "input_field_placeholder");
        readJsonObject(value->m_selective, object, "selective");
    }
}

QJsonValue toJsonValue(const ForceReply::Ptr& value)
{
    QJsonObject jsonObject;

    jsonObject.insert("force_reply", value->m_force_reply);
    if (value->m_input_field_placeholder)
        jsonObject.insert("input_field_placeholder", value->m_input_field_placeholder.value());
    if (value->m_selective) jsonObject.insert("selective", value->m_selective.value());

    return jsonObject;
}
}
