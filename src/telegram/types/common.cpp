#include "common.h"

namespace TelegramApi
{
void readValue(QString& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isString()) value = json[valueName].toString();
}

void readValue(qint64& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isDouble()) value = json[valueName].toInteger();
}

void readValue(bool& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isBool()) value = json[valueName].toBool();
}

void readValue(double& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isDouble()) value = json[valueName].toDouble();
}
}
