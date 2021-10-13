#include "includes.h"

MyMainWindow::MyMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyMainWindow)
{
    ui->setupUi(this);
    this->x = -200;

    //绘图设备pixmap
    QPixmap pixmap(400,400);
        //创建画家
        QPainter painter(&pixmap);
        //更改背景颜色 白色
        //painter.fillRect(pixmap.rect(),Qt::white);
        pixmap.fill(Qt::white);
        //绘图
        painter.drawPixmap(0,0,200,200,QPixmap("://images/万圣节文字.jpg"));
        //保存绘图设备
        pixmap.save("../pixmap.jpg");


    //绘图设备pixmap
    QImage image(400,400,QImage::Format_ARGB32); //背景为透明
        //创建画家
        QPainter painterImage(&image);
        //绘图
        painterImage.drawImage(0,0,QImage("://images/细菌病毒.png"));

        //像素点操作
        for (int i = 0; i < 50; i++)
        {
            for (int j = 0; j < 50; j++)
            {
                 image.setPixel(QPoint(i,j),qRgb(0,255,0));
            }
        }

        //保存绘图设备
        image.save("../image.png");


    //保存类型的设备  可存为2进制文件 不可被查看
    QPicture picture;
            //创建画家
            QPainter painterPic;
            painterPic.begin(&picture);   //必须使用该方式
            //绘图
            painterPic.drawPixmap(0,0,200,200,QPixmap("://images/细菌病毒.png"));

            painterPic.end();
            //保存绘图设备
    //** 必须end（）结束后在保存 才能成功
            picture.save("../picture.jpg");


}

MyMainWindow::~MyMainWindow()
{
    delete ui;
}

void MyMainWindow::paintEvent(QPaintEvent *PaintEvent)
{
    //创建画家
    QPainter p(this);         //QPainter p(this) 用法等同于==  p.begin(this) + p.end;
        //指定当前窗口为绘图设备
        //p.begin(this);  //p.end();

        //画背景图
        //p.drawPixmap(0,0,width(),height(),QPixmap("://images/dog.jpg"));
        p.drawPixmap(rect(),QPixmap("://images/dog.jpg"));

    //创建画笔
    QPen pen;
    pen.setWidth(5);
    pen.setColor(QColor(60,60,60));
    pen.setStyle(Qt::SolidLine);  //直线
        //把画笔给画家
        p.setPen(pen);


        //画直线
        p.drawLine(50,50,150,50);
        p.drawLine(50,50,50,150);

        //画矩形
        p.drawRect(200,200,200,200);

   //创建画刷
   QBrush brush;
   brush.setColor(QColor(120,120,60));
   brush.setStyle(Qt::Dense1Pattern);  //麻点
   p.setBrush(brush);
        //画圆形
        p.drawEllipse(QPoint(300, 300),100,100);

   //局部画图
   p.drawPixmap(this->x,400,200,100,QPixmap("://images/细菌病毒.png"));  //有彩色
   p.drawPixmap(this->x,500,200,100,QBitmap("://images/细菌病毒.png"));  //无彩色  透明背景会变黑  白色背景会变透明


   //测试QPicture保存的图片能否重新显示
   QPicture pic;
   pic.load("../picture.jpg");
   p.drawPicture(0,0,pic);
}

void MyMainWindow::on_pushButton_4_released()
{
    this->x += 20;
    if (this->x >= width())
    {
        this->x = -200;
    }
    update();   //重新刷图  重新运行paintEvent 可添加参数进行局部刷图
}
