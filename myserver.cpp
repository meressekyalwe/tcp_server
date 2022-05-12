#include "myserver.h"
#include <QTcpServer>
#include <QString>
#include <QTcpSocket>
#include <QDataStream>
#include <QTime>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtSql/QtSql>
#include <QSqlError>


MyServer::MyServer(QObject *parent)
{
    if (listen(QHostAddress::Any, 80))
    {
        qDebug() << "Listening";
    }

    else
    {
        qDebug() << "Error while starting " << errorString();
    }
}

MyServer::MyServer(int nPort)
{
    if (listen(QHostAddress::Any, nPort))
    {
        qDebug() << "Listening";
    }

    else
    {
        qDebug() << "Error while starting " << errorString();
    }
}

void MyServer::incommingConnection(int handle)
{
    tcpSocket = new QTcpSocket();

    tcpSocket->setSocketDescriptor(handle);

    connect(tcpSocket, &QTcpSocket::readyRead, this, &MyServer::onReadyRead);
    connect(tcpSocket, &QTcpSocket::disconnected, this, &MyServer::onDisconnected);

    qDebug() << "connection in comming";
}

void MyServer::onReadyRead()
{
    qDebug() << tcpSocket->readAll();

    QString response = "HTTP/1.1 200 OK\r\n\r\n%1";
    tcpSocket->write( response.arg(QTime::currentTime().toString()).toUtf8());
    tcpSocket->disconnectFromHost();
}

void MyServer::onDisconnected()
{
    tcpSocket->close();
    tcpSocket->deleteLater();
}

