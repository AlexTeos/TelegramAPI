#ifndef STICKER_H
#define STICKER_H

#include "common.h"
#include "maskposition.h"
#include "photosize.h"

namespace Telegram
{
struct Sticker
{
    typedef QSharedPointer<Sticker> Ptr;

    QString                m_file_id;
    QString                m_file_unique_id;
    qint64                 m_width;
    qint64                 m_height;
    bool                   m_is_animated;
    bool                   m_is_video;
    PhotoSize::Ptr         m_thumb;
    std::optional<QString> m_emoji;
    std::optional<QString> m_set_name;
    MaskPosition::Ptr      m_mask_position;
    std::optional<qint64>  m_file_size;
};

bool readJsonObject(Sticker::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // STICKER_H
