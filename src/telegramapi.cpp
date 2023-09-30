#include "telegramapi.h"

#include <QEventLoop>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QtGlobal>

#include "types/menubuttoncommands.h"
#include "types/menubuttondefault.h"
#include "types/menubuttonwebapp.h"

namespace Telegram
{
Api::Api() : m_networkManager(new QNetworkAccessManager()) {}

bool Api::start(const QString& token)
{
    m_token = token;

    return getMe().has_value();
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

        if (readJsonObject(update, replyResponse.value(), "result"))
            return update;
        else
            qWarning() << "No result field in response";
    }
    else
        qWarning() << "Incorrect response";

    return std::nullopt;
}

std::optional<User::Ptr> Api::getMe()
{
    auto replyResponse = sendRequest("getMe", QJsonDocument());

    if (replyResponse)
    {
        User::Ptr user;

        if (readJsonObject(user, replyResponse.value(), "result"))
            return user;
        else
            qWarning() << "No result field in response";
    }
    else
        qWarning() << "Incorrect response";

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

        if (readJsonObject(result, replyResponse.value(), "result"))
            return result;
        else
            qWarning() << "No result field in response";
    }
    else
        qWarning() << "Incorrect response";

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

            if (readJsonObject(result, replyResponse.value(), "result"))
                return result;
            else
                qWarning() << "No result field in response";
        }
        else
        {
            Message::Ptr message;

            if (readJsonObject(message, replyResponse.value(), "result"))
                return message;
            else
                qWarning() << "No result field in response";
        }
    }
    else
        qWarning() << "Incorrect response";

    return std::nullopt;
}

std::optional<bool> Api::setChatMenuButton(const std::optional<std::variant<qint64, QString>>& chat_id,
                                           const std::optional<MenuButton::Ptr>&               menu_button)
{
    QJsonObject postJson;

    if (chat_id)
    {
        if (std::holds_alternative<qint64>(chat_id.value()))
            postJson.insert("chat_id", std::get<qint64>(chat_id.value()));
        else
            postJson.insert("chat_id", std::get<QString>(chat_id.value()));
    }

    if (menu_button) postJson.insert("menu_button", toJsonValue(menu_button.value()));

    QJsonDocument jsonDocument(postJson);

    auto replyResponse = sendRequest("setChatMenuButton", jsonDocument);

    if (replyResponse)
    {
        bool result;

        if (readJsonObject(result, replyResponse.value(), "result"))
            return result;
        else
            qWarning() << "No result field in response";
    }
    else
        qWarning() << "Incorrect response";

    return std::nullopt;
}

std::optional<MenuButton::Ptr> Api::getChatMenuButton(const std::optional<std::variant<qint64, QString>>& chat_id)
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
        MenuButton::Ptr typeResult;

        if (readJsonObject(typeResult, replyResponse.value(), "result"))
        {
            if (typeResult->m_type == MenuButtonCommands::Type)
            {
                MenuButtonCommands::Ptr result;
                if (readJsonObject(result, replyResponse.value(), "result")) return result;
            }
            else if (typeResult->m_type == MenuButtonWebApp::Type)
            {
                MenuButtonWebApp::Ptr result;
                if (readJsonObject(result, replyResponse.value(), "result")) return result;
            }
            else if (typeResult->m_type == MenuButtonDefault::Type)
            {
                MenuButtonDefault::Ptr result;
                if (readJsonObject(result, replyResponse.value(), "result")) return result;
            }
            qWarning() << "Unrecognized m_type:" << typeResult->m_type;
        }
        else
            qWarning() << "No result field in response";
    }
    else
        qWarning() << "Incorrect response";

    return std::nullopt;
}

std::optional<bool> Api::setMyCommands(const QVector<BotCommand::Ptr>&            commands,
                                       const std::optional<BotCommandScope::Ptr>& scope,
                                       const std::optional<QString>&              language_code)
{
    QJsonObject postJson;

    postJson.insert("commands", toJsonValue(commands));

    if (scope) postJson.insert("scope", toJsonValue(scope.value()));
    if (language_code) postJson.insert("language_code", toJsonValue(language_code.value()));

    QJsonDocument jsonDocument(postJson);

    auto replyResponse = sendRequest("setMyCommands", jsonDocument);

    if (replyResponse)
    {
        bool result;

        if (readJsonObject(result, replyResponse.value(), "result"))
            return result;
        else
            qWarning() << "No result field in response";
    }
    else
        qWarning() << "Incorrect response";

    return std::nullopt;
}

