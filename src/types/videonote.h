#ifndef VIDEONOTE_H
#define VIDEONOTE_H

#include "photosize.h"

namespace Telegram
{
struct VideoNote
{
    using Ptr = QSharedPointer<VideoNote>;

    QString               m_file_id;
    QString               m_file_unique_id;
    qint64                m_length;
    qint64                m_duration;
    PhotoSize::Ptr        m_thumb;
    std::optional<qint64> m_file_size;
};

bool readJsonObject(VideoNote::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // VIDEONOTE_H
