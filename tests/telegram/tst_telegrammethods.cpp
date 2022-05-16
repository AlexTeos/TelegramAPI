#include "tst_telegrammethods.h"

#include "../src/telegram/api.h"
#include "../src/telegram/types/inlinekeyboardbutton.h"
#include "../src/telegram/types/messageentity.h"

using namespace Telegram;

void TestTelegramMethods::initTestCase()
{
    m_api.setToken("bottoken");
}

void TestTelegramMethods::cleanupTestCase() {}

void TestTelegramMethods::testApiSendMessage()
{
    QVERIFY(m_api.sendMessage(m_user_id, "Test message"));
}

void TestTelegramMethods::testApiSendMessageComplicated()
{
    QString inlineKeyboardMarkupJson =
        "{\"inlineKeyboardMarkup\":{\"inline_keyboard\":[[{\"text\":\"1\"},{\"text\":\"2\"},{\"text\":"
        "\"3\"}],[{\"text\":\"4\"}],[{\"text\":\"5\"},{\"text\":\"6\"}]]}}";

    InlineKeyboardMarkup::Ptr inlineKeyboardMarkup;

    QJsonDocument inlineKeyboardMarkupJsonDocument(QJsonDocument::fromJson(inlineKeyboardMarkupJson.toLatin1()));

    readJsonObject(inlineKeyboardMarkup, inlineKeyboardMarkupJsonDocument.object(), "inlineKeyboardMarkup");

    QString messageEntityJson = "{\"messageEntity\":[{\"type\":\"url\"}]}";

    QVector<MessageEntity::Ptr> messageEntity;

    QJsonDocument messageEntityJsonDocument(QJsonDocument::fromJson(inlineKeyboardMarkupJson.toLatin1()));

    readJsonObject(messageEntity, messageEntityJsonDocument.object(), "messageEntity");

    QVERIFY(m_api.sendMessage(m_user_id,
                              "<b>Test</b> <i>message</i>",
                              "HTML",
                              messageEntity,
                              false,
                              false,
                              false,
                              std::nullopt,
                              true,
                              inlineKeyboardMarkup));
}

void TestTelegramMethods::testApiGetUpdates()
{
    QVERIFY(m_api.getUpdates());
}

void TestTelegramMethods::testApiGetMe()
{
    QVERIFY(m_api.getMe());
}
