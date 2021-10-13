#ifndef CLIENTWIDGET_H
#define CLIENTWIDGET_H

#include <QWidget>
#include <QWebSocket>


namespace Ui {
class clientwidget;
}

class clientwidget : public QWidget
{
    Q_OBJECT

public:
    explicit clientwidget(QWidget *parent = 0);
    ~clientwidget();

    QWebSocket *soc;

private slots:
    void on_pushButtonConnect_clicked();

    void on_buttonSend_clicked();

    void on_buttonClose_clicked();

    void on_pushButtonConnect_2_released();

private:
    Ui::clientwidget *ui;
    quint8 ConnectFlag;
};

#endif // CLIENTWIDGET_H
