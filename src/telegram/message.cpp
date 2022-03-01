#include "message.h"

namespace TelegramApi
{
void readValue(Message::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = Message::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readValue(value->m_message_id, object, "message_id");
        readValue(value->m_from, object, "from");
        readValue(value->m_sender_chat, object, "sender_chat");
        readValue(value->m_date, object, "date");
        readValue(value->m_chat, object, "chat");
        readValue(value->m_forward_from, object, "forward_from");
        readValue(value->m_forward_from_chat, object, "forward_from_chat");
        readValue(value->m_forward_from_message_id, object, "forward_from_message_id");
        readValue(value->m_forward_signature, object, "forward_signature");
        readValue(value->m_forward_sender_name, object, "forward_sender_name");
        readValue(value->m_forward_date, object, "forward_date");
        readValue(value->m_is_automatic_forward, object, "is_automatic_forward");
        readValue(value->m_reply_to_message, object, "reply_to_message");
        readValue(value->m_via_bot, object, "via_bot");
        readValue(value->m_edit_date, object, "edit_date");
        readValue(value->m_has_protected_content, object, "has_protected_content");
        readValue(value->m_media_group_id, object, "media_group_id");
        readValue(value->m_author_signature, object, "author_signature");
        readValue(value->m_text, object, "text");
        readValue(value->m_entities, object, "entities");
        readValue(value->m_animation, object, "animation");
        readValue(value->m_audio, object, "audio");
        readValue(value->m_document, object, "document");
        readValue(value->m_photo, object, "photo");
        readValue(value->m_sticker, object, "sticker");
        readValue(value->m_video, object, "video");
        readValue(value->m_video_note, object, "video_note");
        readValue(value->m_voice, object, "voice");
        readValue(value->m_caption, object, "caption");
        readValue(value->m_caption_entities, object, "caption_entities");
        readValue(value->m_contact, object, "contact");
        readValue(value->m_dice, object, "dice");
        readValue(value->m_game, object, "game");
        readValue(value->m_poll, object, "poll");
        readValue(value->m_venue, object, "venue");
        readValue(value->m_location, object, "location");
        readValue(value->m_new_chat_members, object, "new_chat_members");
        readValue(value->m_left_chat_member, object, "left_chat_member");
        readValue(value->m_new_chat_title, object, "new_chat_title");
        readValue(value->m_new_chat_photo, object, "new_chat_photo");
        readValue(value->m_delete_chat_photo, object, "delete_chat_photo");
        readValue(value->m_group_chat_created, object, "group_chat_created");
        readValue(value->m_supergroup_chat_created, object, "supergroup_chat_created");
        readValue(value->m_channel_chat_created, object, "channel_chat_created");
        readValue(value->m_message_auto_delete_timer_changed, object, "message_auto_delete_timer_changed");
        readValue(value->m_migrate_to_chat_id, object, "migrate_to_chat_id");
        readValue(value->m_migrate_from_chat_id, object, "migrate_from_chat_id");
        readValue(value->m_pinned_message, object, "pinned_message");
        readValue(value->m_invoice, object, "invoice");
        readValue(value->m_successful_payment, object, "successful_payment");
        readValue(value->m_connected_website, object, "connected_website");
        readValue(value->m_passport_data, object, "passport_data");
        readValue(value->m_proximity_alert_triggered, object, "proximity_alert_triggered");
        readValue(value->m_voice_chat_scheduled, object, "voice_chat_scheduled");
        readValue(value->m_voice_chat_started, object, "voice_chat_started");
        readValue(value->m_voice_chat_ended, object, "voice_chat_ended");
        readValue(value->m_voice_chat_participants_invited, object, "voice_chat_participants_invited");
        readValue(value->m_reply_markup, object, "reply_markup");
    }
}
}
