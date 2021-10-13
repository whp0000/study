#include "includes.h"
#include <qDebug>
GameWidget::GameWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameWidget)
{
    ui->setupUi(this);

    ShowPageStart();

    connect(ui->pushButton0,&QPushButton::released,this,&GameWidget::GameRunUseButton_released);
    connect(ui->pushButton1,&QPushButton::released,this,&GameWidget::GameRunUseButton_released);
    connect(ui->pushButton2,&QPushButton::released,this,&GameWidget::GameRunUseButton_released);
    connect(ui->pushButton3,&QPushButton::released,this,&GameWidget::GameRunUseButton_released);
    connect(ui->pushButton4,&QPushButton::released,this,&GameWidget::GameRunUseButton_released);
    connect(ui->pushButton5,&QPushButton::released,this,&GameWidget::GameRunUseButton_released);
    connect(ui->pushButton6,&QPushButton::released,this,&GameWidget::GameRunUseButton_released);
    connect(ui->pushButton7,&QPushButton::released,this,&GameWidget::GameRunUseButton_released);
    connect(ui->pushButton8,&QPushButton::released,this,&GameWidget::GameRunUseButton_released);
    connect(ui->pushButton9,&QPushButton::released,this,&GameWidget::GameRunUseButton_released);

//开始界面显示
    QStringList DiffChose = (QStringList() <<"简单" <<"一般" <<"困难" <<"地狱");// 10s  30s 1分钟 2分钟
    ui->comboBox->addItems(DiffChose);
    QStringList TimeChose = (QStringList() <<"1分钟" <<"20秒" <<"30秒" <<"1分30秒" <<"2分钟");
    ui->comboBoxTime->addItems(TimeChose);

    ui->pushButtonStart->setText("开始游戏");
    ui->pushButtonClose->setText("结束游戏");
//显示游戏界面
    ui->pushButton0->setText("0");
    ui->pushButton1->setText("1");
    ui->pushButton2->setText("2");
    ui->pushButton3->setText("3");
    ui->pushButton4->setText("4");
    ui->pushButton5->setText("5");
    ui->pushButton6->setText("6");
    ui->pushButton7->setText("7");
    ui->pushButton8->setText("8");
    ui->pushButton9->setText("9");
    ui->pushButtonBack->setText("Back");
    ui->pushButtonEnter->setText("Enter");

//显示胜利界面
    QMovie * movieScuess = new QMovie("://images/胜利.gif");
        //设置动画
    ui->labelScuess->setMovie(movieScuess);
    ui->labelScuess->setScaledContents(true);
        //启动的动画
    movieScuess->start();

//显示失败界面
    QMovie * movieFail = new QMovie("://images/失败.gif");
        //设置动画
    ui->labelFail->setMovie(movieFail);
    ui->labelFail->setScaledContents(true);
        //启动的动画
    movieFail->start();
}

GameWidget::~GameWidget()
{
    delete ui;
}

//开始界面显示
void GameWidget::ShowPageStart()
{
    ui->stackedWidget->setCurrentWidget(ui->pageStart);
    GuessTimes = 0;

    GameNumObj.clear();
    GameNumNew.clear();
    GameNumMin = "1";
    GameNumMax.clear();
    NumBit = 0;

}

//显示游戏界面
void GameWidget::ShowPageGame()
{
    ui->stackedWidget->setCurrentWidget(ui->pageGame);
    ui->progressBarCountTime->setMinimum(0);
    ui->progressBarCountTime->setValue(this->GameRunTimesTotal);
    ui->progressBarCountTime->setMaximum(this->GameRunTimesTotal);

    ui->numShow->setText(" ");
    ui->InforShow->setText(QString("请猜测数字（%1--%2）").arg(GameNumMin).arg(GameNumMax));
    ui->UseTimes->setText(QString("%1次").arg(GuessTimes));
}

//显示胜利界面
void GameWidget::ShowPageScuess()
{
    ui->stackedWidget->setCurrentWidget(ui->pageScuess);

    this->GameOverId = this->startTimer(1000); //1000m后触发定时器事件  周期性

    this->killTimer(this->GameRuntimerId);   //结束定时器
    this->GameRuntimerId = 0;
    GameRuntimerCounts = 0;

    ui->labelUseTimes->setText(QString("共用次数：%1").arg(GuessTimes));
}

//显示失败界面
void GameWidget::ShowPageFail()
{
    ui->stackedWidget->setCurrentWidget(ui->pageFail);

    this->GameOverId = this->startTimer(1000); //1000m后触发定时器事件  周期性

}

