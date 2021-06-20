//
// Created by jafar on 4/12/17.
//

#ifndef UNTITLED1_SERVER_H
#define UNTITLED1_SERVER_H
#include <QUdpSocket>

class QTimer;
class QHostAddress;
class QDialog;
class QTcpSocket;
class QTcpServer;

class Server : public QObject
{
    Q_OBJECT
public:
    Server(QHostAddress * = new QHostAddress("127.0.0.1"), quint16 = 8888);

public slots:
    void createConnection();
    void read();
private:
    QHostAddress *serverAddress;
    quint16 serverPort;
    QTcpServer *server;
    QList<QTcpSocket*> *clients;

    void read(QTcpSocket*);
};

#endif //UNTITLED1_SERVER_H
