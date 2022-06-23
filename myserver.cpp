#include "myserver.h"

#include <QDebug>
#include <QCoreApplication>

MyServer::MyServer(QObject *parent) : QObject(parent)
{
    mTcpServer = new QTcpServer(this);

    connect(mTcpServer, &QTcpServer::newConnection, this, &MyServer::slotNewConnection);

    if(!mTcpServer->listen(QHostAddress::Any, 8080)){
        qDebug() << "server is not started";
    } else {
        qDebug() << "server is started";
    }
}

void MyServer::slotNewConnection()
{
    mTcpSocket = mTcpServer->nextPendingConnection();

    mTcpSocket->write("Successfully established a connection with the server !\r\n");

    connect(mTcpSocket, &QTcpSocket::readyRead, this, &MyServer::slotServerRead);
    connect(mTcpSocket, &QTcpSocket::disconnected, this, &MyServer::slotClientDisconnected);
}

void MyServer::slotServerRead()
{
    while(mTcpSocket->bytesAvailable() > 0)
    {
        QByteArray array = mTcpSocket->readAll();

        mTcpSocket->write(array);
    }
}

void MyServer::slotClientDisconnected()
{
    mTcpSocket->close();
}

void MyServer::onClientData()
{
    //QByteArray array = mTcpSocket->readAll();

}