std::optional<bool> Api::deleteMyCommands(const std::optional<BotCommandScope::Ptr>& scope,
                                          const std::optional<QString>&              language_code)
{
    QJsonObject postJson;

    if (scope) postJson.insert("scope", toJsonValue(scope.value()));
    if (scope) postJson.insert("language_code", toJsonValue(language_code.value()));

    QJsonDocument jsonDocument(postJson);

    auto replyResponse = sendRequest("deleteMyCommands", jsonDocument);

    if (replyResponse)
    {
        bool result;

        if (readJsonObject(result, replyResponse.value(), "result"))
            return result;
        else
            qWarning() << "No result field in response";
    }
    else
        qWarning() << "Incorrect response";

    return std::nullopt;
}

std::optional<QVector<BotCommand::Ptr>> Api::getMyCommands(const std::optional<BotCommandScope::Ptr>& scope,
                                                           const std::optional<QString>&              language_code)
{
    QJsonObject postJson;

    if (scope) postJson.insert("scope", toJsonValue(scope.value()));
    if (scope) postJson.insert("language_code", toJsonValue(language_code.value()));

    QJsonDocument jsonDocument(postJson);

    auto replyResponse = sendRequest("getMyCommands", jsonDocument);

    if (replyResponse)
    {
        QVector<BotCommand::Ptr> result;

        if (readJsonObject(result, replyResponse.value(), "result"))
            return result;
        else
            qWarning() << "No result field in response";
    }
    else
        qWarning() << "Incorrect response";

    return std::nullopt;
}

std::optional<QJsonObject> Api::sendRequest(const QString& method, const QJsonDocument& jsonDocument)
{
    if (m_token == "") return std::nullopt;

    QNetworkRequest request;
    request.setUrl(QUrl(m_url + "bot" + m_token + "/" + method));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QSslConfiguration conf = request.sslConfiguration();
    conf.setPeerVerifyMode(QSslSocket::VerifyNone);
    request.setSslConfiguration(conf);

    QEventLoop     eventLoop;
    QNetworkReply* reply = m_networkManager->post(request, jsonDocument.toJson());
    QObject::connect(reply, &QNetworkReply::finished, &eventLoop, &QEventLoop::quit);
    eventLoop.exec();
    if (reply->error() == QNetworkReply::NoError)
    {
        QByteArray arr = reply->readAll();
        reply->deleteLater();
        QJsonDocument replyJsonDocument(QJsonDocument::fromJson(arr));
        if (replyJsonDocument.isObject())
        {
            QJsonObject replyJsonObject = replyJsonDocument.object();
            if (replyJsonObject.contains("ok") && replyJsonObject["ok"].isBool() && replyJsonObject["ok"].toBool() &&
                replyJsonObject.contains("result"))
            {
                replyJsonObject.remove("ok");
                qDebug() << "Successful request:" << request.url() << "data" << jsonDocument.toJson()
                         << "reply:" << arr;
                return replyJsonObject;
            }
            else
            {
                if (replyJsonObject.contains("error_code") && replyJsonObject["error_code"].isDouble() &&
                    replyJsonObject.contains("description") && replyJsonObject["description"].isString())
                {
                    qWarning() << "Telegram responded with an error. Request:" << request.url()
                               << "data:" << jsonDocument.toJson() << "reply:" << arr;
                    emit telegramError(TelegramError(replyJsonObject["error_code"].toDouble(),
                                                     replyJsonObject["description"].toString()));
                }
            }
        }
        else
        {
            qWarning() << "Telegram responded with incorrect json format. Request:" << request.url() << "data:" << arr;
            emit telegramError(TelegramError(0, "Incorrect response format"));
        }

        return std::nullopt;
    }

    QString replyError = reply->errorString();
    reply->deleteLater();
    qWarning() << "Incorrect reply format. Request:" << request.url() << "; reply error:" << replyError;
    emit networkError(NetworkError(reply->error(), replyError));

    return std::nullopt;
}

}
