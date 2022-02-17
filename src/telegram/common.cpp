#include "common.h"

namespace TelegramApi
{
void readValue(QString& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isString()) value = json[valueName].toString();
}

void readValue(uint32_t& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isDouble()) value = json[valueName].toInt();
}

void readValue(bool& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isBool()) value = json[valueName].toBool();
}

void readValue(float& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isDouble()) value = json[valueName].toDouble();
}
}
