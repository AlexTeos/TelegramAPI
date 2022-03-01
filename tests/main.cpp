#include "telegram/tst_telegramapi.h"

int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);

    TESTLIB_SELFCOVERAGE_START(TestObject)
    TestTelegramApi tst_telegramapi;
    QTEST_SET_MAIN_SOURCE_PATH
    return QTest::qExec(&tst_telegramapi, argc, argv);
}
