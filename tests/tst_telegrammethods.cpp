#include "tst_telegrammethods.h"

#include "telegramapi.h"

using namespace Telegram;

void TestTelegramMethods::initTestCase()
{
    QVERIFY(m_api.start(m_bot_token));
}

void TestTelegramMethods::cleanupTestCase() {}

void TestTelegramMethods::testApiSendMessage()
{
    QVERIFY(m_api.sendMessage(m_user_id, "Test message"));
}

void TestTelegramMethods::testApiSendFormattedMessage()
{
    QVERIFY(m_api.sendMessage(m_user_id, "<b>Formatted</b> <i>message</i>", "HTML"));
}

void TestTelegramMethods::testApiSendMessageEntity()
{
    QString messageEntityJson = "{\"messageEntity\":[{\"type\":\"spoiler\",\"offset\":13,\"length\":7}]}";

    QVector<MessageEntity::Ptr> messageEntity;

    QJsonDocument messageEntityJsonDocument(QJsonDocument::fromJson(messageEntityJson.toLatin1()));

    readJsonObject(messageEntity, messageEntityJsonDocument.object(), "messageEntity");

    QVERIFY(m_api.sendMessage(m_user_id, "Message with spoiler", std::nullopt, messageEntity));
}

void TestTelegramMethods::testApiSendReplyKeyboardMarkup()
{
    QString replyKeyboardMarkupJson =
        "{\"replyKeyboardMarkup\":{\"keyboard\":[[{\"text\":\"1\"},{\"text\":\"2\"},{\"text\":"
        "\"3\"}],[{\"text\":\"4\"}],[{\"text\":\"5\"},{\"text\":\"6\"}]],\"one_time_keyboard\":true}}";

    ReplyKeyboardMarkup::Ptr replyKeyboardMarkup;

    QJsonDocument replyKeyboardMarkupJsonDocument(QJsonDocument::fromJson(replyKeyboardMarkupJson.toLatin1()));

    readJsonObject(replyKeyboardMarkup, replyKeyboardMarkupJsonDocument.object(), "replyKeyboardMarkup");

    QVERIFY(m_api.sendMessage(m_user_id,
                              "Message with ReplyKeyboardMarkup",
                              std::nullopt,
                              std::nullopt,
                              std::nullopt,
                              std::nullopt,
                              std::nullopt,
                              std::nullopt,
                              std::nullopt,
                              std::optional(replyKeyboardMarkup)));

    QString replyKeyboardRemoveJson = "{\"replyKeyboardRemove\":{}}";

    ReplyKeyboardRemove::Ptr replyKeyboardRemove;

    QJsonDocument replyKeyboardRemoveJsonDocument(QJsonDocument::fromJson(replyKeyboardRemoveJson.toLatin1()));

    readJsonObject(replyKeyboardRemove, replyKeyboardRemoveJsonDocument.object(), "replyKeyboardRemove");

    QVERIFY(m_api.sendMessage(m_user_id,
                              "Message with ReplyKeyboardRemove",
                              std::nullopt,
                              std::nullopt,
                              std::nullopt,
                              std::nullopt,
                              std::nullopt,
                              std::nullopt,
                              std::nullopt,
                              std::optional(replyKeyboardRemove)));
}

void TestTelegramMethods::testApiSendInlineKeyboardMarkup()
{
    QString inlineKeyboardMarkupJson =
        "{\"inlineKeyboardMarkup\":{\"inline_keyboard\":[[{\"text\":\"1\",\"callback_data\":\"1\"},{\"text\":\"2\","
        "\"callback_data\":\"2\"},{\"text\":\"3\",\"callback_data\":\"3\"}],[{\"text\":\"4\",\"callback_data\":\"4\"}],"
        "[{\"text\":\"5\",\"callback_data\":\"5\"},{\"text\":\"6\",\"callback_data\":\"6\"}]]}}";

    InlineKeyboardMarkup::Ptr inlineKeyboardMarkup;

    QJsonDocument inlineKeyboardMarkupJsonDocument(QJsonDocument::fromJson(inlineKeyboardMarkupJson.toLatin1()));

    readJsonObject(inlineKeyboardMarkup, inlineKeyboardMarkupJsonDocument.object(), "inlineKeyboardMarkup");

    QVERIFY(m_api.sendMessage(m_user_id,
                              "Message with InlineKeyboardMarkup",
                              std::nullopt,
                              std::nullopt,
                              std::nullopt,
                              std::nullopt,
                              std::nullopt,
                              std::nullopt,
                              std::nullopt,
                              std::optional(inlineKeyboardMarkup)));
}

