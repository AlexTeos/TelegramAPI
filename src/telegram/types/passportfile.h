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
    qint64  m_file_size = 0;
    qint64  m_file_date = 0;
};

void readValue(PassportFile::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // PASSPORTFILE_H
