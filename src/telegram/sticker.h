#ifndef STICKER_H
#define STICKER_H

#include "common.h"
#include "maskposition.h"
#include "photosize.h"

namespace TelegramApi
{
struct Sticker
{
    typedef QSharedPointer<Sticker> Ptr;

    QString           m_file_id;
    QString           m_file_unique_id;
    int32_t           m_width;
    int32_t           m_height;
    bool              m_is_animated;
    bool              m_is_video;
    PhotoSize::Ptr    m_thumb;
    QString           m_emoji;
    QString           m_set_name;
    MaskPosition::Ptr m_mask_position;
    int32_t           m_file_size;
};

void readValue(Sticker::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // STICKER_H
