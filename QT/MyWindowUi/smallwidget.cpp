#include "includes.h"

#include <QSpinBox>  //数字调节块
#include <QSlider>   //滑块
#include <QHBoxLayout>  //布局
//自定义控件
smallWidget::smallWidget(QWidget *parent) : QWidget(parent)   //通过提升UI中widget控件为smallWidget,smallWidget控件属于UI中，继而随主窗口初始化
{
    QSpinBox *spin = new QSpinBox(this);
    QSlider *slider = new QSlider(Qt::Horizontal,this);
    //把控件添加到布局中
    QHBoxLayout *hlayout = new QHBoxLayout(this);
    hlayout->addWidget(spin);
    hlayout->addWidget(slider);

    connect(spin, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), slider, &QSlider::setValue); //函数指针转换 --指定用int类型
    connect(slider,	&QSlider::valueChanged, spin, &QSpinBox::setValue); //函数指针转换 --指定用int类型


}

