#include "common.h"

namespace Telegram
{
bool readJsonObject(QString& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isString())
    {
        value = json[valueName].toString();

        return true;
    }

    return false;
}

bool readJsonObject(qint64& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isDouble())
    {
#if QT_VERSION >= 0x060000
        value = json[valueName].toInteger();
#else
        value = json[valueName].toDouble();
#endif
        return true;
    }

    return false;
}

bool readJsonObject(bool& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isBool())
    {
        value = json[valueName].toBool();

        return true;
    }

    return false;
}

bool readJsonObject(double& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isDouble())
    {
        value = json[valueName].toDouble();

        return true;
    }

    return false;
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
