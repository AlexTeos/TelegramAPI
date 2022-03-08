#include <QtAlgorithms>
#include <QtTest>

class TestTelegramTypes : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase();
    void cleanupTestCase();
    void tesApiMessage();
    void tesApiChatMember();
    void tesApiUpdate();
    void tesApiInlineKeyboardMarkup();
    void tesApiPollAnswer();
    void tesApiLocation();
    void tesApiMessageEntity();
};
