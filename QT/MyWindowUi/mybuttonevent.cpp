#include "includes.h"

MyButtonEvent::MyButtonEvent(QWidget *parent) : QPushButton(parent)
{

}

void MyButtonEvent::mousePressEvent(QMouseEvent * event) //按下鼠标  事件忽略测试
{
        qDebug()<<"按键被按下";
        QPushButton::mousePressEvent(event);  //按键按下 可以触发信号和槽
}
