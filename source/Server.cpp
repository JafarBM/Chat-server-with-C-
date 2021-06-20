//
// Created by jafar on 4/12/17.
//

#include <header/Server.h>

#include <QDialog>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTimer>
#include <iostream>
using namespace std;

Server::Server(QHostAddress *serverAddress, quint16 serverPort) : serverAddress(serverAddress), serverPort(serverPort)
{
    cout << "1" << endl;
    clients = new QList<QTcpSocket*>();
    server = new QTcpServer(this);
    server -> listen(*serverAddress, serverPort);
    connect(server, SIGNAL(newConnection()), this, SLOT(createConnection()));
}

void Server::createConnection()
{
    cout << 2 << endl;
    QTcpSocket *client = server -> nextPendingConnection();
    connect(client, SIGNAL(readyRead()), this, SLOT(read()));
    clients -> append(client);
}

void Server::read()
{
    cout << 3 << endl;
    for(int i = 0; i < clients -> size(); ++i)
        if(clients -> at(i) -> bytesAvailable() > 0)
            read(clients -> at(i));
}

void Server::read(QTcpSocket * client)
{
    QByteArray data = client -> readAll();
    for(int j = 0; j < clients -> size(); ++ j)
        clients -> at(j) -> write(data);
}