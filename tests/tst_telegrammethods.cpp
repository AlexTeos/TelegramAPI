#include "tst_telegrammethods.h"

#include "api.h"
#include "types/inlinekeyboardbutton.h"
#include "types/messageentity.h"

using namespace Telegram;

void TestTelegramMethods::initTestCase()
{
    m_api.start("bottoken");
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
}

void TestTelegramMethods::testApiGetUpdates()
{
    QVERIFY(m_api.getUpdates());
}

void TestTelegramMethods::testApiGetMe()
{
    QVERIFY(m_api.getMe());
}
