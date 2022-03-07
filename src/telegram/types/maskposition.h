#ifndef MASKPOSITION_H
#define MASKPOSITION_H

#include "common.h"

namespace Telegram
{
struct MaskPosition
{
    typedef QSharedPointer<MaskPosition> Ptr;

    QString m_point;
    double   m_x_shift = 0;
    double   m_y_shift = 0;
    double   m_scale   = 0;
};

void readJsonObject(MaskPosition::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // MASKPOSITION_H
