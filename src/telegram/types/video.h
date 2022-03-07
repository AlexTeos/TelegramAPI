#ifndef VIDEO_H
#define VIDEO_H

#include "common.h"
#include "photosize.h"

namespace Telegram
{
struct Video
{
    typedef QSharedPointer<Video> Ptr;

    QString        m_file_id;
    QString        m_file_unique_id;
    qint64         m_width    = 0;
    qint64         m_height   = 0;
    qint64         m_duration = 0;
    PhotoSize::Ptr m_thumb;
    QString        m_file_name;
    QString        m_mime_type;
    qint64         m_file_size = 0;
};

void readJsonObject(Video::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // VIDEO_H
