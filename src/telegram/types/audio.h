#ifndef AUDIO_H
#define AUDIO_H

#include "common.h"
#include "photosize.h"

namespace Telegram
{
struct Audio
{
    typedef QSharedPointer<Audio> Ptr;

    QString                m_file_id;
    QString                m_file_unique_id;
    qint64                 m_duration;
    std::optional<QString> m_performer;
    std::optional<QString> m_title;
    std::optional<QString> m_file_name;
    std::optional<QString> m_mime_type;
    std::optional<qint64>  m_file_size;
    PhotoSize::Ptr         m_thumb;
};

void readJsonObject(Audio::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // AUDIO_H
