#include "update.h"

namespace Telegram
{
void readJsonObject(Update::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = Update::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readJsonObject(value->m_update_id, object, "update_id");
        readJsonObject(value->m_message, object, "message");
        readJsonObject(value->m_edited_message, object, "edited_message");
        readJsonObject(value->m_channel_post, object, "channel_post");
        readJsonObject(value->m_edited_channel_post, object, "edited_channel_post");
        readJsonObject(value->m_inline_query, object, "inline_query");
        readJsonObject(value->m_chosen_inline_result, object, "chosen_inline_result");
        readJsonObject(value->m_callback_query, object, "callback_query");
        readJsonObject(value->m_shipping_query, object, "shipping_query");
        readJsonObject(value->m_shipping_query, object, "shipping_query");
        readJsonObject(value->m_pre_checkout_query, object, "pre_checkout_query");
        readJsonObject(value->m_poll, object, "poll");
        readJsonObject(value->m_poll_answer, object, "poll_answer");
        readJsonObject(value->m_my_chat_member, object, "my_chat_member");
        readJsonObject(value->m_chat_member, object, "chat_member");
        readJsonObject(value->m_chat_join_request, object, "chat_join_request");
    }
}
}
