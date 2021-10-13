#include "clientwidget.h"
#include "ui_clientwidget.h"
#include <QHostAddress>

clientwidget::clientwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::clientwidget)
{
    ui->setupUi(this);
    ConnectFlag = 0;
    soc = NULL;
    soc = new QWebSocket;
    soc->setParent(this);
    this->setWindowTitle("客户端");
    connect(soc,&QWebSocket::connected,
            [=](){
                    ui->textEditRead->append("与服务器连接成功");
                    ConnectFlag = 1;
                 });
    connect(soc,&QWebSocket::textMessageReceived,
            [=](const QString &msg){
                    ui->textEditRead->append(msg);
                 });

}

clientwidget::~clientwidget()
{
    delete ui;
}

void clientwidget::on_pushButtonConnect_clicked()
{
    QString url = ui->lineEditURL->text();
    if (url != NULL)
    {
        soc->open(QUrl(url));
    }
}

void clientwidget::on_buttonSend_clicked()
{
     QString str = ui->textEditWrite->toPlainText();
     if(str != NULL){
        soc->sendTextMessage(str);
     }
}

void clientwidget::on_buttonClose_clicked()
{
    soc->deleteLater();
    soc->close();
}

void clientwidget::on_pushButtonConnect_2_released()
{
    if (ConnectFlag == 1)
    {
        ui->textEditRead->append("与服务器断开连接");
        soc->close();
        ConnectFlag = 0;
    }
}
