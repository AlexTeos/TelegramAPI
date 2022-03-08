#ifndef REPLYKEYBOARDMARKUP_H
#define REPLYKEYBOARDMARKUP_H

#include "common.h"
#include "keyboardbutton.h"

namespace Telegram
{
struct ReplyKeyboardMarkup
{
    typedef QSharedPointer<ReplyKeyboardMarkup> Ptr;

    QVector<QVector<KeyboardButton::Ptr>> m_keyboard;
    std::optional<bool>                   m_resize_keyboard;
    std::optional<bool>                   m_one_time_keyboard;
    std::optional<QString>                m_input_field_placeholder;
    std::optional<bool>                   m_selective;
};

void       readJsonObject(ReplyKeyboardMarkup::Ptr& value, const QJsonObject& json, const QString& valueName);
QJsonValue toJsonValue(const ReplyKeyboardMarkup::Ptr& value);
}
#endif // REPLYKEYBOARDMARKUP_H
