#include <QCoreApplication>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>

#include "telegram/message.h"

int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);

    QString messageJson =
        "{\"message\":{\"message_id\":3,\"from\":{\"id\":295590780,\"is_bot\":false,\"first_name\":\"Alexander\","
        "\"username\":\"alexshemalex\",\"language_code\":\"ru\"},\"chat\":{\"id\":295590780,\"first_name\":"
        "\"Alexander\",\"username\":\"alexshemalex\",\"type\":\"private\"},\"date\":1645730477,\"text\":\"/"
        "start\",\"entities\":[{\"offset\":0,\"length\":6,\"type\":\"bot_command\"}]}}";

    TelegramApi::Message::Ptr message;

    QJsonDocument loadDoc(QJsonDocument::fromJson(messageJson.toLatin1()));

    TelegramApi::readValue(message, loadDoc.object(), "message");

    return a.exec();
}
