#ifndef UPDATE_H
#define UPDATE_H

#include "callbackquery.h"
#include "chatjoinrequest.h"
#include "choseninlineresult.h"
#include "common.h"
#include "inlinequery.h"
#include "message.h"
#include "poll.h"
#include "pollanswer.h"
#include "precheckoutquery.h"
#include "shippingquery.h"

namespace TelegramApi
{
struct Update
{
    typedef QSharedPointer<Update> Ptr;

    int32_t                 m_update_id;
    Message::Ptr            m_message;
    Message::Ptr            m_edited_message;
    Message::Ptr            m_channel_post;
    Message::Ptr            m_edited_channel_post;
    InlineQuery::Ptr        m_inline_query;
    ChosenInlineResult::Ptr m_chosen_inline_result;
    CallbackQuery::Ptr      m_callback_query;
    ShippingQuery::Ptr      m_shipping_query;
    PreCheckoutQuery::Ptr   m_pre_checkout_query;
    Poll::Ptr               m_poll;
    PollAnswer::Ptr         m_poll_answer;
    ChatMemberUpdated::Ptr  m_my_chat_member;
    ChatMemberUpdated::Ptr  m_chat_member;
    ChatJoinRequest::Ptr    m_chat_join_request;
};

void readValue(Update::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // UPDATE_H
