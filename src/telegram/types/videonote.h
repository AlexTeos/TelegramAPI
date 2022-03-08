#ifndef VIDEONOTE_H
#define VIDEONOTE_H

#include "common.h"
#include "photosize.h"

namespace Telegram
{
struct VideoNote
{
    typedef QSharedPointer<VideoNote> Ptr;

    QString               m_file_id;
    QString               m_file_unique_id;
    qint64                m_length;
    qint64                m_duration;
    PhotoSize::Ptr        m_thumb;
    std::optional<qint64> m_file_size;
};

void readJsonObject(VideoNote::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // VIDEONOTE_H
