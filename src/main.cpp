#include <QCoreApplication>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>

#include "telegram/message.h"

int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
