#ifndef VIDEO_H
#define VIDEO_H

#include "common.h"
#include "photosize.h"

namespace Telegram
{
struct Video
{
    typedef QSharedPointer<Video> Ptr;

    QString                m_file_id;
    QString                m_file_unique_id;
    qint64                 m_width;
    qint64                 m_height;
    qint64                 m_duration;
    PhotoSize::Ptr         m_thumb;
    std::optional<QString> m_file_name;
    std::optional<QString> m_mime_type;
    std::optional<qint64>  m_file_size;
};

void readJsonObject(Video::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // VIDEO_H
