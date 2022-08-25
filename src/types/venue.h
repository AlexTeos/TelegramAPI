#ifndef VENUE_H
#define VENUE_H

#include "location.h"

namespace Telegram
{
struct Venue
{
    using Ptr = QSharedPointer<Venue>;

    Location::Ptr          m_location;
    QString                m_title;
    QString                m_address;
    std::optional<QString> m_foursquare_id;
    std::optional<QString> m_foursquare_type;
    std::optional<QString> m_google_place_id;
    std::optional<QString> m_google_place_type;
};

bool readJsonObject(Venue::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // VENUE_H
