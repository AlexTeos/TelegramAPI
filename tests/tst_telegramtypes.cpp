#include "tst_telegramtypes.h"

#include "types/chatmemberowner.h"
#include "types/inlinekeyboardmarkup.h"
#include "types/message.h"
#include "types/pollanswer.h"
#include "types/update.h"

using namespace Telegram;

void TestTelegramTypes::initTestCase() {}

void TestTelegramTypes::cleanupTestCase() {}

void TestTelegramTypes::tesApiMessage()
{
#if QT_VERSION >= 0x060000
    qint64 id = 9007199254740991;
#else
    qint64 id = 295590000;
#endif

    QString messageJson = "{\"message\":{\"message_id\":3,\"from\":{\"id\":" + QString::number(id) +
                          ",\"is_bot\":false,\"first_name\":\"test_first_name\",\"username\":\"test_username\","
                          "\"language_code\":\"ru\"},\"chat\":{\"id\":295590000,\"first_name\":\"test_first_name\","
                          "\"username\":\"test_username\",\"type\":\"private\"},\"date\":1645736477,\"text\":\"/"
                          "start\",\"entities\":[{\"offset\":0,\"length\":6,\"type\":\"bot_command\"}]}}";
    Message::Ptr message;

    QJsonDocument jsonDocument(QJsonDocument::fromJson(messageJson.toLatin1()));

    readJsonObject(message, jsonDocument.object(), "message");

    QVERIFY(message);
    QVERIFY(message->m_message_id == 3);
    QVERIFY(message->m_date == 1645736477);
    QVERIFY(message->m_text == "/start");

    QVERIFY(message->m_from);
    QVERIFY(message->m_from->m_id == id);
    QVERIFY(message->m_from->m_is_bot == false);
    QVERIFY(message->m_from->m_first_name == "test_first_name");
    QVERIFY(message->m_from->m_username == "test_username");
    QVERIFY(message->m_from->m_language_code == "ru");

    QVERIFY(message->m_chat);
    QVERIFY(message->m_chat->m_id == 295590000);
    QVERIFY(message->m_chat->m_first_name == "test_first_name");
    QVERIFY(message->m_chat->m_username == "test_username");
    QVERIFY(message->m_chat->m_type == "private");

    QVERIFY(message->m_entities.size() == 1);
    QVERIFY(message->m_entities[0]);
    QVERIFY(message->m_entities[0]->m_offset == 0);
    QVERIFY(message->m_entities[0]->m_length == 6);
    QVERIFY(message->m_entities[0]->m_type == "bot_command");
}

void TestTelegramTypes::tesApiChatMember()
{
    QString chatMemberJson =
        "{\"new_chat_member\":{\"status\":\"creator\",\"user\":{\"id\":295590000,\"is_bot\":false,\"first_name\":"
        "\"User\",\"username\":\"user\",\"language_code\":\"ru\"}, \"is_anonymous\":false, \"custom_title\":\"test\"}}";

    ChatMember::Ptr chatMember;

    QJsonDocument jsonDocument(QJsonDocument::fromJson(chatMemberJson.toLatin1()));

    readJsonObject(chatMember, jsonDocument.object(), "new_chat_member");

    ChatMemberOwner::Ptr chatMemberOwner = chatMember.staticCast<ChatMemberOwner>();

    QVERIFY(chatMemberOwner);
    QVERIFY(chatMemberOwner->m_status == "creator");
    QVERIFY(chatMemberOwner->m_is_anonymous == false);
    QVERIFY(chatMemberOwner->m_custom_title == "test");

    QVERIFY(chatMemberOwner->m_user);
    QVERIFY(chatMemberOwner->m_user->m_id == 295590000);
    QVERIFY(chatMemberOwner->m_user->m_is_bot == false);
    QVERIFY(chatMemberOwner->m_user->m_first_name == "User");
    QVERIFY(chatMemberOwner->m_user->m_username == "user");
    QVERIFY(chatMemberOwner->m_user->m_language_code == "ru");
}

