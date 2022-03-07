#include "replykeyboardremove.h"

namespace Telegram
{
void readJsonObject(ReplyKeyboardRemove::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = ReplyKeyboardRemove::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readJsonObject(value->m_selective, object, "selective");
    }
}

QJsonValue toJsonValue(const ReplyKeyboardRemove::Ptr& value)
{
    QJsonObject jsonObject;

    jsonObject.insert("remove_keyboard", value->m_remove_keyboard);
    jsonObject.insert("selective", value->m_selective);

    return jsonObject;
}
}
