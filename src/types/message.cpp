#include "message.h"

namespace Telegram
{
bool readJsonObject(Message::Ptr& value, const QJsonObject& json, const QString& valueName)
{
    if (json.contains(valueName) && json[valueName].isObject())
    {
        value = Message::Ptr::create();

        QJsonObject object = json[valueName].toObject();

        readJsonObject(value->m_message_id, object, "message_id");
        readJsonObject(value->m_from, object, "from");
        readJsonObject(value->m_sender_chat, object, "sender_chat");
        readJsonObject(value->m_date, object, "date");
        readJsonObject(value->m_chat, object, "chat");
        readJsonObject(value->m_forward_from, object, "forward_from");
        readJsonObject(value->m_forward_from_chat, object, "forward_from_chat");
        readJsonObject(value->m_forward_from_message_id, object, "forward_from_message_id");
        readJsonObject(value->m_forward_signature, object, "forward_signature");
        readJsonObject(value->m_forward_sender_name, object, "forward_sender_name");
        readJsonObject(value->m_forward_date, object, "forward_date");
        readJsonObject(value->m_is_automatic_forward, object, "is_automatic_forward");
        readJsonObject(value->m_reply_to_message, object, "reply_to_message");
        readJsonObject(value->m_via_bot, object, "via_bot");
        readJsonObject(value->m_edit_date, object, "edit_date");
        readJsonObject(value->m_has_protected_content, object, "has_protected_content");
        readJsonObject(value->m_media_group_id, object, "media_group_id");
        readJsonObject(value->m_author_signature, object, "author_signature");
        readJsonObject(value->m_text, object, "text");
        readJsonObject(value->m_entities, object, "entities");
        readJsonObject(value->m_animation, object, "animation");
        readJsonObject(value->m_audio, object, "audio");
        readJsonObject(value->m_document, object, "document");
        readJsonObject(value->m_photo, object, "photo");
        readJsonObject(value->m_sticker, object, "sticker");
        readJsonObject(value->m_video, object, "video");
        readJsonObject(value->m_video_note, object, "video_note");
        readJsonObject(value->m_voice, object, "voice");
        readJsonObject(value->m_caption, object, "caption");
        readJsonObject(value->m_caption_entities, object, "caption_entities");
        readJsonObject(value->m_contact, object, "contact");
        readJsonObject(value->m_dice, object, "dice");
        readJsonObject(value->m_game, object, "game");
        readJsonObject(value->m_poll, object, "poll");
        readJsonObject(value->m_venue, object, "venue");
        readJsonObject(value->m_location, object, "location");
        readJsonObject(value->m_new_chat_members, object, "new_chat_members");
        readJsonObject(value->m_left_chat_member, object, "left_chat_member");
        readJsonObject(value->m_new_chat_title, object, "new_chat_title");
        readJsonObject(value->m_new_chat_photo, object, "new_chat_photo");
        readJsonObject(value->m_delete_chat_photo, object, "delete_chat_photo");
        readJsonObject(value->m_group_chat_created, object, "group_chat_created");
        readJsonObject(value->m_supergroup_chat_created, object, "supergroup_chat_created");
        readJsonObject(value->m_channel_chat_created, object, "channel_chat_created");
        readJsonObject(value->m_message_auto_delete_timer_changed, object, "message_auto_delete_timer_changed");
        readJsonObject(value->m_migrate_to_chat_id, object, "migrate_to_chat_id");
        readJsonObject(value->m_migrate_from_chat_id, object, "migrate_from_chat_id");
        readJsonObject(value->m_pinned_message, object, "pinned_message");
        readJsonObject(value->m_invoice, object, "invoice");
        readJsonObject(value->m_successful_payment, object, "successful_payment");
        readJsonObject(value->m_connected_website, object, "connected_website");
        readJsonObject(value->m_passport_data, object, "passport_data");
        readJsonObject(value->m_proximity_alert_triggered, object, "proximity_alert_triggered");
        readJsonObject(value->m_voice_chat_scheduled, object, "voice_chat_scheduled");
        readJsonObject(value->m_voice_chat_started, object, "voice_chat_started");
        readJsonObject(value->m_voice_chat_ended, object, "voice_chat_ended");
        readJsonObject(value->m_voice_chat_participants_invited, object, "voice_chat_participants_invited");
        readJsonObject(value->m_reply_markup, object, "reply_markup");

        return true;
    }

    return false;
}
}
