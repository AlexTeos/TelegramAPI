#ifndef MESSAGE_H
#define MESSAGE_H

#include "common.h"
#include "user.h"

namespace TelegramApi
{
struct Message
{
    typedef QSharedPointer<Message> Ptr;

    uint32_t  m_message_id;
    User::Ptr m_from;
    // Chat sender_chat;
    // uint32_t date;
    // Chat chat;
    // User forward_from;
    // Chat forward_from_chat;
    // uint32_t forward_from_message_id;
    // QString forward_signature;
    // QString forward_sender_name;
    // uint32_t forward_date;
    // bool is_automatic_forward;
    // QPointer<Message> reply_to_message;
    // User via_bot;
    // uint32_t edit_date;
    // bool has_protected_content;
    // QString media_group_id;
    // QString author_signature;
    // QString text;
    // QVector<Message> entities;
    // Animation animation Animation;
    // Audio audio;
    // Document document;
    // QVector<PhotoSize> photo;
    // Sticker sticker;
    // Video video;
    // VideoNote video_note VideoNote;
    // Voice voice;
    // QString caption;
    // QVector<Message> caption_entities;
    // Contact contact;
    // Dice dice;
    // Game game;
    // Poll poll;
    // Venue venue;
    // Location location;
    // QVector<User> new_chat_members;
    // User left_chat_member;
    // QString new_chat_title;
    // QVector<PhotoSize> new_chat_photo;
    // bool delete_chat_photo;
    // bool group_chat_created;
    // bool supergroup_chat_created;
    // bool channel_chat_created;
    // MessageAutoDeleteTimerChanged message_auto_delete_timer_changed;
    // uint32_t migrate_to_chat_id Integer;
    // uint32_t migrate_from_chat_id;
    // QPointer<Message> pinned_message;
    // Invoice invoice;
    // SuccessfulPayment successful_payment;
    // QString connected_website;
    // PassportData passport_data;
    // ProximityAlertTriggered proximity_alert_triggered;
    // VoiceChatScheduled voice_chat_scheduled;
    // VoiceChatStarted voice_chat_started;
    // VoiceChatEnded voice_chat_ended;
    // VoiceChatParticipantsInvited voice_chat_participants_invited;
    // InlineKeyboardMarkup reply_markup;
};

void readValue(Message::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // MESSAGE_H
