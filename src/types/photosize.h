#ifndef PHOTOSIZE_H
#define PHOTOSIZE_H

#include "common.h"

namespace Telegram
{
struct PhotoSize
{
    typedef QSharedPointer<PhotoSize> Ptr;

    QString               m_file_id;
    QString               m_file_unique_id;
    qint64                m_width;
    qint64                m_height;
    std::optional<qint64> m_file_size;
};

bool readJsonObject(PhotoSize::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // PHOTOSIZE_H
