#include "serverwidget.h"
#include "ui_serverwidget.h"

ServerWidget::ServerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ServerWidget)
{
    ui->setupUi(this);
    ser = NULL;
    soc = NULL;
    this->setWindowTitle("服务器端口：9000");
    ser = new QWebSocketServer("Server",QWebSocketServer::NonSecureMode,this);
    //服务器绑定
    //QString addrip = QString("192.168.2.240");
    ser->listen(QHostAddress::Any,9000); //设置IP地址  设置端口号
    //ui->textEditRead->append(QString::number(ser->serverPort()));
    //客户端连接成功
    connect(ser,&QWebSocketServer::newConnection,
            [=](){
                     //获取客户端信息：取出建立好的套接字
                        soc = ser->nextPendingConnection();
                        if(soc == NULL)
                        {
                            return;
                        }
                        QString address = soc->peerAddress().toString(); //QHostAddress->QString
                        quint16 port = soc->peerPort();
                        QString str = QString("[%1,%2]:连接成功").arg(address).arg(port);
                        //服务器显示连接成功
                        ui->textEditRead->append(str);

                        //等待数据接受
                        connect(soc,&QWebSocket::textMessageReceived,
                                [=](const QString &msg){
                                         ui->textEditRead->append(msg);
                                     });
                        //客户端断开
                        connect(soc,& QWebSocket::disconnected,
                                [=](){
                                        QString address = soc->peerAddress().toString(); //QHostAddress->QString
                                        quint16 port = soc->peerPort();
                                        QString str = QString("[%1,%2]:断开连接").arg(address).arg(port);
                                        //服务器显示断开连接
                                        ui->textEditRead->append(str);
                                        soc = NULL;
                                     });


                });
}

ServerWidget::~ServerWidget()
{
    delete ui;
}

void ServerWidget::on_buttonSend_clicked()
{
    if(soc == NULL)
    {
        return;
    }
    //服务器发送数据
    QString str = ui->textEditWrite->toPlainText();
    soc->sendTextMessage(str.toUtf8());


}

void ServerWidget::on_pushButton_2_clicked()
{
    if(soc == NULL)
    {
        return;
    }
    //断开客户端连接
    soc->deleteLater();
    ser->deleteLater();
    soc = NULL;

}
