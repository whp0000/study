#include "includes.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
//主窗口控制
    move(200,200);
    setWindowTitle("王海平的窗口");

//按钮控制
    QPushButton *ButtonBegin = new QPushButton(this);
    ButtonBegin->resize(100,50);
    ButtonBegin->move(50,200);
    ButtonBegin->setText("     开始");
    //重启按钮放在开始按钮中间
    QPushButton *ButtonReBegin = new QPushButton(ButtonBegin);
    ButtonReBegin->resize(30,22);
    ButtonReBegin->move(0,0);
    ButtonReBegin->setText("重启");

    QPushButton *ButtonEnd = new QPushButton(this);
    ButtonEnd->resize(100,50);
    ButtonEnd->move(250,200);
    ButtonEnd->setText("结束");
    //点击处理
    connect(ButtonEnd,&QAbstractButton::released,
         [=](){
                    qDebug()<<"按键结束";
             });

//菜单栏
    QMenuBar *MyMenuBar = menuBar();
    //添加菜单
    QMenu *MyMenuFile = MyMenuBar->addMenu("文件");

        //添加弹出菜单项
    QAction *MyMenuFile_New = MyMenuFile->addAction("新建");
        //添加分割线
    MyMenuFile->addSeparator();
    QAction *MyMenuFile_Open = MyMenuFile->addAction("打开");
            //点击处理
    connect(MyMenuFile_New,&QAction::triggered,
             [=](){
                        qDebug()<<"新建文件";
                 });
            //打开文件对话框
    connect(MyMenuFile_Open,&QAction::triggered,
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
       //添加模态对话框
    QAction *MyMo = MyMenuFile->addAction("模态对话框");
    connect(MyMo,&QAction::triggered,
             [=](){
                        QDialog dlg;  //对话框
                        dlg.resize(200,150);
                        dlg.setWindowTitle("模态对话框");
                        dlg.exec();   //等待用户操作结束
                        qDebug()<<"模态对话框";
                 });
    //添加非模态对话框
 QAction *MyNoMo = MyMenuFile->addAction("非模态对话框");
 connect(MyNoMo,&QAction::triggered,
          [=](){
                     //不希望NoDlg出去此函数后内存销毁，会导致对话框不显示
                     //（方法1）
//                     QDialog *NoDlg = new QDialog(this);  //对话框
//                     NoDlg->resize(200,150);
//                     NoDlg->setWindowTitle("非模态对话框");
//                     NoDlg->show();
                     //（方法2） 内存优化  限定NoDlg生存期
                     QDialog *NoDlg = new QDialog;
                     NoDlg->resize(200,150);
                     NoDlg->setAttribute(Qt::WA_DeleteOnClose);  //对话框窗口关闭就释放NoDlg
                     NoDlg->show();
                     qDebug()<<"非模态对话框";
              });
//工具栏  菜单项的快捷方式
    QToolBar *MyToolBar = addToolBar("ToolBat");
    //添加快捷方式
    MyToolBar->addAction(MyMenuFile_New);
    //添加按钮控件
    QPushButton *BoolButton_Run = new QPushButton(this);
    BoolButton_Run->setText("run");
    //点击处理
    connect(BoolButton_Run,&QAbstractButton::released,
         [=](){
                    qDebug()<<"run";
             });
    MyToolBar->addWidget(BoolButton_Run);
    MyToolBar->addWidget(ButtonBegin);
    MyToolBar->addWidget(ButtonEnd);
    //标准对话框（帮助信息）
    QAction *MyHelp = MyToolBar->addAction("帮助");
    connect(MyHelp,&QAction::triggered,
         [=](){
                    //创建标准对话框信息
                    QMessageBox::about(this,"help","王海平的软件");
              });
    //问题对话框
    QAction *MyQuestion = MyToolBar->addAction("调查");
    connect(MyQuestion,&QAction::triggered,
         [=](){
                        //创建标准对话框信息
                        int ret = QMessageBox::question(this,"Question","你满意吗",QMessageBox::Yes|QMessageBox::No|QMessageBox::Close);
                        switch (ret)
                        {
                        case QMessageBox::Yes:
                                    qDebug()<<"满意";
                            break;
                        case QMessageBox::No:
                                    qDebug()<<"不满意";
                            break;
                        default:
                                    qDebug()<<"不知道";
                            break;
                    }
              });
//状态栏
    QStatusBar *MyStatusBar = statusBar();
    //添加标签到状态栏 从左往右
    QLabel *MyStatus_lable = new QLabel(this);
    MyStatus_lable->setText("当前文件");
    MyStatusBar->addWidget(MyStatus_lable);
    //添加标签到状态栏 从右往左
    MyStatusBar->addPermanentWidget(new QLabel("编码格式",this));
//核心控件  (文本编辑区域)
    QTextEdit *MyTextEdit = new QTextEdit(this);
    setCentralWidget(MyTextEdit);
//浮动窗口
    QDockWidget *MyDockWidget = new QDockWidget(this);
    addDockWidget(Qt::RightDockWidgetArea,MyDockWidget);
    QTextEdit *MyTextEdit_Dock = new QTextEdit(this);
    //浮动窗口添加控件
    MyDockWidget->setWidget(MyTextEdit_Dock);


//右键菜单
    //创建菜单、菜单项
    pop_menu = new QMenu();
    add_images_action = new QAction(this);

    add_folder_action = new QAction(this);

    remove_selected_action = new QAction(this);

    remove_all_action = new QAction(this);

    add_images_action->setText("add_images_action");
    add_folder_action->setText("add_folder_action");
    remove_selected_action->setText("remove_selected_action");
    remove_all_action->setText("remove_all_action");
    //连接信号与槽

    connect(add_images_action, &QAction::triggered, this, &MainWindow::selectImages);

    connect(add_folder_action, &QAction::triggered, this, &MainWindow::selectFolder);

    connect(remove_selected_action, &QAction::triggered, this, &MainWindow::removeSelectedImages);

    connect(remove_all_action, &QAction::triggered, this, &MainWindow::removeAllImages);

}

MainWindow::~MainWindow()
{
}

void MainWindow::mousePressEvent(QMouseEvent * event) //按下鼠标
{

}
void MainWindow::contextMenuEvent(QContextMenuEvent *event)//右键菜单
{
    pop_menu->clear();
    pop_menu->addAction(add_images_action);
    pop_menu->addAction(add_folder_action);
    pop_menu->addAction(remove_selected_action);
    pop_menu->addAction(remove_all_action);
    //菜单出现的位置为当前鼠标的位置

    pop_menu->exec(QCursor::pos());
    event->accept();
}
void MainWindow::selectImages()
{
    qDebug()<<"selectImages";
}
void MainWindow::selectFolder()
{
    qDebug()<<"selectFolder";
}
void MainWindow::removeSelectedImages()
{
    qDebug()<<"removeSelectedImages";
}
void MainWindow::removeAllImages()
{
    qDebug()<<"removeAllImages";
}
