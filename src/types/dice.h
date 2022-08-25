#ifndef DICE_H
#define DICE_H

#include "common.h"

namespace Telegram
{
struct Dice
{
    using Ptr = QSharedPointer<Dice>;

    QString m_emoji;
    qint64  m_value = 0;
};

bool readJsonObject(Dice::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // DICE_H
