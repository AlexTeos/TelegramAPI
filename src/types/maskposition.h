#ifndef MASKPOSITION_H
#define MASKPOSITION_H

#include "common.h"

namespace Telegram
{
struct MaskPosition
{
    using Ptr = QSharedPointer<MaskPosition>;

    QString m_point;
    double  m_x_shift;
    double  m_y_shift;
    double  m_scale;
};

bool readJsonObject(MaskPosition::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // MASKPOSITION_H
