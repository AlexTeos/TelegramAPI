#ifndef TELEGRAMAPI_H
#define TELEGRAMAPI_H

#include <QNetworkAccessManager>

#include "types/botcommand.h"
#include "types/botcommandscope.h"
#include "types/forcereply.h"
#include "types/inlinekeyboardmarkup.h"
#include "types/menubutton.h"
#include "types/messageentity.h"
#include "types/replykeyboardmarkup.h"
#include "types/replykeyboardremove.h"
#include "types/update.h"

namespace Telegram
{
struct Error
{
    Error() {}
    Error(const quint32& errorCode, const QString& description) : m_errorCode(errorCode), m_description(description) {}
    quint32 m_errorCode;
    QString m_description;
};
typedef Error NetworkError;
typedef Error TelegramError;

class Api : public QObject
{
    Q_OBJECT
public:
    Api();

    bool start(const QString& token);

    template <typename KeyboardType = InlineKeyboardMarkup::Ptr>
    std::optional<Telegram::Message::Ptr> sendMessage(
        const std::variant<qint64, QString>&              chat_id,
        const QString&                                    text,
        const std::optional<QString>&                     parse_mode                  = std::nullopt,
        const std::optional<QVector<MessageEntity::Ptr>>& entities                    = std::nullopt,
        const std::optional<bool>&                        disable_web_page_preview    = std::nullopt,
        const std::optional<bool>&                        disable_notification        = std::nullopt,
        const std::optional<bool>&                        protect_content             = std::nullopt,
        const std::optional<qint64>&                      reply_to_message_id         = std::nullopt,
        const std::optional<bool>&                        allow_sending_without_reply = std::nullopt,
        const std::optional<KeyboardType>&                reply_markup                = std::nullopt)
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
        if (reply_markup) postJson.insert("reply_markup", toJsonValue(reply_markup.value()));

        QJsonDocument jsonDocument(postJson);

        auto replyResponse = sendRequest("sendMessage", jsonDocument);

        if (replyResponse)
        {
            Message::Ptr message;

            if (readJsonObject(message, replyResponse.value(), "result")) return message;
        }

        return std::nullopt;
    }

    std::optional<QVector<Telegram::Update::Ptr>> getUpdates(
        const std::optional<qint64>&           offset          = std::nullopt,
        const std::optional<qint64>&           limit           = std::nullopt,
        const std::optional<qint64>&           timeout         = std::nullopt,
        const std::optional<QVector<QString>>& allowed_updates = std::nullopt);

    std::optional<Telegram::User::Ptr> getMe();

    std::optional<bool> answerCallbackQuery(const QString&                callback_query_id,
                                            const std::optional<QString>& text       = std::nullopt,
                                            const std::optional<bool>&    show_alert = std::nullopt,
                                            const std::optional<QString>& url        = std::nullopt,
                                            const std::optional<qint64>&  cache_time = std::nullopt);

    std::optional<std::variant<Message::Ptr, bool>> editMessageText(
        const QString&                                      text,
        const std::optional<std::variant<qint64, QString>>& chat_id,
        const std::optional<qint64>&                        message_id               = std::nullopt,
        const std::optional<QString>&                       inline_message_id        = std::nullopt,
        const std::optional<QString>&                       parse_mode               = std::nullopt,
        const std::optional<QVector<MessageEntity::Ptr>>&   entities                 = std::nullopt,
        const std::optional<bool>&                          disable_web_page_preview = std::nullopt,
        const std::optional<InlineKeyboardMarkup::Ptr>&     reply_markup             = std::nullopt);

    std::optional<bool> setChatMenuButton(const std::optional<std::variant<qint64, QString>>& chat_id = std::nullopt,
                                          const std::optional<MenuButton::Ptr>& menu_button           = std::nullopt);

    std::optional<MenuButton::Ptr> getChatMenuButton(
        const std::optional<std::variant<qint64, QString>>& chat_id = std::nullopt);

    std::optional<bool> setMyCommands(const QVector<BotCommand::Ptr>&            commands,
                                      const std::optional<BotCommandScope::Ptr>& scope         = std::nullopt,
                                      const std::optional<QString>&              language_code = std::nullopt);

    std::optional<bool> deleteMyCommands(const std::optional<BotCommandScope::Ptr>& scope         = std::nullopt,
                                         const std::optional<QString>&              language_code = std::nullopt);

    std::optional<QVector<BotCommand::Ptr>> getMyCommands(
        const std::optional<BotCommandScope::Ptr>& scope         = std::nullopt,
        const std::optional<QString>&              language_code = std::nullopt);

signals:
    void telegramError(TelegramError error);
    void networkError(NetworkError error);

private:
    std::optional<QJsonObject> sendRequest(const QString& method, const QJsonDocument& jsonDocument);

    QScopedPointer<QNetworkAccessManager> m_networkManager;
    QString                               m_url = "https://api.telegram.org/";
    QString                               m_token;
};
}
#endif // TELEGRAMAPI_H
