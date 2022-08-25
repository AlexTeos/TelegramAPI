#ifndef INLINEKEYBOARDMARKUP_H
#define INLINEKEYBOARDMARKUP_H

#include "inlinekeyboardbutton.h"

namespace Telegram
{
struct InlineKeyboardMarkup
{
    using Ptr = QSharedPointer<InlineKeyboardMarkup>;

    QJsonValue toObject(Ptr& value) const;

    QVector<QVector<InlineKeyboardButton::Ptr>> m_inline_keyboard;
};

bool       readJsonObject(InlineKeyboardMarkup::Ptr& value, const QJsonObject& json, const QString& valueName);
QJsonValue toJsonValue(const InlineKeyboardMarkup::Ptr& value);
}

#endif // INLINEKEYBOARDMARKUP_H
