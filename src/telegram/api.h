#ifndef API_H
#define API_H

#include <QNetworkAccessManager>

#include "types/forcereply.h"
#include "types/inlinekeyboardmarkup.h"
#include "types/messageentity.h"
#include "types/replykeyboardmarkup.h"
#include "types/replykeyboardremove.h"

namespace Telegram
{
class Api
{
public:
    Api();

    void setToken(const QString& token);
    void setUrl(const QString& url);

    bool sendMessage(const qint64&                                       chat_id,
                     const QString&                                      text,
                     const std::optional<QString>&                       parse_mode                  = std::nullopt,
                     const std::optional<QVector<MessageEntity::Ptr>>&   entities                    = std::nullopt,
                     const std::optional<bool>&                          disable_web_page_preview    = std::nullopt,
                     const std::optional<bool>&                          disable_notification        = std::nullopt,
                     const std::optional<bool>&                          protect_content             = std::nullopt,
                     const std::optional<qint64>&                        reply_to_message_id         = std::nullopt,
                     const std::optional<bool>&                          allow_sending_without_reply = std::nullopt,
                     const std::optional<std::variant<InlineKeyboardMarkup::Ptr,
                                                      ReplyKeyboardMarkup::Ptr,
                                                      ReplyKeyboardRemove::Ptr,
                                                      ForceReply::Ptr>>& reply_markup                = std::nullopt);

private:
    bool sendRequest(const QJsonDocument& jsonDocument);

    QScopedPointer<QNetworkAccessManager> m_networkManager;
    QString                               m_url = "https://api.telegram.org/";
    QString                               m_token;
};
}
#endif // API_H