void TestTelegramTypes::tesApiUpdate()
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

    QJsonDocument jsonDocument(QJsonDocument::fromJson(updateJson.toLatin1()));

    readJsonObject(update, jsonDocument.object(), "result");

    QVERIFY(update.size() == 5);

    QVERIFY(update[0]);
    QVERIFY(update[0]->m_update_id == 642464933);

    QVERIFY(update[0]->m_message);
    QVERIFY(update[0]->m_message->m_message_id == 8);
    QVERIFY(update[0]->m_message->m_date == 1646071963);
    QVERIFY(update[0]->m_message->m_text == "/start");

    QVERIFY(update[0]->m_message->m_from);
    QVERIFY(update[0]->m_message->m_from->m_id == 295590000);
    QVERIFY(update[0]->m_message->m_from->m_is_bot == false);
    QVERIFY(update[0]->m_message->m_from->m_first_name == "test_first_name");
    QVERIFY(update[0]->m_message->m_from->m_username == "test_username");
    QVERIFY(update[0]->m_message->m_from->m_language_code == "ru");

    QVERIFY(update[0]->m_message->m_chat);
    QVERIFY(update[0]->m_message->m_chat->m_id == 295590000);
    QVERIFY(update[0]->m_message->m_chat->m_first_name == "test_first_name");
    QVERIFY(update[0]->m_message->m_chat->m_username == "test_username");
    QVERIFY(update[0]->m_message->m_chat->m_type == "private");

    QVERIFY(update[0]->m_message->m_entities.size() == 1);
    QVERIFY(update[0]->m_message->m_entities[0]);
    QVERIFY(update[0]->m_message->m_entities[0]->m_offset == 0);
    QVERIFY(update[0]->m_message->m_entities[0]->m_length == 6);
    QVERIFY(update[0]->m_message->m_entities[0]->m_type == "bot_command");

    QVERIFY(update[1]);
    QVERIFY(update[1]->m_update_id == 652064934);

    QVERIFY(update[1]->m_message);
    QVERIFY(update[1]->m_message->m_message_id == 9);
    QVERIFY(update[1]->m_message->m_date == 1646861286);
    QVERIFY(update[1]->m_message->m_text == "/start");

    QVERIFY(update[1]->m_message->m_from);
    QVERIFY(update[1]->m_message->m_from->m_id == 295590000);
    QVERIFY(update[1]->m_message->m_from->m_is_bot == false);
    QVERIFY(update[1]->m_message->m_from->m_first_name == "test_first_name");
    QVERIFY(update[1]->m_message->m_from->m_username == "test_username");
    QVERIFY(update[1]->m_message->m_from->m_language_code == "ru");

    QVERIFY(update[1]->m_message->m_chat);
    QVERIFY(update[1]->m_message->m_chat->m_id == 295590000);
    QVERIFY(update[1]->m_message->m_chat->m_first_name == "test_first_name");
    QVERIFY(update[1]->m_message->m_chat->m_username == "test_username");
    QVERIFY(update[1]->m_message->m_chat->m_type == "private");

    QVERIFY(update[1]->m_message->m_entities.size() == 1);
    QVERIFY(update[1]->m_message->m_entities[0]);
    QVERIFY(update[1]->m_message->m_entities[0]->m_offset == 0);
    QVERIFY(update[1]->m_message->m_entities[0]->m_length == 6);
    QVERIFY(update[1]->m_message->m_entities[0]->m_type == "bot_command");

    QVERIFY(update[2]);
    QVERIFY(update[2]->m_update_id == 642664935);

    QVERIFY(update[2]->m_message);
    QVERIFY(update[2]->m_message->m_message_id == 10);
    QVERIFY(update[2]->m_message->m_date == 1646761287);
    QVERIFY(update[2]->m_message->m_text == "/start");

    QVERIFY(update[2]->m_message->m_from);
    QVERIFY(update[2]->m_message->m_from->m_id == 295590000);
    QVERIFY(update[2]->m_message->m_from->m_is_bot == false);
    QVERIFY(update[2]->m_message->m_from->m_first_name == "test_first_name");
    QVERIFY(update[2]->m_message->m_from->m_username == "test_username");
    QVERIFY(update[2]->m_message->m_from->m_language_code == "ru");

    QVERIFY(update[2]->m_message->m_chat);
    QVERIFY(update[2]->m_message->m_chat->m_id == 295590000);
    QVERIFY(update[2]->m_message->m_chat->m_first_name == "test_first_name");
    QVERIFY(update[2]->m_message->m_chat->m_username == "test_username");
    QVERIFY(update[2]->m_message->m_chat->m_type == "private");

    QVERIFY(update[2]->m_message->m_entities.size() == 1);
    QVERIFY(update[2]->m_message->m_entities[0]);
    QVERIFY(update[2]->m_message->m_entities[0]->m_offset == 0);
    QVERIFY(update[2]->m_message->m_entities[0]->m_length == 6);
    QVERIFY(update[2]->m_message->m_entities[0]->m_type == "bot_command");

    QVERIFY(update[3]);
    QVERIFY(update[3]->m_update_id == 642764936);

    QVERIFY(update[3]->m_message);
    QVERIFY(update[3]->m_message->m_message_id == 11);
    QVERIFY(update[3]->m_message->m_date == 1646161287);
    QVERIFY(update[3]->m_message->m_text == "/start");

    QVERIFY(update[3]->m_message->m_from);
    QVERIFY(update[3]->m_message->m_from->m_id == 295590000);
    QVERIFY(update[3]->m_message->m_from->m_is_bot == false);
    QVERIFY(update[3]->m_message->m_from->m_first_name == "test_first_name");
    QVERIFY(update[3]->m_message->m_from->m_username == "test_username");
    QVERIFY(update[3]->m_message->m_from->m_language_code == "ru");

    QVERIFY(update[3]->m_message->m_chat);
    QVERIFY(update[3]->m_message->m_chat->m_id == 295590000);
    QVERIFY(update[3]->m_message->m_chat->m_first_name == "test_first_name");
    QVERIFY(update[3]->m_message->m_chat->m_username == "test_username");
    QVERIFY(update[3]->m_message->m_chat->m_type == "private");

    QVERIFY(update[3]->m_message->m_entities.size() == 1);
    QVERIFY(update[3]->m_message->m_entities[0]);
    QVERIFY(update[3]->m_message->m_entities[0]->m_offset == 0);
    QVERIFY(update[3]->m_message->m_entities[0]->m_length == 6);
    QVERIFY(update[3]->m_message->m_entities[0]->m_type == "bot_command");

    QVERIFY(update[4]);
    QVERIFY(update[4]->m_update_id == 642084937);

    QVERIFY(update[4]->m_message);
    QVERIFY(update[4]->m_message->m_message_id == 12);
    QVERIFY(update[4]->m_message->m_date == 1646160288);
    QVERIFY(update[4]->m_message->m_text == "/start");

    QVERIFY(update[4]->m_message->m_from);
    QVERIFY(update[4]->m_message->m_from->m_id == 295590000);
    QVERIFY(update[4]->m_message->m_from->m_is_bot == false);
    QVERIFY(update[4]->m_message->m_from->m_first_name == "test_first_name");
    QVERIFY(update[4]->m_message->m_from->m_username == "test_username");
    QVERIFY(update[4]->m_message->m_from->m_language_code == "ru");

    QVERIFY(update[4]->m_message->m_chat);
    QVERIFY(update[4]->m_message->m_chat->m_id == 295590000);
    QVERIFY(update[4]->m_message->m_chat->m_first_name == "test_first_name");
    QVERIFY(update[4]->m_message->m_chat->m_username == "test_username");
    QVERIFY(update[4]->m_message->m_chat->m_type == "private");

    QVERIFY(update[4]->m_message->m_entities.size() == 1);
    QVERIFY(update[4]->m_message->m_entities[0]);
    QVERIFY(update[4]->m_message->m_entities[0]->m_offset == 0);
    QVERIFY(update[4]->m_message->m_entities[0]->m_length == 6);
    QVERIFY(update[4]->m_message->m_entities[0]->m_type == "bot_command");
}

