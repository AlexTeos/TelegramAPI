#ifndef PASSPORTFILE_H
#define PASSPORTFILE_H

#include "common.h"

namespace TelegramApi
{
struct PassportFile
{
    typedef QSharedPointer<PassportFile> Ptr;

    QString m_file_id;
    QString m_file_unique_id;
    int32_t m_file_size;
    int32_t m_file_date;
};

void readValue(PassportFile::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // PASSPORTFILE_H
