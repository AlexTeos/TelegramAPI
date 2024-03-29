#ifndef FORCEREPLY_H
#define FORCEREPLY_H

#include "common.h"

namespace Telegram
{
struct ForceReply
{
    using Ptr = QSharedPointer<ForceReply>;

    bool                   m_force_reply;
    std::optional<QString> m_input_field_placeholder;
    std::optional<bool>    m_selective;
};

bool       readJsonObject(ForceReply::Ptr& value, const QJsonObject& json, const QString& valueName);
QJsonValue toJsonValue(const ForceReply::Ptr& value);
}
#endif // FORCEREPLY_H
