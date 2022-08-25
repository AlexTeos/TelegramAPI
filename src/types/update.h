#ifndef UPDATE_H
#define UPDATE_H

#include "callbackquery.h"
#include "chatjoinrequest.h"
#include "chatmemberupdated.h"
#include "choseninlineresult.h"
#include "inlinequery.h"
#include "message.h"
#include "poll.h"
#include "pollanswer.h"
#include "precheckoutquery.h"
#include "shippingquery.h"

namespace Telegram
{
struct Update
{
    using Ptr = QSharedPointer<Update>;

    qint64                  m_update_id;
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

bool readJsonObject(Update::Ptr& value, const QJsonObject& json, const QString& valueName);
}

#endif // UPDATE_H
