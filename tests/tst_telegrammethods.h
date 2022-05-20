#include <QtAlgorithms>
#include <QtTest>

#include "api.h"

class TestTelegramMethods : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase();
    void cleanupTestCase();
    void testApiSendMessage();
    void testApiSendMessageComplicated();
    void testApiGetUpdates();
    void testApiGetMe();

private:
    Telegram::Api m_api;
    qint64        m_user_id = 295590000;
};