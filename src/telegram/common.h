#ifndef COMMON_H
#define COMMON_H

#include <QJsonDocument>
#include <QJsonObject>

namespace TelegramApi
{
void readValue(QString& value, const QJsonObject& json, const QString& valueName);
void readValue(uint32_t& value, const QJsonObject& json, const QString& valueName);
void readValue(bool& value, const QJsonObject& json, const QString& valueName);
void readValue(float& value, const QJsonObject& json, const QString& valueName);
}

#endif // COMMON_H
