#ifndef DOCUMENT_H
#define DOCUMENT_H

#include "common.h"
#include "photosize.h"

namespace Telegram
{
struct Document
{
    typedef QSharedPointer<Document> Ptr;

    QString                m_file_id;
    QString                m_file_unique_id;
    PhotoSize::Ptr         m_thumb;
    std::optional<QString> m_file_name;
    std::optional<QString> m_mime_type;
    std::optional<qint64>  m_file_size;
};

bool readJsonObject(Document::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // DOCUMENT_H
