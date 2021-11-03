#ifndef CASSISTANT_H
#define CASSISTANT_H

#include <QTime>

struct sTime{
  int hour;
  int minute;
  int second;
};

sTime getCurrentTime();
sTime TimeAddMinute(sTime startTime, const int addMinute);


#endif // CASSISTANT_H
