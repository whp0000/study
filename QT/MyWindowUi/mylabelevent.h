#ifndef MYLABELEVENT_H
#define MYLABELEVENT_H

#include <QLabel>

class MyLabelEvent : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabelEvent (QWidget *parent = 0);

protected:
    void mouseMoveEvent(QMouseEvent * event);  //区域内移动鼠标
    void mousePressEvent(QMouseEvent * event); //按下鼠标
    void mouseReleaseEvent(QMouseEvent * event);//松开鼠标
    void enterEvent(QEvent * event);           //进入控件区域
    void leaveEvent(QEvent * event);          //离开控件区域

    bool event(QEvent * event);          //离开控件区域

signals:

public slots:
};

#endif // MYLABELEVENT_H
