#ifndef TIMEMANAGER_H
#define TIMEMANAGER_H
#include <windows.h>

class TimeManager
{
public:
    void start();
    void stop();
    void getTime();
    double getAlgTime() const;

private:
    LARGE_INTEGER _start;
    LARGE_INTEGER _end;
    LARGE_INTEGER _f;
    double _algTime;
};

void TimeManager::start()
{
    QueryPerformanceCounter(&_start);
}

void TimeManager::stop()
{
    QueryPerformanceCounter(&_end);
    getTime();
}

void TimeManager::getTime()
{
    QueryPerformanceFrequency(&_f);
    _algTime = double(_end.QuadPart - _start.QuadPart) / _f.QuadPart;
}

double TimeManager::getAlgTime() const
{
    return _algTime;
}
#endif // TIMEMANAGER_H
