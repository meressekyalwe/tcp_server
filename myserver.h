#ifndef MYSERVER_H
#define MYSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>


class MyServer : public QObject
{
 Q_OBJECT

public:
   explicit MyServer(QObject *parent = 0);

public slots:
   void slotNewConnection();
   void slotServerRead();
   void slotClientDisconnected();
   void onClientData();

private:
   QTcpServer* mTcpServer;
   QTcpSocket* mTcpSocket;
};

#endif // MYSERVER_H

#include <main.moc>
