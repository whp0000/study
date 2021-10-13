#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MyMainWindow;
}

class MyMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MyMainWindow(QWidget *parent = 0);
    ~MyMainWindow();

protected:
    //重写绘图事件
    //如果在窗口绘图，必须放在绘图事件里实现
    //绘图事件内部自动调用，窗口需要重绘的时候（状态改变）
    void paintEvent(QPaintEvent *);

private slots:
    void on_pushButton_4_released();

private:
    Ui::MyMainWindow *ui;
    int x;
};

#endif // MYMAINWINDOW_H
