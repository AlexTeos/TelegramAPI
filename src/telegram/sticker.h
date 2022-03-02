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
    qint64            m_width       = 0;
    qint64            m_height      = 0;
    bool              m_is_animated = false;
    bool              m_is_video    = false;
    PhotoSize::Ptr    m_thumb;
    QString           m_emoji;
    QString           m_set_name;
    MaskPosition::Ptr m_mask_position;
    qint64            m_file_size = 0;
};

void readValue(Sticker::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // STICKER_H
