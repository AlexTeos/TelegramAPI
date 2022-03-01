#ifndef PHOTOSIZE_H
#define PHOTOSIZE_H

#include "common.h"

namespace TelegramApi
{
struct PhotoSize
{
    typedef QSharedPointer<PhotoSize> Ptr;

    QString m_file_id;
    QString m_file_unique_id;
    int32_t m_width     = 0;
    int32_t m_height    = 0;
    int32_t m_file_size = 0;
};

void readValue(PhotoSize::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // PHOTOSIZE_H
