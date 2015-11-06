#ifndef NETCLIENT_H
#define NETCLIENT_H
#include <QTcpSocket>
#include <QString>
class NetClient: public QObject
{
    Q_OBJECT

public:
    NetClient();
    void connectToServer(QString serverIp,quint16 port);
    QString getCurrentConfig(){return currentConfig;}

private slots:
    void readConfig();
    void displayError(QAbstractSocket::SocketError socketError);

private:
    QTcpSocket *tcpSocket;
    QString currentConfig;
    quint16 blockSize;
};

#endif // NETCLIENT_H
