#ifndef INLINEKEYBOARDMARKUP_H
#define INLINEKEYBOARDMARKUP_H

#include "common.h"
#include "inlinekeyboardbutton.h"

namespace Telegram
{
struct InlineKeyboardMarkup
{
    typedef QSharedPointer<InlineKeyboardMarkup> Ptr;

    QJsonValue toObject(Ptr& value) const;

    QVector<QVector<InlineKeyboardButton::Ptr>> m_inline_keyboard;
};

void       readJsonObject(InlineKeyboardMarkup::Ptr& value, const QJsonObject& json, const QString& valueName);
QJsonValue toJsonValue(const InlineKeyboardMarkup::Ptr& value);
}

#endif // INLINEKEYBOARDMARKUP_H
