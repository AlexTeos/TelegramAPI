#ifndef VENUE_H
#define VENUE_H

#include "common.h"
#include "location.h"

namespace TelegramApi
{
struct Venue
{
    typedef QSharedPointer<Venue> Ptr;

    Location::Ptr m_location;
    QString       m_title;
    QString       m_address;
    QString       m_foursquare_id;
    QString       m_foursquare_type;
    QString       m_google_place_id;
    QString       m_google_place_type;
};

void readValue(Venue::Ptr& value, const QJsonObject& json, const QString& valueName);
}
#endif // VENUE_H
