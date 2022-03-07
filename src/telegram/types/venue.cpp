#include "venue.h"

namespace Telegram
{
void readJsonObject(Venue::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = Venue::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readJsonObject(value->m_location, object, "location");
        readJsonObject(value->m_title, object, "title");
        readJsonObject(value->m_address, object, "address");
        readJsonObject(value->m_foursquare_id, object, "foursquare_id");
        readJsonObject(value->m_foursquare_type, object, "foursquare_type");
        readJsonObject(value->m_google_place_id, object, "google_place_id");
        readJsonObject(value->m_google_place_type, object, "google_place_type");
    }
}
}
