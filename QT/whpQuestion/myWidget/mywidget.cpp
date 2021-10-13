#include "includes.h"

myWidget::myWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myWidget)
{
    ui->setupUi(this);
    thread1 = NULL;
}

myWidget::~myWidget()
{
    delete ui;
}

void myWidget::on_pushButtonBegin_clicked()
{
    static qint16 i = 0;

    if ((thread1 == NULL) || (thread1->isRunning() == false))
    {
        showDebug(QString("开始\n"));
        ui->textBrowserDebug->moveCursor(QTextCursor::End);
        thread1 = new threadHandle(this);
        connect(thread1,&threadHandle::showDebugSignal,this,&myWidget::showDebug);
        thread1->ThdBegin();
        thread1->SetShowStr(QString("%1").arg(i));
        thread1->start();
        i++;
    }
    else
    {
        showDebug(QString("线程正在运行，无法重复开启\n"));
        ui->textBrowserDebug->moveCursor(QTextCursor::End);
    }

}

void myWidget::on_pushButtonEnd_clicked()
{
    if (thread1 == NULL)
    {
      showDebug(QString("请先开启线程\n"));
      return;
    }
    showDebug(QString("结束\n"));
    ui->textBrowserDebug->moveCursor(QTextCursor::End);
    thread1->ThdEnd();
    thread1->quit();
    //delete thread1;  //自动回收
    thread1 = NULL;
}

void myWidget::showDebug(QString str)
{
    ui->textBrowserDebug->insertPlainText(str);
    ui->textBrowserDebug->moveCursor(QTextCursor::End);
}


void myWidget::on_pushButtonPulse_clicked()
{
    if (thread1 == NULL)
    {
      showDebug(QString("请先开启线程\n"));
      return;
    }
    showDebug(QString("暂停\n"));
    ui->textBrowserDebug->moveCursor(QTextCursor::End);
    thread1->ThdPulse();
}

void myWidget::on_pushButtonContinue_clicked()
{
    if (thread1 == NULL)
    {
      showDebug(QString("请先开启线程\n"));
      return;
    }
    showDebug(QString("继续\n"));
    ui->textBrowserDebug->moveCursor(QTextCursor::End);
    thread1->ThdContinue();
}
