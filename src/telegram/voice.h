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
    qint64  m_duration = 0;
    QString m_mime_type;
    qint64  m_file_size = 0;
};

void readValue(Voice::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // VOICE_H
