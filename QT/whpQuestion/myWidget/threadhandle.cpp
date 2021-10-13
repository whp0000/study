#include "includes.h"

threadHandle::threadHandle(QWidget *parent) : QThread(parent)
{
     RunFlag = true;
     PluseFlag = false;
     ShowStr = QString("");
}

void threadHandle::run()
{
    static qint16 i = 0;
    if ( i != 0)
    {
        i += 10;
    }
    while (RunFlag)
    {

      if (PluseFlag)
      {
           continue;
      }
      emit showDebugSignal(QString("%1:%2\n").arg(ShowStr).arg(i));
      msleep(500);
      i++;
    }
}

void threadHandle::ThdBegin()
{
    RunFlag = true;
}
void threadHandle::ThdEnd()
{
    RunFlag = false;
}
void threadHandle::ThdPulse()
{
    PluseFlag = true;
}
void threadHandle::ThdContinue()
{
    PluseFlag = false;
}

void threadHandle::SetShowStr(QString str)
{
    ShowStr = str;
}