void TestTelegramTypes::tesApiInlineKeyboardMarkup()
{
    QString inlineKeyboardMarkupJson =
        "{\"inlineKeyboardMarkup\":{\"inline_keyboard\":[[{\"text\":\"1\"},{\"text\":\"2\"},{\"text\":"
        "\"3\"}],[{\"text\":\"4\"}],[{\"text\":\"5\"},{\"text\":\"6\"}]]}}";

    InlineKeyboardMarkup::Ptr inlineKeyboardMarkup;

    QJsonDocument jsonDocument(QJsonDocument::fromJson(inlineKeyboardMarkupJson.toLatin1()));

    readJsonObject(inlineKeyboardMarkup, jsonDocument.object(), "inlineKeyboardMarkup");

    QVERIFY(inlineKeyboardMarkup);
    QVERIFY(inlineKeyboardMarkup->m_inline_keyboard.size() == 3);

    QVERIFY(inlineKeyboardMarkup->m_inline_keyboard[0].size() == 3);
    QVERIFY(inlineKeyboardMarkup->m_inline_keyboard[0][0]);
    QVERIFY(inlineKeyboardMarkup->m_inline_keyboard[0][0]->m_text == "1");
    QVERIFY(inlineKeyboardMarkup->m_inline_keyboard[0][1]);
    QVERIFY(inlineKeyboardMarkup->m_inline_keyboard[0][1]->m_text == "2");
    QVERIFY(inlineKeyboardMarkup->m_inline_keyboard[0][2]);
    QVERIFY(inlineKeyboardMarkup->m_inline_keyboard[0][2]->m_text == "3");

    QVERIFY(inlineKeyboardMarkup->m_inline_keyboard[1].size() == 1);
    QVERIFY(inlineKeyboardMarkup->m_inline_keyboard[1][0]);
    QVERIFY(inlineKeyboardMarkup->m_inline_keyboard[1][0]->m_text == "4");

    QVERIFY(inlineKeyboardMarkup->m_inline_keyboard[2].size() == 2);
    QVERIFY(inlineKeyboardMarkup->m_inline_keyboard[2][0]);
    QVERIFY(inlineKeyboardMarkup->m_inline_keyboard[2][0]->m_text == "5");
    QVERIFY(inlineKeyboardMarkup->m_inline_keyboard[2][1]);
    QVERIFY(inlineKeyboardMarkup->m_inline_keyboard[2][1]->m_text == "6");
}

