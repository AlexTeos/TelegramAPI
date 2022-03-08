#ifndef COMMON_H
#define COMMON_H

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

namespace Telegram
{
void readJsonObject(QString& value, const QJsonObject& json, const QString& valueName);
void readJsonObject(qint64& value, const QJsonObject& json, const QString& valueName);
void readJsonObject(bool& value, const QJsonObject& json, const QString& valueName);
void readJsonObject(double& value, const QJsonObject& json, const QString& valueName);

template <typename T>
void readJsonObject(std::optional<T>& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName))
    {
        T valueTemp;
        readJsonObject(valueTemp, json, valueName);
        value = valueTemp;
    }
    else
        value = std::nullopt;
}

template <typename T>
void readJsonObject(QVector<T>& valueArray, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isArray())
    {
        QJsonArray jsonArray = json[valueName].toArray();
        valueArray.resize(jsonArray.size());

        auto valueArrayIter = valueArray.begin();
        auto jsonArrayIter  = jsonArray.begin();
        for (; valueArrayIter != valueArray.end() && jsonArrayIter != jsonArray.end();
             ++valueArrayIter, ++jsonArrayIter)
        {
            QJsonObject object;
            if (jsonArrayIter->isArray())
            {
                object = QJsonObject{{valueName, jsonArrayIter->toArray()}};
            }
            else if (jsonArrayIter->isObject())
            {
                object = QJsonObject{{valueName, jsonArrayIter->toObject()}};
            }
            else if (jsonArrayIter->isString())
            {
                object = QJsonObject{{valueName, jsonArrayIter->toString()}};
            }
            else if (jsonArrayIter->isDouble())
            {
                object = QJsonObject{{valueName, jsonArrayIter->toDouble()}};
            }
            else if (jsonArrayIter->isBool())
            {
                object = QJsonObject{{valueName, jsonArrayIter->toBool()}};
            }
            readJsonObject(*valueArrayIter, object, valueName);
        }
    }
}

QJsonValue toJsonValue(const QString& value);
QJsonValue toJsonValue(const qint64& value);
QJsonValue toJsonValue(const bool& value);
QJsonValue toJsonValue(const double& value);

template <typename T>
QJsonValue toJsonValue(const QVector<T>& valueArray)
{
    QJsonArray jsonArray;

    for (auto valueArrayIter = valueArray.begin(); valueArrayIter != valueArray.end(); ++valueArrayIter)
        jsonArray.append(toJsonValue(*valueArrayIter));

    return jsonArray;
}
}

#endif // COMMON_H
