#include "api.h"

#include <QEventLoop>
#include <QNetworkReply>
#include <QNetworkRequest>

namespace Telegram
{
Api::Api() : m_networkManager(new QNetworkAccessManager()) {}

void Api::setToken(const QString& token)
{
    m_token = token;
}

void Api::setUrl(const QString& url)
{
    m_url = url;
}

std::optional<Telegram::Message::Ptr> Api::sendMessage(
    const qint64&                                     chat_id,
    const QString&                                    text,
    const std::optional<QString>&                     parse_mode,
    const std::optional<QVector<MessageEntity::Ptr>>& entities,
    const std::optional<bool>&                        disable_web_page_preview,
    const std::optional<bool>&                        disable_notification,
    const std::optional<bool>&                        protect_content,
    const std::optional<qint64>&                      reply_to_message_id,
    const std::optional<bool>&                        allow_sending_without_reply,
    const std::optional<
        std::variant<InlineKeyboardMarkup::Ptr, ReplyKeyboardMarkup::Ptr, ReplyKeyboardRemove::Ptr, ForceReply::Ptr>>&
        reply_markup)
{
    if (m_token == "") return std::nullopt;

    QJsonObject postJson{{"text", text}, {"chat_id", chat_id}};

    if (parse_mode) postJson.insert("parse_mode", parse_mode.value());
    if (entities) postJson.insert("entities", toJsonValue(entities.value()));
    if (disable_web_page_preview) postJson.insert("disable_web_page_preview", disable_web_page_preview.value());
    if (disable_notification) postJson.insert("disable_notification", disable_notification.value());
    if (protect_content) postJson.insert("protect_content", protect_content.value());
    if (reply_to_message_id) postJson.insert("reply_to_message_id", reply_to_message_id.value());
    if (allow_sending_without_reply)
        postJson.insert("allow_sending_without_reply", allow_sending_without_reply.value());
    if (reply_markup)
    {
        if (std::holds_alternative<InlineKeyboardMarkup::Ptr>(reply_markup.value()))
            postJson.insert("reply_to_message_id",
                            toJsonValue(std::get<InlineKeyboardMarkup::Ptr>(reply_markup.value())));
        else if (std::holds_alternative<ReplyKeyboardMarkup::Ptr>(reply_markup.value()))
            postJson.insert("reply_to_message_id",
                            toJsonValue(std::get<ReplyKeyboardMarkup::Ptr>(reply_markup.value())));
        else if (std::holds_alternative<ReplyKeyboardRemove::Ptr>(reply_markup.value()))
            postJson.insert("reply_to_message_id",
                            toJsonValue(std::get<ReplyKeyboardRemove::Ptr>(reply_markup.value())));
        else if (std::holds_alternative<ForceReply::Ptr>(reply_markup.value()))
            postJson.insert("reply_to_message_id", toJsonValue(std::get<ForceReply::Ptr>(reply_markup.value())));
    };

    QJsonDocument jsonDocument(postJson);

    auto replyResponse = sendRequest("sendMessage", jsonDocument);

    if (replyResponse)
    {
        Message::Ptr message;

        readJsonObject(message, replyResponse.value(), "result");

        return message;
    }

    return std::nullopt;
}

std::optional<QVector<Update::Ptr>> Api::getUpdates(const std::optional<qint64>&           offset,
                                                    const std::optional<qint64>&           limit,
                                                    const std::optional<qint64>&           timeout,
                                                    const std::optional<QVector<QString>>& allowed_updates)
{
    if (m_token == "") return std::nullopt;

    QJsonObject postJson;

    if (offset) postJson.insert("parse_mode", offset.value());
    if (limit) postJson.insert("entities", toJsonValue(limit.value()));
    if (timeout) postJson.insert("disable_web_page_preview", timeout.value());
    if (allowed_updates) postJson.insert("disable_notification", toJsonValue(allowed_updates.value()));

    QJsonDocument jsonDocument(postJson);

    auto replyResponse = sendRequest("getUpdates", jsonDocument);

    if (replyResponse)
    {
        QVector<Update::Ptr> update;

        readJsonObject(update, replyResponse.value(), "result");

        return update;
    }

    return std::nullopt;
}

std::optional<User::Ptr> Api::getMe()
{
    if (m_token == "") return std::nullopt;

    auto replyResponse = sendRequest("getMe", QJsonDocument());

    if (replyResponse)
    {
        User::Ptr user;

        readJsonObject(user, replyResponse.value(), "result");

        return user;
    }

    return std::nullopt;
}

std::optional<QJsonObject> Api::sendRequest(const QString& method, const QJsonDocument& jsonDocument)
{
    QNetworkRequest request;
    request.setUrl(QUrl(m_url + m_token + "/" + method));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QEventLoop     eventLoop;
    QNetworkReply* reply = m_networkManager->post(request, jsonDocument.toJson());
    QObject::connect(reply, &QNetworkReply::finished, &eventLoop, &QEventLoop::quit);
    eventLoop.exec();

    QJsonDocument replyJsonDocument(QJsonDocument::fromJson(reply->readAll()));

    reply->deleteLater();

    if (replyJsonDocument.isObject())
    {
        QJsonObject replyJsonObject = replyJsonDocument.object();
        if (replyJsonObject.contains("ok") && replyJsonObject["ok"].isBool() && replyJsonObject["ok"].toBool() &&
            replyJsonObject.contains("result"))
        {
            replyJsonObject.remove("ok");
            return replyJsonObject;
        }
    }

    return std::nullopt;
}
}
