#include "common.h"

namespace Telegram
{
void readJsonObject(QString& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isString()) value = json[valueName].toString();
}

void readJsonObject(qint64& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isDouble()) value = json[valueName].toInteger();
}

void readJsonObject(bool& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isBool()) value = json[valueName].toBool();
}

void readJsonObject(double& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isDouble()) value = json[valueName].toDouble();
}

QJsonValue toJsonValue(const QString& value)
{
    return value;
}

QJsonValue toJsonValue(const qint64& value)
{
    return value;
}

QJsonValue toJsonValue(const bool& value)
{
    return value;
}

QJsonValue toJsonValue(const double& value)
{
    return value;
}

}
