#ifndef ANIMATION_H
#define ANIMATION_H

#include "common.h"
#include "photosize.h"

namespace Telegram
{
struct Animation
{
    typedef QSharedPointer<Animation> Ptr;

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

void readJsonObject(Animation::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // ANIMATION_H
