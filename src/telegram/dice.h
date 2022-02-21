#ifndef DICE_H
#define DICE_H
#include "common.h"

namespace TelegramApi
{
struct Dice
{
    typedef QSharedPointer<Dice> Ptr;

    QString m_emoji;
    int32_t m_value;
};

void readValue(Dice::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // DICE_H
