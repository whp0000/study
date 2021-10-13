#include "mywidget.h"
#include "ui_mywidget.h"
#include "EasyIni.h"
#include <QDebug>
myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::myWidget)
{
    ui->setupUi(this);
    on_pushButtonRefresh_2_clicked();
}

myWidget::~myWidget()
{
    delete ui;
}


void myWidget::on_pushButtonRefresh_clicked()
{
    ui->textEdit->clear();
    const QString path=qApp->applicationDirPath()+"/ini/easyini.ini";
    QFile file(path);
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    QTextStream in(&file);
    ui->textEdit->setText(in.readAll());
    file.close();
}

void myWidget::on_pushButtonRefresh_2_clicked()
{
    using namespace Tool;
    const QString path=qApp->applicationDirPath()+"/ini/easyini.ini";
    qDebug()<<"write"<<path;
    EasyIni ini(path,EasyIni::ReadWrite);
    ini.setValue(ui->lineEditgroup->text(),ui->lineEditkey->text(),ui->lineEditvalue->text());
    ui->lineEditgroup->clear();
    ui->lineEditkey->clear();
    ui->lineEditvalue->clear();
}
