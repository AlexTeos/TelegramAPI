#include "tst_telegramapi.h"

#include "../src/telegram/chatmember.h"
#include "../src/telegram/message.h"
#include "../src/telegram/update.h"

using namespace TelegramApi;

void TestTelegramApi::initTestCase() {}

void TestTelegramApi::cleanupTestCase() {}

void TestTelegramApi::testApiMessage()
{
    QString messageJson =
        "{\"message\":{\"message_id\":3,\"from\":{\"id\":295590780,\"is_bot\":false,\"first_name\":\"Alexander\","
        "\"username\":\"alexshemalex\",\"language_code\":\"ru\"},\"chat\":{\"id\":295590780,\"first_name\":"
        "\"Alexander\",\"username\":\"alexshemalex\",\"type\":\"private\"},\"date\":1645730477,\"text\":\"/"
        "start\",\"entities\":[{\"offset\":0,\"length\":6,\"type\":\"bot_command\"}]}}";
    Message::Ptr message;

    QJsonDocument loadDoc(QJsonDocument::fromJson(messageJson.toLatin1()));

    readValue(message, loadDoc.object(), "message");
}

void TestTelegramApi::testApiChatMember()
{
    QString chatMemberJson = "{\"new_chat_member\":{\"status\":\"creator\",\"user\":{\"id\":295590000,\"is_bot\":false,"
                             "\"first_name\":\"User\",\"username\":\"user\",\"language_code\":\"ru\"}, "
                             "\"is_anonymous\":false, \"custom_title\":\"test\"}}";

    ChatMember::Ptr chatMember;

    QJsonDocument loadDoc(QJsonDocument::fromJson(chatMemberJson.toLatin1()));

    readValue(chatMember, loadDoc.object(), "new_chat_member");
}

void TestTelegramApi::testApiUpdate()
{
    QString updateJson =
        "{\"ok\":true,\"result\":[{\"update_id\":642064933,\"message\":{\"message_id\":8,\"from\":{\"id\":"
        "295590780,\"is_bot\":false,\"first_name\":\"Alexander\",\"username\":\"alexshemalex\",\"language_code\":"
        "\"ru\"},\"chat\":{\"id\":295590780,\"first_name\":\"Alexander\",\"username\":\"alexshemalex\",\"type\":"
        "\"private\"},\"date\":1646081963,\"text\":\"/"
        "start\",\"entities\":[{\"offset\":0,\"length\":6,\"type\":\"bot_command\"}]}}]}";

    QVector<Update::Ptr> update;

    QJsonDocument loadDoc(QJsonDocument::fromJson(updateJson.toLatin1()));

    readArray(update, loadDoc.object(), "result");
}

void TestTelegramApi::testApiUpdateArray()
{
    QString updateJson =
        "{\"ok\":true,\"result\":{\"update_id\":642064933,\"message\":{\"message_id\":8,\"from\":{\"id\":"
        "295590780,\"is_bot\":false,\"first_name\":\"Alexander\",\"username\":\"alexshemalex\",\"language_code\":"
        "\"ru\"},\"chat\":{\"id\":295590780,\"first_name\":\"Alexander\",\"username\":\"alexshemalex\",\"type\":"
        "\"private\"},\"date\":1646081963,\"text\":\"/"
        "start\",\"entities\":[{\"offset\":0,\"length\":6,\"type\":\"bot_command\"}]}}}";

    TelegramApi::Update::Ptr update;

    QJsonDocument loadDoc(QJsonDocument::fromJson(updateJson.toLatin1()));

    TelegramApi::readValue(update, loadDoc.object(), "result");
}
