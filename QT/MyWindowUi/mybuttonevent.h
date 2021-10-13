#ifndef MYBUTTONEVENT_H
#define MYBUTTONEVENT_H

#include <QWidget>
#include <QPushButton>
class MyButtonEvent : public QPushButton
{
    Q_OBJECT
public:
    explicit MyButtonEvent(QWidget *parent = 0);

signals:

protected:
        void mousePressEvent(QMouseEvent * event); //按下鼠标
public slots:
};

#endif // MYBUTTONEVENT_H
