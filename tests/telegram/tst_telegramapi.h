#include <QtAlgorithms>
#include <QtTest>

class TestTelegramApi : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase();
    void cleanupTestCase();
    void testApiMessage();
    void testApiChatMember();
    void testApiUpdate();
    void testApiUpdateArray();
};
