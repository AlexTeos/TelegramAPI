#ifndef VIDEO_H
#define VIDEO_H

#include "common.h"
#include "photosize.h"

namespace TelegramApi
{
struct Video
{
    typedef QSharedPointer<Video> Ptr;

    QString        m_file_id;
    QString        m_file_unique_id;
    int32_t        m_width;
    int32_t        m_height;
    int32_t        m_duration;
    PhotoSize::Ptr m_thumb;
    QString        m_file_name;
    QString        m_mime_type;
    int32_t        m_file_size;
};

void readValue(Video::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // VIDEO_H
