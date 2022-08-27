#include "telegramapi.h"

#include <QEventLoop>
#include <QNetworkReply>
#include <QNetworkRequest>

namespace Telegram
{
Api::Api() : m_networkManager(new QNetworkAccessManager()) {}

bool Api::start(const QString& token)
{
    m_token = token;

    return getMe().has_value();
}

std::optional<Message::Ptr> Api::sendMessage(
    const std::variant<qint64, QString>&              chat_id,
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
    QJsonObject postJson{{"text", text}};

    if (std::holds_alternative<qint64>(chat_id))
        postJson.insert("chat_id", std::get<qint64>(chat_id));
    else
        postJson.insert("chat_id", std::get<QString>(chat_id));

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
            postJson.insert("reply_markup", toJsonValue(std::get<InlineKeyboardMarkup::Ptr>(reply_markup.value())));
        else if (std::holds_alternative<ReplyKeyboardMarkup::Ptr>(reply_markup.value()))
            postJson.insert("reply_markup", toJsonValue(std::get<ReplyKeyboardMarkup::Ptr>(reply_markup.value())));
        else if (std::holds_alternative<ReplyKeyboardRemove::Ptr>(reply_markup.value()))
            postJson.insert("reply_markup", toJsonValue(std::get<ReplyKeyboardRemove::Ptr>(reply_markup.value())));
        else if (std::holds_alternative<ForceReply::Ptr>(reply_markup.value()))
            postJson.insert("reply_markup", toJsonValue(std::get<ForceReply::Ptr>(reply_markup.value())));
    };

    QJsonDocument jsonDocument(postJson);

    auto replyResponse = sendRequest("sendMessage", jsonDocument);

    if (replyResponse)
    {
        Message::Ptr message;

        if (readJsonObject(message, replyResponse.value(), "result")) return message;
    }

    return std::nullopt;
}

std::optional<QVector<Update::Ptr>> Api::getUpdates(const std::optional<qint64>&           offset,
                                                    const std::optional<qint64>&           limit,
                                                    const std::optional<qint64>&           timeout,
                                                    const std::optional<QVector<QString>>& allowed_updates)
{
    QJsonObject postJson;

    if (offset) postJson.insert("offset", offset.value());
    if (limit) postJson.insert("limit", limit.value());
    if (timeout) postJson.insert("timeout", timeout.value());
    if (allowed_updates) postJson.insert("allowed_updates", toJsonValue(allowed_updates.value()));

    QJsonDocument jsonDocument(postJson);

    auto replyResponse = sendRequest("getUpdates", jsonDocument);

    if (replyResponse)
    {
        QVector<Update::Ptr> update;

        if (readJsonObject(update, replyResponse.value(), "result")) return update;
    }

    return std::nullopt;
}

std::optional<User::Ptr> Api::getMe()
{
    auto replyResponse = sendRequest("getMe", QJsonDocument());

    if (replyResponse)
    {
        User::Ptr user;

        if (readJsonObject(user, replyResponse.value(), "result")) return user;
    }

    return std::nullopt;
}

std::optional<bool> Api::answerCallbackQuery(const QString&                callback_query_id,
                                             const std::optional<QString>& text,
                                             const std::optional<bool>&    show_alert,
                                             const std::optional<QString>& url,
                                             const std::optional<qint64>&  cache_time)
{
    QJsonObject postJson{{"callback_query_id", callback_query_id}};

    if (text) postJson.insert("text", text.value());
    if (show_alert) postJson.insert("show_alert", show_alert.value());
    if (url) postJson.insert("url", url.value());
    if (cache_time) postJson.insert("cache_time", cache_time.value());

    QJsonDocument jsonDocument(postJson);

    auto replyResponse = sendRequest("answerCallbackQuery", jsonDocument);

    if (replyResponse)
    {
        bool result;

        if (readJsonObject(result, replyResponse.value(), "result")) return result;
    }

    return std::nullopt;
}

