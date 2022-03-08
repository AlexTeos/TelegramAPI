#ifndef VOICE_H
#define VOICE_H

#include "common.h"

namespace Telegram
{
struct Voice
{
    typedef QSharedPointer<Voice> Ptr;

    QString                m_file_id;
    QString                m_file_unique_id;
    qint64                 m_duration;
    std::optional<QString> m_mime_type;
    std::optional<qint64>  m_file_size;
};

void readJsonObject(Voice::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // VOICE_H
