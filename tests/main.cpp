#include "tst_telegrammethods.h"
#include "tst_telegramtypes.h"

int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);

    TESTLIB_SELFCOVERAGE_START(TestObject)
    TestTelegramTypes   tst_telegramTypes;
    TestTelegramMethods tst_telegramMethods;
    QTEST_SET_MAIN_SOURCE_PATH

    return QTest::qExec(&tst_telegramTypes, argc, argv) or QTest::qExec(&tst_telegramMethods, argc, argv);
}
