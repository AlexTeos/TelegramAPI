#ifndef MASKPOSITION_H
#define MASKPOSITION_H

#include "common.h"

namespace TelegramApi
{
struct MaskPosition
{
    typedef QSharedPointer<MaskPosition> Ptr;

    QString m_point;
    float   m_x_shift = 0;
    float   m_y_shift = 0;
    float   m_scale   = 0;
};

void readValue(MaskPosition::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // MASKPOSITION_H
