#ifndef COMMON_H
#define COMMON_H

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

namespace TelegramApi
{
void readValue(QString& value, const QJsonObject& json, const QString& valueName);
void readValue(qint64& value, const QJsonObject& json, const QString& valueName);
void readValue(bool& value, const QJsonObject& json, const QString& valueName);
void readValue(double& value, const QJsonObject& json, const QString& valueName);

template <typename T>
void readValue(QVector<T>& valueArray, const QJsonObject& json, const QString& valueName)
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
            readValue(*valueArrayIter, object, valueName);
        }
    }
}
}

#endif // COMMON_H
