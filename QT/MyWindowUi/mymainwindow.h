#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QTimerEvent>

namespace Ui {
class MyMainWindow;
}

class MyMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MyMainWindow(QWidget *parent = 0);
    ~MyMainWindow();

private slots:
    void on_pushButton_4_clicked();

protected:
    void keyPressEvent(QKeyEvent * ev);    //按下键盘
    void timerEvent(QTimerEvent *tm);   //定时器事件
    void closeEvent(QCloseEvent * event);   //窗口关闭事件
    //事件过滤器  控件需要按照过滤器
    bool eventFilter(QObject * watched, QEvent * event);
private:
    Ui::MyMainWindow *ui;
    int timerId;
};

#endif // MYMAINWINDOW_H
