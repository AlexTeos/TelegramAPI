#ifndef VIDEONOTE_H
#define VIDEONOTE_H

#include "common.h"
#include "photosize.h"

namespace TelegramApi
{
struct VideoNote
{
    typedef QSharedPointer<VideoNote> Ptr;

    QString        m_file_id;
    QString        m_file_unique_id;
    qint64         m_length   = 0;
    qint64         m_duration = 0;
    PhotoSize::Ptr m_thumb;
    qint64         m_file_size = 0;
};

void readValue(VideoNote::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // VIDEONOTE_H