void TestTelegramMethods::testApiEditMessageText()
{
    Message::Ptr message = m_api.sendMessage(m_user_id, "This message will be edited").value();
    QVERIFY(message);

    QVERIFY(m_api.editMessageText("This message <s>will be edited</s> is edited",
                                  message->m_chat->m_id,
                                  message->m_message_id,
                                  std::nullopt,
                                  "HTML"));
}

void TestTelegramMethods::testApiGetUpdates()
{
    QVERIFY(m_api.getUpdates());
}

void TestTelegramMethods::testApiGetMe()
{
    QVERIFY(m_api.getMe());
}

void TestTelegramMethods::testMyCommands()
{
    QString commandsJson =
        "{\"commands\":[{\"command\":\"test_command_1\",\"description\":\"First test command description"
        "\"},{\"command\":\"test_command_2\",\"description\":\"Second test command description"
        "\"},{\"command\":\"test_command_3\",\"description\":\"Third test command description\"}]}";

    QJsonDocument commandsJsonDocument(QJsonDocument::fromJson(commandsJson.toLatin1()));

    QVector<BotCommand::Ptr> commands;
    readJsonObject(commands, commandsJsonDocument.object(), "commands");

    m_api.setMyCommands(commands);
    auto setMyCommandsResult = m_api.setMyCommands(commands);
    QVERIFY(setMyCommandsResult);
    QVERIFY(setMyCommandsResult.value());

    auto getMyCommandsResult = m_api.getMyCommands();
    QVERIFY(getMyCommandsResult);
    QVERIFY(getMyCommandsResult.value().size() == commands.size());
    for (int i = 0; i < commands.size(); ++i)
    {
        QVERIFY(commands[i]->m_command == getMyCommandsResult.value()[i]->m_command);
        QVERIFY(commands[i]->m_description == getMyCommandsResult.value()[i]->m_description);
    }

    auto deleteMyCommands = m_api.deleteMyCommands();
    QVERIFY(deleteMyCommands);
    QVERIFY(deleteMyCommands.value());

    auto getMyCommandsAfterDeleteResult = m_api.getMyCommands();
    QVERIFY(getMyCommandsAfterDeleteResult);
    QVERIFY(getMyCommandsAfterDeleteResult.value().size() == 0);
}

void TestTelegramMethods::testMenuButton()
{
    MenuButton::Ptr menuButton;

    // Default
    QString       menuButtonDefaultJson = "{\"menu_button\":{\"type\":\"default\"}}";
    QJsonDocument menuButtonDefaultJsonDocument(QJsonDocument::fromJson(menuButtonDefaultJson.toLatin1()));
    readJsonObject(menuButton, menuButtonDefaultJsonDocument.object(), "menu_button");
    MenuButtonDefault::Ptr menuButtonDefault          = menuButton.staticCast<MenuButtonDefault>();
    auto                   setMenuButtonDefaultResult = m_api.setChatMenuButton(m_user_id, menuButtonDefault);
    QVERIFY(setMenuButtonDefaultResult);
    QVERIFY(setMenuButtonDefaultResult.value());

    auto getChatMenuButtonDefaultResult = m_api.getChatMenuButton(m_user_id);
    QVERIFY(getChatMenuButtonDefaultResult);
    MenuButtonDefault::Ptr menuButtonDefaultResult =
        getChatMenuButtonDefaultResult.value().staticCast<MenuButtonDefault>();
    QVERIFY(menuButtonDefaultResult->m_type == MenuButtonDefault::Type);

    // Commands
    QString       menuButtonCommandsJson = "{\"menu_button\":{\"type\":\"commands\"}}";
    QJsonDocument menuButtonCommandsJsonDocument(QJsonDocument::fromJson(menuButtonCommandsJson.toLatin1()));
    readJsonObject(menuButton, menuButtonCommandsJsonDocument.object(), "menu_button");
    MenuButtonCommands::Ptr menuButtonCommands          = menuButton.staticCast<MenuButtonCommands>();
    auto                    setMenuButtonCommandsResult = m_api.setChatMenuButton(m_user_id, menuButtonCommands);
    QVERIFY(setMenuButtonCommandsResult);
    QVERIFY(setMenuButtonCommandsResult.value());

    auto getChatMenuButtonCommandsResult = m_api.getChatMenuButton(m_user_id);
    QVERIFY(getChatMenuButtonCommandsResult);
    MenuButtonCommands::Ptr menuButtonCommandsResult =
        getChatMenuButtonCommandsResult.value().staticCast<MenuButtonCommands>();
    QVERIFY(menuButtonCommandsResult->m_type == MenuButtonCommands::Type);
}
