#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include "threadhandle.h"

namespace Ui {
class myWidget;
}

class myWidget : public QWidget
{
    Q_OBJECT

public:
    explicit myWidget(QWidget *parent = 0);
    ~myWidget();

public:
    void showDebug(QString str);

private slots:
    void on_pushButtonBegin_clicked();

    void on_pushButtonEnd_clicked();

    void on_pushButtonPulse_clicked();

    void on_pushButtonContinue_clicked();

private:
    Ui::myWidget *ui;
    threadHandle *thread1;
};

#endif // MYWIDGET_H
