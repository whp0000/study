#include "mywidget.h"
#include "ui_mywidget.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QPluginLoader>

myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::myWidget)
{
    ui->setupUi(this);
    loadMySqlDriver();
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("MapInfo");
    db.setUserName("root");
    db.setPassword("1");
    int ok = db.open();
    //qDebug()<<u8"aa据库"<<ok;
    if(ok){
          QMessageBox::information(this, "infor", "success");
    }else{
          QMessageBox::information(this, "infor", "open failed");
          qDebug()<<"警告","无法连接数据库";
    }
}

myWidget::~myWidget()
{
    delete ui;
}

void myWidget::loadMySqlDriver()
{
    QPluginLoader loader;
    // MySQL 驱动插件的路径
//    loader.setFileName("/Users/Biao/Qt5.4.0/5.4/clang_64/plugins/sqldrivers/libqsqlmysql.dylib");
    loader.setFileName("/home/whp/run/QT/5.12.9/gcc_64/plugins/sqldrivers/libqsqlmysql.so");
    qDebug() << loader.load();
    qDebug() << loader.errorString();
}
