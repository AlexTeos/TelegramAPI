#include "tst_telegrammethods.h"

#include "../src/telegram/api.h"

using namespace Telegram;

void TestTelegramMethods::initTestCase()
{
    m_api.setToken("bottoken");
}

void TestTelegramMethods::cleanupTestCase() {}

void TestTelegramMethods::testApiSendMessage()
{
    m_api.sendMessage(295590000, "Test message");
}