void TestTelegramTypes::tesApiPollAnswer()
{
    QString pollAnswerJson = "{\"poll_answer\":{\"poll_id\":\"1234\",\"user\":{\"id\":295590000,\"is_bot\":false,"
                             "\"first_name\":\"test_first_name\",\"username\":\"test_username\",\"language_code\":"
                             "\"ru\"},\"option_ids\":[295590000,1,2,3,4,5,6]}}";

    PollAnswer::Ptr pollAnswer;

    QJsonDocument jsonDocument(QJsonDocument::fromJson(pollAnswerJson.toLatin1()));

    readJsonObject(pollAnswer, jsonDocument.object(), "poll_answer");

    QVERIFY(pollAnswer);
    QVERIFY(pollAnswer->m_poll_id == "1234");

    QVERIFY(pollAnswer->m_user);
    QVERIFY(pollAnswer->m_user->m_id == 295590000);
    QVERIFY(pollAnswer->m_user->m_is_bot == false);
    QVERIFY(pollAnswer->m_user->m_first_name == "test_first_name");
    QVERIFY(pollAnswer->m_user->m_username == "test_username");
    QVERIFY(pollAnswer->m_user->m_language_code == "ru");

    QVERIFY(pollAnswer->m_option_ids.size() == 7);
    QVERIFY(pollAnswer->m_option_ids[0] == 295590000);
    QVERIFY(pollAnswer->m_option_ids[1] == 1);
    QVERIFY(pollAnswer->m_option_ids[2] == 2);
    QVERIFY(pollAnswer->m_option_ids[3] == 3);
    QVERIFY(pollAnswer->m_option_ids[4] == 4);
    QVERIFY(pollAnswer->m_option_ids[5] == 5);
    QVERIFY(pollAnswer->m_option_ids[6] == 6);
}

void TestTelegramTypes::tesApiLocation()
{
    QString locationJson = "{\"location\":{\"latitude\":58.978341,\"longitude\":32.370649}}";

    Location::Ptr location;

    QJsonDocument jsonDocument(QJsonDocument::fromJson(locationJson.toLatin1()));

    readJsonObject(location, jsonDocument.object(), "location");

    QVERIFY(location);
    QVERIFY(location->m_latitude == 58.978341);
    QVERIFY(location->m_longitude == 32.370649);
}

void TestTelegramTypes::tesApiMessageEntity()
{
    QString messageEntityJson = "{\"messageEntity\":[{\"type\":\"url\"}, {\"type\":\"phone_number\"}]}";

    QVector<MessageEntity::Ptr> messageEntity;

    QJsonDocument jsonDocument(QJsonDocument::fromJson(messageEntityJson.toLatin1()));

    readJsonObject(messageEntity, jsonDocument.object(), "messageEntity");

    QVERIFY(messageEntity.size() == 2);
    QVERIFY(messageEntity[0]);
    QVERIFY(messageEntity[0]->m_type == "url");
    QVERIFY(messageEntity[1]);
    QVERIFY(messageEntity[1]->m_type == "phone_number");
}
