#ifndef REPLYKEYBOARDREMOVE_H
#define REPLYKEYBOARDREMOVE_H

#include "common.h"

namespace Telegram
{
struct ReplyKeyboardRemove
{
    typedef QSharedPointer<ReplyKeyboardRemove> Ptr;

    bool                m_remove_keyboard = true;
    std::optional<bool> m_selective;
};

bool       readJsonObject(ReplyKeyboardRemove::Ptr& value, const QJsonObject& json, const QString& valueName);
QJsonValue toJsonValue(const ReplyKeyboardRemove::Ptr& value);
}

#endif // REPLYKEYBOARDREMOVE_H
