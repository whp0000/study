#ifndef SERVERWIDGET_H
#define SERVERWIDGET_H

#include <QWidget>
#include <QWebSocketServer>
#include <QWebSocket>
namespace Ui {
class ServerWidget;
}

class ServerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ServerWidget(QWidget *parent = 0);
    ~ServerWidget();
    QWebSocketServer *ser;
    QWebSocket *soc;


private slots:
    void on_buttonSend_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ServerWidget *ui;
};

#endif // SERVERWIDGET_H
