#include <QtAlgorithms>
#include <QtTest>

#include "../src/telegram/api.h"

class TestTelegramMethods : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase();
    void cleanupTestCase();
    void testApiSendMessage();

private:
    Telegram::Api m_api;
};
