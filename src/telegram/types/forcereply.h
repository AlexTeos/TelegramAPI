#ifndef FORCEREPLY_H
#define FORCEREPLY_H

#include "common.h"

namespace Telegram
{
struct ForceReply
{
    typedef QSharedPointer<ForceReply> Ptr;

    bool    m_force_reply = true;
    QString m_input_field_placeholder;
    bool    m_selective = false;
};

void       readJsonObject(ForceReply::Ptr& value, const QJsonObject& json, const QString& valueName);
QJsonValue toJsonValue(const ForceReply::Ptr& value);
}
#endif // FORCEREPLY_H
