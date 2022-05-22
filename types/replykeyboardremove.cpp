#include "replykeyboardremove.h"

namespace Telegram
{
bool readJsonObject(ReplyKeyboardRemove::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = ReplyKeyboardRemove::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readJsonObject(value->m_selective, object, "selective");

        return true;
    }

    return false;
}

QJsonValue toJsonValue(const ReplyKeyboardRemove::Ptr& value)
{
    QJsonObject jsonObject;

    jsonObject.insert("remove_keyboard", true);
    if (value->m_selective) jsonObject.insert("selective", value->m_selective.value());

    return jsonObject;
}
}
