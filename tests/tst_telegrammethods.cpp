#include "tst_telegrammethods.h"

#include "telegramapi.h"
#include "types/inlinekeyboardbutton.h"
#include "types/messageentity.h"

using namespace Telegram;

void TestTelegramMethods::initTestCase()
{
    QVERIFY(m_api.start(m_bot_token));
}

void TestTelegramMethods::cleanupTestCase() {}

void TestTelegramMethods::testApiSendMessage()
{
    QVERIFY(m_api.sendMessage(m_user_id, "Test message"));
}

void TestTelegramMethods::testApiSendFormattedMessage()
{
    QVERIFY(m_api.sendMessage(m_user_id, "<b>Formatted</b> <i>message</i>", "HTML"));
}

void TestTelegramMethods::testApiSendMessageEntity()
{
    QString messageEntityJson = "{\"messageEntity\":[{\"type\":\"spoiler\",\"offset\":13,\"length\":7}]}";

    QVector<MessageEntity::Ptr> messageEntity;

    QJsonDocument messageEntityJsonDocument(QJsonDocument::fromJson(messageEntityJson.toLatin1()));

    readJsonObject(messageEntity, messageEntityJsonDocument.object(), "messageEntity");

    QVERIFY(m_api.sendMessage(m_user_id, "Message with spoiler", std::nullopt, messageEntity));
}

void TestTelegramMethods::testApiSendReplyKeyboardMarkup()
{
    QString replyKeyboardMarkupJson =
        "{\"replyKeyboardMarkup\":{\"keyboard\":[[{\"text\":\"1\"},{\"text\":\"2\"},{\"text\":"
        "\"3\"}],[{\"text\":\"4\"}],[{\"text\":\"5\"},{\"text\":\"6\"}]],\"one_time_keyboard\":true}}";

    ReplyKeyboardMarkup::Ptr replyKeyboardMarkup;

    QJsonDocument replyKeyboardMarkupJsonDocument(QJsonDocument::fromJson(replyKeyboardMarkupJson.toLatin1()));

    readJsonObject(replyKeyboardMarkup, replyKeyboardMarkupJsonDocument.object(), "replyKeyboardMarkup");

    QVERIFY(m_api.sendMessage(m_user_id,
                              "Message with ReplyKeyboardMarkup",
                              std::nullopt,
                              std::nullopt,
                              std::nullopt,
                              std::nullopt,
                              std::nullopt,
                              std::nullopt,
                              std::nullopt,
                              replyKeyboardMarkup));

    QString replyKeyboardRemoveJson = "{\"replyKeyboardRemove\":{}}";

    ReplyKeyboardRemove::Ptr replyKeyboardRemove;

    QJsonDocument replyKeyboardRemoveJsonDocument(QJsonDocument::fromJson(replyKeyboardRemoveJson.toLatin1()));

    readJsonObject(replyKeyboardRemove, replyKeyboardRemoveJsonDocument.object(), "replyKeyboardRemove");

    QVERIFY(m_api.sendMessage(m_user_id,
                              "Message with ReplyKeyboardRemove",
                              std::nullopt,
                              std::nullopt,
                              std::nullopt,
                              std::nullopt,
                              std::nullopt,
                              std::nullopt,
                              std::nullopt,
                              replyKeyboardRemove));
}

void TestTelegramMethods::testApiSendInlineKeyboardMarkup()
{
    QString inlineKeyboardMarkupJson =
        "{\"inlineKeyboardMarkup\":{\"inline_keyboard\":[[{\"text\":\"1\",\"callback_data\":\"1\"},{\"text\":\"2\","
        "\"callback_data\":\"2\"},{\"text\":\"3\",\"callback_data\":\"3\"}],[{\"text\":\"4\",\"callback_data\":\"4\"}],"
        "[{\"text\":\"5\",\"callback_data\":\"5\"},{\"text\":\"6\",\"callback_data\":\"6\"}]]}}";

    InlineKeyboardMarkup::Ptr inlineKeyboardMarkup;

    QJsonDocument inlineKeyboardMarkupJsonDocument(QJsonDocument::fromJson(inlineKeyboardMarkupJson.toLatin1()));

    readJsonObject(inlineKeyboardMarkup, inlineKeyboardMarkupJsonDocument.object(), "inlineKeyboardMarkup");

    QVERIFY(m_api.sendMessage(m_user_id,
                              "Message with InlineKeyboardMarkup",
                              std::nullopt,
                              std::nullopt,
                              std::nullopt,
                              std::nullopt,
                              std::nullopt,
                              std::nullopt,
                              std::nullopt,
                              inlineKeyboardMarkup));
}

void TestTelegramMethods::testApiEditMessageText()
{
    Message::Ptr message = m_api.sendMessage(m_user_id, "This message will be edited").value();
    QVERIFY(message);

    QVERIFY(m_api.editMessageText("This message <s>will be edited</s> is edited",
                                  message->m_chat->m_id,
                                  message->m_message_id,
                                  std::nullopt,
                                  "HTML"));
}

void TestTelegramMethods::testApiGetUpdates()
{
    QVERIFY(m_api.getUpdates());
}

void TestTelegramMethods::testApiGetMe()
{
    QVERIFY(m_api.getMe());
}
