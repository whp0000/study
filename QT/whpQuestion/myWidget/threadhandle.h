#ifndef THREADHANDLE_H
#define THREADHANDLE_H

#include <QThread>
#include <QString>


class threadHandle : public QThread
{
    Q_OBJECT
public:
    explicit threadHandle(QWidget *parent = 0);

    void ThdBegin();
    void ThdEnd();
    void ThdPulse();
    void ThdContinue();

    void SetShowStr(QString str);
protected:
    void run();
signals:
    void showDebugSignal(QString str);

public slots:

private:
    bool RunFlag;
    bool PluseFlag;
    QString ShowStr;
};

#endif // THREADHANDLE_H
