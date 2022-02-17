#ifndef CHATPHOTO_H
#define CHATPHOTO_H

#include "common.h"

namespace TelegramApi
{
struct ChatPhoto
{
    typedef QSharedPointer<ChatPhoto> Ptr;

    QString m_small_file_id;
    QString m_small_file_unique_id;
    QString m_big_file_id;
    QString m_big_file_unique_id;
};

void readValue(ChatPhoto::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // CHATPHOTO_H
