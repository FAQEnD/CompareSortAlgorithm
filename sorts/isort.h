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
    virtual void isSorted()
    {
        QString type;
        int sizeOfElement = sizeof(_arr[0]);
        if(sizeOfElement == 4)
            type = "int";
        else
            type = "double";
        if(std::is_sorted(_arr.begin(), _arr.end()))
            qDebug() << "Array of " << type <<  "sorted";
        else
            qDebug() << "array of " << type <<  "not sorted";
    }
protected:
    std::vector<T> _arr;
    TimeManager _tManager;
};

#endif // ISORT_H