std::optional<std::variant<Message::Ptr, bool>> Api::editMessageText(
    const QString&                                      text,
    const std::optional<std::variant<qint64, QString>>& chat_id,
    const std::optional<qint64>&                        message_id,
    const std::optional<QString>&                       inline_message_id,
    const std::optional<QString>&                       parse_mode,
    const std::optional<QVector<MessageEntity::Ptr>>&   entities,
    const std::optional<bool>&                          disable_web_page_preview,
    const std::optional<InlineKeyboardMarkup::Ptr>&     reply_markup)
{
    if ((not inline_message_id) && not(chat_id && message_id)) return std::nullopt;

    QJsonObject postJson{{"text", text}};

    if (chat_id)
    {
        if (std::holds_alternative<qint64>(chat_id.value()))
            postJson.insert("chat_id", std::get<qint64>(chat_id.value()));
        else
            postJson.insert("chat_id", std::get<QString>(chat_id.value()));
    }

    if (message_id) postJson.insert("message_id", message_id.value());
    if (inline_message_id) postJson.insert("inline_message_id", inline_message_id.value());
    if (parse_mode) postJson.insert("parse_mode", parse_mode.value());
    if (entities) postJson.insert("entities", toJsonValue(entities.value()));
    if (disable_web_page_preview) postJson.insert("disable_web_page_preview", disable_web_page_preview.value());
    if (reply_markup) postJson.insert("reply_markup", toJsonValue(reply_markup.value()));

    QJsonDocument jsonDocument(postJson);

    auto replyResponse = sendRequest("editMessageText", jsonDocument);

    if (replyResponse)
    {
        if (inline_message_id)
        {
            bool result;

            if (readJsonObject(result, replyResponse.value(), "result")) return result;
        }
        else
        {
            Message::Ptr message;

            if (readJsonObject(message, replyResponse.value(), "result")) return message;
        }
    }

    return std::nullopt;
}

std::optional<bool> Api::setChatMenuButton(
    const std::optional<std::variant<qint64, QString>>& chat_id,
    const std::optional<std::variant<MenuButtonCommands::Ptr, MenuButtonWebApp::Ptr, MenuButtonDefault::Ptr>>&
        menu_button)
{
    QJsonObject postJson;

    if (chat_id)
    {
        if (std::holds_alternative<qint64>(chat_id.value()))
            postJson.insert("chat_id", std::get<qint64>(chat_id.value()));
        else
            postJson.insert("chat_id", std::get<QString>(chat_id.value()));
    }

    if (menu_button)
    {
        if (std::holds_alternative<MenuButtonCommands::Ptr>(menu_button.value()))
            postJson.insert("menu_button", toJsonValue(std::get<MenuButtonCommands::Ptr>(menu_button.value())));
        else if (std::holds_alternative<MenuButtonWebApp::Ptr>(menu_button.value()))
            postJson.insert("menu_button", toJsonValue(std::get<MenuButtonWebApp::Ptr>(menu_button.value())));
        else if (std::holds_alternative<MenuButtonDefault::Ptr>(menu_button.value()))
            postJson.insert("menu_button", toJsonValue(std::get<MenuButtonDefault::Ptr>(menu_button.value())));
    };

    QJsonDocument jsonDocument(postJson);

    auto replyResponse = sendRequest("setChatMenuButton", jsonDocument);

    if (replyResponse)
    {
        bool result;

        if (readJsonObject(result, replyResponse.value(), "result")) return result;
    }

    return std::nullopt;
}

std::optional<std::variant<MenuButtonCommands::Ptr, MenuButtonWebApp::Ptr, MenuButtonDefault::Ptr>> Api::
    getChatMenuButton(const std::optional<std::variant<qint64, QString>>& chat_id)
{
    QJsonObject postJson;

    if (chat_id)
    {
        if (std::holds_alternative<qint64>(chat_id.value()))
            postJson.insert("chat_id", std::get<qint64>(chat_id.value()));
        else
            postJson.insert("chat_id", std::get<QString>(chat_id.value()));
    }

    QJsonDocument jsonDocument(postJson);

    auto replyResponse = sendRequest("getChatMenuButton", jsonDocument);

    if (replyResponse)
    {
        MenuButton::Ptr result;

        if (readJsonObject(result, replyResponse.value(), "result"))
        {
            if (result->m_type == MenuButtonCommands::Type)
                return result.staticCast<MenuButtonCommands>();
            else if (result->m_type == MenuButtonWebApp::Type)
                return result.staticCast<MenuButtonWebApp>();
            else if (result->m_type == MenuButtonDefault::Type)
                return result.staticCast<MenuButtonDefault>();
        }
    }

    return std::nullopt;
}

std::optional<QJsonObject> Api::sendRequest(const QString& method, const QJsonDocument& jsonDocument)
{
    if (m_token == "") return std::nullopt;

    QNetworkRequest request;
    request.setUrl(QUrl(m_url + "bot" + m_token + "/" + method));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QEventLoop     eventLoop;
    QNetworkReply* reply = m_networkManager->post(request, jsonDocument.toJson());
    QObject::connect(reply, &QNetworkReply::finished, &eventLoop, &QEventLoop::quit);
    eventLoop.exec();
    QByteArray    arr = reply->readAll();
    QJsonDocument replyJsonDocument(QJsonDocument::fromJson(arr));

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
