#include "venue.h"

namespace TelegramApi
{
void readValue(Venue::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = Venue::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readValue(value->m_location, object, "location");
        readValue(value->m_title, object, "title");
        readValue(value->m_address, object, "address");
        readValue(value->m_foursquare_id, object, "foursquare_id");
        readValue(value->m_foursquare_type, object, "foursquare_type");
        readValue(value->m_google_place_id, object, "google_place_id");
        readValue(value->m_google_place_type, object, "google_place_type");
    }
}
}
