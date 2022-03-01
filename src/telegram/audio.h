#ifndef AUDIO_H
#define AUDIO_H

#include "common.h"
#include "photosize.h"

namespace TelegramApi
{
struct Audio
{
    typedef QSharedPointer<Audio> Ptr;

    QString        m_file_id;
    QString        m_file_unique_id;
    int32_t        m_duration = 0;
    QString        m_performer;
    QString        m_title;
    QString        m_file_name;
    QString        m_mime_type;
    int32_t        m_file_size = 0;
    PhotoSize::Ptr m_thumb;
};

void readValue(Audio::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // AUDIO_H
