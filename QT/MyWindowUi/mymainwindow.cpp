#include "includes.h"

MyMainWindow::MyMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyMainWindow)
{
    ui->setupUi(this);
    //打开文件对话框
    connect(ui->action_open,&QAction::triggered,
             [=](){
                        QString Path = QFileDialog::getOpenFileName(this, tr("打开文件"),
                                                                        "../", //打开路径
                                                                        tr("Images (*.png *.xpm *.jpg);;"
                                                                           "Text files (*.txt);;"
                                                                           "XML files (*.xml);;"
                                                                           "soure(*.cpp *.c *.h);;"
                                                                           "all(*.*)" ));
                        qDebug()<< Path;
                 });
    //读取lineEdit控件内容
    QString text = ui->lineEdit->text();
    char* ss = text.toUtf8().data();
    qDebug()<<ss;
    //写lineEdit控件内容
    ui->lineEdit->setText("王海平");
    //设置lineEdit显示间隙
    ui->lineEdit->setTextMargins(20,0,0,0);
    //设置lineEdit显示方式
    ui->lineEdit->setEchoMode(QLineEdit::Normal);

    //提示输入
    QStringList list;
    list << "hello" << "Hi" << "Good bye";
    QCompleter *com = new QCompleter(list,this);  //提示框模型
    com->setCaseSensitivity(Qt::CaseInsensitive); //不区分大小写

    ui->lineEdit->setCompleter(com);

    //Lable 显示文本
    ui->labelText->setText("wanghaiping");
    //Lable 显示图片
    ui->labelImage->setPixmap(QPixmap("1.ppm"));
        //让图片自动适应Lable大小
    ui->labelImage->setScaledContents(true);

    //Lable 显示GIF
    QMovie * movie = new QMovie("://images/兴高采烈.gif");
        //设置动画
    ui->labelGif->setMovie(movie);
    ui->labelGif->setScaledContents(true);
        //启动的动画
    movie->start();

    //Lable 设置网页链接
    ui->labelUrl ->setText("<h1><a href=\"https://www.baidu.com\">百度一下</a></h1>");
    ui->labelUrl ->setOpenExternalLinks(true);

    //数码管显示
    ui->lcdNumber->display("12F");

    //进度条
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(100);
    ui->progressBar->setValue(50);

    //网页窗口   需添加模块
    ui->webView->load(QUrl("https://www.baidu.com"));

    //主题设置
    ui->lineEditMyStyle->setStyleSheet("QLineEdit{color:red;"
                                       "selection-color:rgb(100,200,200);"
                                       "selection-background-color:blue;"
                                       "background-image: url(://images/细菌病毒.png);}"); //前景色设置 背景色background-color  选中前景色 选中背景色 图片
        ui->lineEditMyStyle->setText("AAAAAAA");
         //自动伸缩图片
        ui->textEditMyStyle->setStyleSheet("QTextEdit{border-image: url(://images/细菌病毒(大图).png) 20 20 20 20 streth streth;}"); //向内裁剪

        //伪状态  -控制 改变 样式
        ui->pushButtonMyStyle->setStyleSheet("QPushButton{border-image: url(://images/万圣节文字.png);}"
                                             "QPushButton:hover{border-image: url(://images/地球环保.png);}"
                                             "QPushButton:pressed{border-image: url(://images/地球绿色.png);}"
                                             );  //默认  鼠标在上时  点击时
    //事件
        //自定义控件 lobal
            //安装事件过滤器
                ui->labelEv->installEventFilter(this); //参数为 过滤器所在的控件

        //定时器事件
            //开启定时器
            this->timerId = this->startTimer(1000); //1000m后触发定时器事件  周期性

        //事件忽略测试
        connect(ui->pushButtonEvent,QPushButton::pressed,
                [=](){
           qDebug()<<"接收到按键按下信号" ;
        });
}

MyMainWindow::~MyMainWindow()
{
    delete ui;
}

void MyMainWindow::on_pushButton_4_clicked()
{
    static qint8 i = 0;
    i = ++i%4;
    ui->stackedWidget->setCurrentIndex(i);
}

void MyMainWindow::keyPressEvent(QKeyEvent *ev)
{
    int retKey;
    QString str;
    if (ev->modifiers() == Qt::ControlModifier)
    {
       str = "ctrl+";
    }

    retKey = ev->key();
    str += QString("%1").arg((char)retKey);

    ui->labelEv->setText(str);
}

void MyMainWindow::timerEvent(QTimerEvent *tm)   //计时器事件
{
    if (tm->timerId() == this->timerId)   //判断定时器
    {
        static int i = 0;
        i++;
        ui->labelEv->setText(QString("%1").arg(i));
        if (i == 10)
        {
            this->killTimer(this->timerId);   //结束定时器
            i = 0;
        }
    }
}
void MyMainWindow::closeEvent(QCloseEvent * event)   //窗口关闭事件
{
//事件忽略测试 传递给父组件

    //创建标准对话框信息
    int ret = QMessageBox::question(this,"close","是否关闭软件",QMessageBox::Yes|QMessageBox::No);
    switch (ret)
    {
    case QMessageBox::Yes:
         event->accept();   //当前控件接收信号
        break;
    case QMessageBox::No:
         event->ignore();    //当前控件不接收信号，传递给父组件
        break;
    default:
                qDebug()<<"不知道";
        break;
    }

}

//事件过滤器  所有控件的事件都可以在此函数内完成
bool MyMainWindow::eventFilter(QObject * watched, QEvent * event)
{
    if (watched == ui->labelEv)  //管理labelEv控件的事件
    {
        if (event->type() == QEvent::MouseButtonPress) //鼠标按下事件
        {
            QMouseEvent *ev = static_cast<QMouseEvent *>(event);
            if (ev->button() == Qt::MiddleButton)
            {
               qDebug()<<"事件过滤器执行：中键按下";

               //表示该事件已被处理  子控件内自己的事件处理不能被执行
               return true;

               //使用下面 子控件内自己的事件处理可以被执行
               //return QWidget::eventFilter(watched,event); //不做处理  传递给父类
            }
            else
            {
               return QWidget::eventFilter(watched,event); //不做处理  传递给父类
            }
        }
        else
        {
           return QWidget::eventFilter(watched,event); //不做处理  传递给父类
        }
    }
    else
    {
        return QWidget::eventFilter(watched,event); //不做处理  传递给父类
    }
}
