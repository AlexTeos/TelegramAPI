#include "tst_telegramapi.h"

#include "../src/telegram/types/chatmember.h"
#include "../src/telegram/types/inlinekeyboardmarkup.h"
#include "../src/telegram/types/message.h"
#include "../src/telegram/types/pollanswer.h"
#include "../src/telegram/types/update.h"

using namespace TelegramApi;

void TestTelegramApi::initTestCase() {}

void TestTelegramApi::cleanupTestCase() {}

void TestTelegramApi::testApiMessage()
{
    QString messageJson =
        "{\"message\":{\"message_id\":3,\"from\":{\"id\":9007199254740991,\"is_bot\":false,\"first_name\":\"test_first_"
        "name\",\"username\":\"test_username\",\"language_code\":\"ru\"},\"chat\":{\"id\":295590000,\"first_name\":"
        "\"test_first_name\",\"username\":\"test_username\",\"type\":\"private\"},\"date\":1645736477,\"text\":\"/"
        "start\",\"entities\":[{\"offset\":0,\"length\":6,\"type\":\"bot_command\"}]}}";
    Message::Ptr message;

    QJsonDocument loadDoc(QJsonDocument::fromJson(messageJson.toLatin1()));

    readValue(message, loadDoc.object(), "message");
}

void TestTelegramApi::testApiChatMember()
{
    QString chatMemberJson =
        "{\"new_chat_member\":{\"status\":\"creator\",\"user\":{\"id\":295590000,\"is_bot\":false,\"first_name\":"
        "\"User\",\"username\":\"user\",\"language_code\":\"ru\"}, \"is_anonymous\":false, \"custom_title\":\"test\"}}";

    ChatMember::Ptr chatMember;

    QJsonDocument loadDoc(QJsonDocument::fromJson(chatMemberJson.toLatin1()));

    readValue(chatMember, loadDoc.object(), "new_chat_member");
}

void TestTelegramApi::testApiUpdate()
{
    QString updateJson =
        "{\"ok\":true,\"result\":[{\"update_id\":642464933,\"message\":{\"message_id\":8,\"from\":{\"id\":295590000,"
        "\"is_bot\":false,\"first_name\":\"test_first_name\",\"username\":\"test_username\",\"language_code\":\"ru\"},"
        "\"chat\":{\"id\":295590000,\"first_name\":\"test_first_name\",\"username\":\"test_username\",\"type\":"
        "\"private\"},\"date\":1646071963,\"text\":\"/"
        "start\",\"entities\":[{\"offset\":0,\"length\":6,\"type\":\"bot_command\"}]}},{\"update_id\":652064934,"
        "\"message\":{\"message_id\":9,\"from\":{\"id\":295590000,\"is_bot\":false,\"first_name\":\"test_first_name\","
        "\"username\":\"test_username\",\"language_code\":\"ru\"},\"chat\":{\"id\":295590000,\"first_name\":\"test_"
        "first_name\",\"username\":\"test_username\",\"type\":\"private\"},\"date\":1646861286,\"text\":\"/"
        "start\",\"entities\":[{\"offset\":0,\"length\":6,\"type\":\"bot_command\"}]}},{\"update_id\":642664935,"
        "\"message\":{\"message_id\":10,\"from\":{\"id\":295590000,\"is_bot\":false,\"first_name\":\"test_first_name\","
        "\"username\":\"test_username\",\"language_code\":\"ru\"},\"chat\":{\"id\":295590000,\"first_name\":\"test_"
        "first_name\",\"username\":\"test_username\",\"type\":\"private\"},\"date\":1646761287,\"text\":\"/"
        "start\",\"entities\":[{\"offset\":0,\"length\":6,\"type\":\"bot_command\"}]}},{\"update_id\":642764936,"
        "\"message\":{\"message_id\":11,\"from\":{\"id\":295590000,\"is_bot\":false,\"first_name\":\"test_first_name\","
        "\"username\":\"test_username\",\"language_code\":\"ru\"},\"chat\":{\"id\":295590000,\"first_name\":\"test_"
        "first_name\",\"username\":\"test_username\",\"type\":\"private\"},\"date\":1646161287,\"text\":\"/"
        "start\",\"entities\":[{\"offset\":0,\"length\":6,\"type\":\"bot_command\"}]}},{\"update_id\":642084937,"
        "\"message\":{\"message_id\":12,\"from\":{\"id\":295590000,\"is_bot\":false,\"first_name\":\"test_first_name\","
        "\"username\":\"test_username\",\"language_code\":\"ru\"},\"chat\":{\"id\":295590000,\"first_name\":\"test_"
        "first_name\",\"username\":\"test_username\",\"type\":\"private\"},\"date\":1646160288,\"text\":\"/"
        "start\",\"entities\":[{\"offset\":0,\"length\":6,\"type\":\"bot_command\"}]}}]}";

    QVector<Update::Ptr> update;

    QJsonDocument loadDoc(QJsonDocument::fromJson(updateJson.toLatin1()));

    readValue(update, loadDoc.object(), "result");
}

void TestTelegramApi::testApiInlineKeyboardMarkup()
{
    QString inlineKeyboardMarkupJson =
        "{\"inlineKeyboardMarkup\":{\"inline_keyboard\":[[{\"text\":\"1\"},{\"text\":\"2\"},{\"text\":"
        "\"3\"}],[{\"text\":\"4\"}],[{\"text\":\"5\"},{\"text\":\"6\"}]]}}";

    InlineKeyboardMarkup::Ptr inlineKeyboardMarkup;

    QJsonDocument loadDoc(QJsonDocument::fromJson(inlineKeyboardMarkupJson.toLatin1()));

    readValue(inlineKeyboardMarkup, loadDoc.object(), "inlineKeyboardMarkup");
}

void TestTelegramApi::testApiPollAnswer()
{
    QString pollAnswerJson = "{\"poll_answer\":{\"poll_id\":\"1234\",\"user\":{\"id\":295590780,\"is_bot\":false,"
                             "\"first_name\":\"test_first_name\",\"username\":\"test_username\",\"language_code\":"
                             "\"ru\"},\"option_ids\":[9007199254740991,1,2,3,4,5,6]}}";

    PollAnswer::Ptr pollAnswer;

    QJsonDocument loadDoc(QJsonDocument::fromJson(pollAnswerJson.toLatin1()));

    readValue(pollAnswer, loadDoc.object(), "poll_answer");
}

void TestTelegramApi::testApiLocation()
{
    QString locationJson = "{\"location\":{\"latitude\":58.978341,\"longitude\":32.370649}}";

    Location::Ptr location;

    QJsonDocument loadDoc(QJsonDocument::fromJson(locationJson.toLatin1()));

    readValue(location, loadDoc.object(), "location");
}
