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
                              replyKeyboardMarkup));

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
                              replyKeyboardRemove));
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
                              inlineKeyboardMarkup));
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
        "{\"commands\":[{\"command\":\"test_command_1\",\"description\":\"First test command description "
        "\"},{\"command\":\"test_command_2\",\"description\":\"Second test command description "
        "\"},{\"command\":\"test_command_3\",\"description\":\"Third test command description \"}]}";

    QJsonDocument commandsJsonDocument(QJsonDocument::fromJson(commandsJson.toLatin1()));

    QVector<BotCommand::Ptr> commands;
    readJsonObject(commands, commandsJsonDocument.object(), "menu_button");

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
    QVERIFY(std::holds_alternative<MenuButtonDefault::Ptr>(getChatMenuButtonDefaultResult.value()));
    QVERIFY(std::get<MenuButtonDefault::Ptr>(getChatMenuButtonDefaultResult.value())->m_type == "default");

    // Commands
    QString       menuButtonCommandsJson = "{\"menu_button\":{\"type\":\"commands\"}}";
    QJsonDocument menuButtonCommandsJsonDocument(QJsonDocument::fromJson(menuButtonCommandsJson.toLatin1()));
    readJsonObject(menuButton, menuButtonCommandsJsonDocument.object(), "menu_button");
    MenuButtonCommands::Ptr menuButtonCommands          = menuButton.staticCast<MenuButtonCommands>();
    auto                    setMenuButtonCommandsResult = m_api.setChatMenuButton(m_user_id, menuButtonCommands);
    QVERIFY(setMenuButtonCommandsResult);
    QVERIFY(setMenuButtonCommandsResult.value());

    auto getChatMenuButtonCommandsResult = m_api.getChatMenuButton(m_user_id);
    QVERIFY(getChatMenuButtonDefaultResult);
    QVERIFY(std::holds_alternative<MenuButtonCommands::Ptr>(getChatMenuButtonCommandsResult.value()));
    QVERIFY(std::get<MenuButtonCommands::Ptr>(getChatMenuButtonCommandsResult.value())->m_type == "commands");

    // Web App
    //QString menuButtonWebAppJson =
    //    "{\"menu_button\":{\"type\":\"web_app\",\"text\":\"TestLink\",\"web_app\":{\"m_url\":\"https://test.link/\"}}}";
    //QJsonDocument menuButtonWebAppJsonDocument(QJsonDocument::fromJson(menuButtonWebAppJson.toLatin1()));
    //readJsonObject(menuButton, menuButtonWebAppJsonDocument.object(), "menu_button");
    //MenuButtonWebApp::Ptr menuButtonWebApp          = menuButton.staticCast<MenuButtonWebApp>();
    //auto                  setMenuButtonWebAppResult = m_api.setChatMenuButton(m_user_id, menuButtonWebApp);
    //QVERIFY(setMenuButtonWebAppResult);
    //QVERIFY(setMenuButtonWebAppResult.value());

    //auto getChatMenuButtonWebAppResult = m_api.getChatMenuButton(m_user_id);
    //QVERIFY(getChatMenuButtonDefaultResult);
    //QVERIFY(std::holds_alternative<MenuButtonWebApp::Ptr>(getChatMenuButtonWebAppResult.value()));
    //QVERIFY(std::get<MenuButtonWebApp::Ptr>(getChatMenuButtonWebAppResult.value())->m_type == "web_app");
    //QVERIFY(std::get<MenuButtonWebApp::Ptr>(getChatMenuButtonWebAppResult.value())->m_text == "TestLink");
    //QVERIFY(std::get<MenuButtonWebApp::Ptr>(getChatMenuButtonWebAppResult.value())->m_web_app->m_url ==
    //        "https://test.link/");
}
