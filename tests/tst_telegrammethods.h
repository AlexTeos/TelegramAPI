#include <QtAlgorithms>
#include <QtTest>

#include "telegramapi.h"

class TestTelegramMethods : public QObject
{
    Q_OBJECT
public:
    TestTelegramMethods(QString bot_token, qint64 user_id) : m_bot_token(bot_token), m_user_id(user_id){};

private slots:
    void initTestCase();
    void cleanupTestCase();
    void testApiSendMessage();
    void testApiSendFormattedMessage();
    void testApiSendMessageEntity();
    void testApiSendReplyKeyboardMarkup();
    void testApiSendInlineKeyboardMarkup();
    void testApiEditMessageText();
    void testApiGetUpdates();
    void testApiGetMe();
    void testMenuButton();

private:
    Telegram::Api m_api;
    QString       m_bot_token;
    qint64        m_user_id;
};
