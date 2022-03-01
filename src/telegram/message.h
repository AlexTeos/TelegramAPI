#ifndef MESSAGE_H
#define MESSAGE_H

#include "animation.h"
#include "audio.h"
#include "chat.h"
#include "common.h"
#include "contact.h"
#include "dice.h"
#include "document.h"
#include "game.h"
#include "inlinekeyboardmarkup.h"
#include "invoice.h"
#include "messageautodeletetimerchanged.h"
#include "passportdata.h"
#include "poll.h"
#include "proximityalerttriggered.h"
#include "sticker.h"
#include "successfulpayment.h"
#include "user.h"
#include "venue.h"
#include "video.h"
#include "videonote.h"
#include "voice.h"
#include "voicechatended.h"
#include "voicechatparticipantsinvited.h"
#include "voicechatscheduled.h"
#include "voicechatstarted.h"

namespace TelegramApi
{
struct Message
{
    typedef QSharedPointer<Message> Ptr;

    int32_t                            m_message_id = 0;
    User::Ptr                          m_from;
    Chat::Ptr                          m_sender_chat;
    int32_t                            m_date = 0;
    Chat::Ptr                          m_chat;
    User::Ptr                          m_forward_from;
    Chat::Ptr                          m_forward_from_chat;
    int32_t                            m_forward_from_message_id = 0;
    QString                            m_forward_signature;
    QString                            m_forward_sender_name;
    int32_t                            m_forward_date         = 0;
    bool                               m_is_automatic_forward = false;
    Message::Ptr                       m_reply_to_message;
    User::Ptr                          m_via_bot;
    int32_t                            m_edit_date             = 0;
    bool                               m_has_protected_content = false;
    QString                            m_media_group_id;
    QString                            m_author_signature;
    QString                            m_text;
    QVector<Message::Ptr>              m_entities;
    Animation::Ptr                     m_animation;
    Audio::Ptr                         m_audio;
    Document::Ptr                      m_document;
    QVector<PhotoSize::Ptr>            m_photo;
    Sticker::Ptr                       m_sticker;
    Video::Ptr                         m_video;
    VideoNote::Ptr                     m_video_note;
    Voice::Ptr                         m_voice;
    QString                            m_caption;
    QVector<Message::Ptr>              m_caption_entities;
    Contact::Ptr                       m_contact;
    Dice::Ptr                          m_dice;
    Game::Ptr                          m_game;
    Poll::Ptr                          m_poll;
    Venue::Ptr                         m_venue;
    Location::Ptr                      m_location;
    QVector<User::Ptr>                 m_new_chat_members;
    User::Ptr                          m_left_chat_member;
    QString                            m_new_chat_title;
    QVector<PhotoSize::Ptr>            m_new_chat_photo;
    bool                               m_delete_chat_photo       = false;
    bool                               m_group_chat_created      = false;
    bool                               m_supergroup_chat_created = false;
    bool                               m_channel_chat_created    = false;
    MessageAutoDeleteTimerChanged::Ptr m_message_auto_delete_timer_changed;
    int32_t                            m_migrate_to_chat_id   = 0;
    int32_t                            m_migrate_from_chat_id = 0;
    Message::Ptr                       m_pinned_message;
    Invoice::Ptr                       m_invoice;
    SuccessfulPayment::Ptr             m_successful_payment;
    QString                            m_connected_website;
    PassportData::Ptr                  m_passport_data;
    ProximityAlertTriggered::Ptr       m_proximity_alert_triggered;
    VoiceChatScheduled::Ptr            m_voice_chat_scheduled;
    VoiceChatStarted::Ptr              m_voice_chat_started;
    VoiceChatEnded::Ptr                m_voice_chat_ended;
    VoiceChatParticipantsInvited::Ptr  m_voice_chat_participants_invited;
    InlineKeyboardMarkup::Ptr          m_reply_markup;
};

void readValue(Message::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // MESSAGE_H
