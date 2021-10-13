#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QWidgetAction>

namespace Ui {
class GameWidget;
}

class GameWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GameWidget(QWidget *parent = 0);
    ~GameWidget();

    void ShowPageStart();
    void ShowPageGame();
    void ShowPageScuess();
    void ShowPageFail();

protected:
    void closeEvent(QCloseEvent * event);
    bool eventFilter(QObject * obj, QEvent * event);
    void timerEvent(QTimerEvent *tm);   //定时器事件

private slots:
    void on_pushButtonStart_released();

    void on_pushButtonClose_released();
    void GameRunUseButton_released();

    void on_pushButtonEnter_released();

    void on_pushButtonBack_clicked();

private:
    Ui::GameWidget *ui;
    int GameRuntimerId;
    int GameRuntimerCounts = 0;

    int GameRunTimesTotal;
    int GameOverId;

    QString GameNumObj;
    QString GameNumNew;
    QString GameNumMin = "1";
    QString GameNumMax;
    int NumBit = 0;
    int MaxBit = 0;

    int GuessTimes = 0;
};

#endif // GAMEWIDGET_H
