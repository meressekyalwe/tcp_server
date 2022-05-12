#ifndef MYSERVER_H
#define MYSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QSqlDatabase>


class MyServer : public QTcpServer
{
    Q_OBJECT

public:

    explicit MyServer(QObject *parent = nullptr);

    MyServer(int nPort);

    void incommingConnection(int handle);

public slots:

    void onReadyRead();

    void onDisconnected();

private:

   QTcpSocket* tcpSocket;
};

#endif // MYSERVER_H

#include <main.moc>
