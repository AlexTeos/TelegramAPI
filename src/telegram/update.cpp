#include "update.h"

namespace TelegramApi
{
void readValue(Update::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = Update::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readValue(value->m_update_id, object, "update_id");
        readValue(value->m_message, object, "message");
        readValue(value->m_edited_message, object, "edited_message");
        readValue(value->m_channel_post, object, "channel_post");
        readValue(value->m_edited_channel_post, object, "edited_channel_post");
        readValue(value->m_inline_query, object, "inline_query");
        readValue(value->m_chosen_inline_result, object, "chosen_inline_result");
        readValue(value->m_callback_query, object, "callback_query");
        readValue(value->m_shipping_query, object, "shipping_query");
        readValue(value->m_shipping_query, object, "shipping_query");
        readValue(value->m_pre_checkout_query, object, "pre_checkout_query");
        readValue(value->m_poll, object, "poll");
        readValue(value->m_poll_answer, object, "poll_answer");
        readValue(value->m_my_chat_member, object, "my_chat_member");
        readValue(value->m_chat_member, object, "chat_member");
        readValue(value->m_chat_join_request, object, "chat_join_request");
    }
}
}
