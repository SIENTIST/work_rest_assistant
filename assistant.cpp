#include "assistant.h"

sTime getCurrentTime()
{
    QTime curTime = QTime::currentTime(); //获取当前时间

    sTime outputTime;

    outputTime.hour   = curTime.hour();
    outputTime.minute = curTime.minute();
    outputTime.second = curTime.second();

    return outputTime;
}

sTime calcEndTime(const sTime startTime, const int addMinute)
{
    int addHour = (addMinute + startTime.minute) / 60;

    sTime endTme;
    endTme.minute = (addMinute + startTime.minute) % 60;
    endTme.hour = (startTime.hour + addHour) % 24;

    return endTme;
}