//开始按钮
void GameWidget::on_pushButtonStart_released()
{
    int TmpMax = 0;
    this->GameRuntimerId = this->startTimer(1000); //1000m后触发定时器事件  周期性

    if (ui->comboBox->currentText() == QString("简单"))
    {
        this->GameNumMax = "9";
        TmpMax = 9;
        MaxBit = 1;
    }
    else if (ui->comboBox->currentText() == QString("一般"))
    {
        this->GameNumMax = "99";
        TmpMax = 99;
        MaxBit = 2;
    }
    else if (ui->comboBox->currentText() == QString("困难"))
    {
        this->GameNumMax = "999";
        TmpMax = 999;
        MaxBit = 3;
    }
    else if (ui->comboBox->currentText() == QString("地狱"))
    {
        this->GameNumMax = "9999";
        TmpMax = 9999;
        MaxBit = 4;
    }
    else
    {
            //qDebug()<<"其他";
    }
    //随机数
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    int test = qrand()%TmpMax+1;

    this->GameNumObj = QString::number(test);

    if (ui->comboBoxTime->currentText() == QString("1分钟"))
    {
        this->GameRunTimesTotal = 60;
    }
    else if (ui->comboBoxTime->currentText() == QString("20秒"))
    {
        this->GameRunTimesTotal = 20;
    }
    else if (ui->comboBoxTime->currentText() == QString("30秒"))
    {
        this->GameRunTimesTotal = 30;
    }
    else if (ui->comboBoxTime->currentText() == QString("1分30秒"))
    {
        this->GameRunTimesTotal = 90;
    }
    else if (ui->comboBoxTime->currentText() == QString("2分钟"))
    {
        this->GameRunTimesTotal = 120;
    }
    else
    {
        //no nothing
    }

    ShowPageGame();
}

void GameWidget::on_pushButtonClose_released()
{
    //创建标准对话框信息
    int ret = QMessageBox::question(this,"close","是否关闭游戏",QMessageBox::Yes|QMessageBox::No);
    switch (ret)
    {
    case QMessageBox::Yes:
            this->close();
        break;
    case QMessageBox::No:
        break;
    default:
        break;
    }
}

//事件过滤器
bool GameWidget::eventFilter(QObject * obj, QEvent * event)
{
    return QWidget::eventFilter(obj,event);
}
//退出事件
void GameWidget::closeEvent(QCloseEvent * event)
{
    //创建标准对话框信息
    int ret = QMessageBox::question(this,"close","是否关闭游戏",QMessageBox::Yes|QMessageBox::No);
    switch (ret)
    {
    case QMessageBox::Yes:
            event->accept();
        break;
    case QMessageBox::No:
    default:
            event->ignore();
        break;
    }
}

void GameWidget::timerEvent(QTimerEvent *tm)   //定时器事件
{
    if (tm->timerId() == this->GameRuntimerId)   //判断定时器
    {
        GameRuntimerCounts++;
        qDebug()<<GameRuntimerCounts<<"run";

        ui->progressBarCountTime->setValue(this->GameRunTimesTotal - GameRuntimerCounts);
        if (GameRuntimerCounts == this->GameRunTimesTotal)
        {
            this->killTimer(this->GameRuntimerId);   //结束定时器
            this->GameRuntimerId = 0;
            ShowPageFail();
            GameRuntimerCounts = 0;
        }
    }

    if (tm->timerId() == this->GameOverId)   //判断定时器
    {
        static int j = 0;
        j++;
        qDebug()<<j <<"over";
        if (j == 5)
        {
            this->killTimer(this->GameOverId);   //结束定时器
            this->GameOverId = 0;
            ShowPageStart();
            j = 0;
        }
    }
}
//游戏运行按键处理
void GameWidget::GameRunUseButton_released()
{
    QObject *object = sender();
    QPushButton *button = static_cast<QPushButton*>(object);
    if ((button->text() >= "0") && (button->text() <= "9"))
    {
        if (!((button->text() == "0") && (NumBit == 0)) && (NumBit < MaxBit))
        {
            QString strnum = button->text();
            GameNumNew += strnum;
            NumBit++;

        }
    }
    ui->numShow->setText(GameNumNew);
    qDebug()<<NumBit;

}

void GameWidget::on_pushButtonEnter_released()
{
    if (NumBit <= MaxBit)
    {
        if ((GameNumNew >= GameNumMin) && (GameNumNew <= GameNumMax))
        {
            GuessTimes++;
            ui->UseTimes->setText(QString("%1次").arg(GuessTimes));

            if (GameNumNew > GameNumObj)
            {
                GameNumMax = GameNumNew;
                int num = GameNumNew.toInt();
                GameNumMax = QString::number(num - 1);
                //提示语句
                ui->InforShow->setText(QString("请猜测数字（%1--%2）").arg(GameNumMin).arg(GameNumMax));
            }
            else if(GameNumNew < GameNumObj)
            {
                GameNumMin = GameNumNew;
                int num = GameNumNew.toInt();
                GameNumMin = QString::number(num + 1);
                ui->InforShow->setText(QString("请猜测数字（%1--%2）").arg(GameNumMin).arg(GameNumMax));
                //提示语句
            }
            else
            {
                //结束游戏
                ShowPageScuess();
            }

            if (GameNumMin == GameNumMax)
            {
               ui->InforShow->setText(QString("答案就是（%1）").arg(GameNumMin));
            }
        }
        else
        {
            qDebug()<<"超出猜数范围";
        }
        GameNumNew.clear();
        NumBit = 0;
        ui->numShow->setText(GameNumNew);

    }
    else
    {
        qDebug()<<"位超过4";
    }


}

void GameWidget::on_pushButtonBack_clicked()
{
    if (NumBit > 0)
    {
        GameNumNew.chop(1);
        NumBit--;
        ui->numShow->setText(GameNumNew);
    }

}
