#ifndef VOICE_H
#define VOICE_H

#include "common.h"

namespace TelegramApi
{
struct Voice
{
    typedef QSharedPointer<Voice> Ptr;

    QString m_file_id;
    QString m_file_unique_id;
    int32_t m_duration;
    QString m_mime_type;
    int32_t m_file_size;
};

void readValue(Voice::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // VOICE_H
