#include "includes.h"

MyLabelEvent::MyLabelEvent(QWidget *parent) : QLabel(parent)
{
    this->setMouseTracking(true);   //启用鼠标跟踪  不必按下鼠标再触发事件
}

void MyLabelEvent::mouseMoveEvent(QMouseEvent *ev)
{
    int x,y;

    x = ev->x();
    y = ev->y();
    QString str = QString("mouse loction: %1 , %2").arg(x).arg(y);
    //qDebug()<<x<<y;
    this->setText(str);

    QLabel::mouseMoveEvent(ev);   //事件继续向下传递   否则无法执行鼠标按下信号触发的槽函数
}

void MyLabelEvent::mousePressEvent(QMouseEvent *ev)
{
    if (ev->button() == Qt::LeftButton)
    {
        qDebug()<<"左键按下";
        this->setPixmap(QPixmap("://images/dog.jpg"));
            //让图片自动适应Lable大小
        this->setScaledContents(true);
    }
    else if (ev->button() == Qt::RightButton)
    {
        qDebug()<<"右键按下";
    }
    else if (ev->button() == Qt::MidButton)
    {
        qDebug()<<"中键按下";
    }

    QLabel::mousePressEvent(ev);   //事件继续向下传递   否则无法执行鼠标按下信号触发的槽函数
}

void MyLabelEvent::mouseReleaseEvent(QMouseEvent *ev)
{
    if (ev->button() == Qt::LeftButton)
    {
        qDebug()<<"左键抬起";

    }
    else if (ev->button() == Qt::RightButton)
    {
        qDebug()<<"右键抬起";
    }
    else if (ev->button() == Qt::MidButton)
    {
        qDebug()<<"中键抬起";
    }

    QLabel::mouseReleaseEvent(ev);   //事件继续向下传递   否则无法执行鼠标按下信号触发的槽函数
}

void MyLabelEvent::enterEvent(QEvent * event)
{
    qDebug()<<"进入";

    QLabel::enterEvent(event);   //事件继续向下传递   否则无法执行鼠标按下信号触发的槽函数
}
void MyLabelEvent::leaveEvent(QEvent * event)
{
    qDebug()<<"离开";

    QLabel::leaveEvent(event);   //事件继续向下传递   否则无法执行鼠标按下信号触发的槽函数
}

//事件分发
bool MyLabelEvent::event(QEvent * event)
{
    if (event->type() == QEvent::MouseButtonRelease) //禁止右键按键抬起事件
    {
        QMouseEvent *ev = static_cast<QMouseEvent *>(event);
        if (ev->button() == Qt::RightButton)
        {
            return true;  //返回true  会告诉上级 事件处理完毕  达到忽略的效果
        }
        else
        {
             return QWidget::event(event);
        }
    }
    else
    {
       return QWidget::event(event);
    }
}
