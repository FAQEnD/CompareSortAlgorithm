#ifndef ISORT_H
#define ISORT_H
#include <vector>
#include "timemanager.h"

template <class T>
class ISort
{
public:
    virtual void sort() = 0;
    double getAlgorithmTime()
    {
        return _tManager.getAlgTime();
    }
protected:
    std::vector<T> _arr;
    TimeManager _tManager;
};

#endif // ISORT_H
