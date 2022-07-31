#include "tst_telegrammethods.h"
#include "tst_telegramtypes.h"

int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);

    QSettings settings(QSettings::IniFormat, QSettings::UserScope, "TelegramApiUT");

    if (argc > 2)
    {
        settings.setValue("Token", argv[1]);
        settings.setValue("UserId", argv[2]);
        argv += 2;
        argc -= 2;
    }

    TESTLIB_SELFCOVERAGE_START(TestObject)
    TestTelegramTypes   tst_telegramTypes;
    TestTelegramMethods tst_telegramMethods(settings.value("Token").toString(), settings.value("UserId").toLongLong());
    QTEST_SET_MAIN_SOURCE_PATH
    return QTest::qExec(&tst_telegramTypes, argc, argv) or QTest::qExec(&tst_telegramMethods, argc, argv);
}
