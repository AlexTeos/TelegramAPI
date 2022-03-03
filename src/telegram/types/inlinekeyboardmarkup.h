#ifndef INLINEKEYBOARDMARKUP_H
#define INLINEKEYBOARDMARKUP_H

#include "common.h"
#include "inlinekeyboardbutton.h"

namespace TelegramApi
{
struct InlineKeyboardMarkup
{
    typedef QSharedPointer<InlineKeyboardMarkup> Ptr;

    QVector<QVector<InlineKeyboardButton::Ptr>> m_inline_keyboard;
};

void readValue(InlineKeyboardMarkup::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // INLINEKEYBOARDMARKUP_H
