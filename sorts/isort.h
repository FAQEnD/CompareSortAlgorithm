#ifndef ISORT_H
#define ISORT_H
#include <vector>
#include "timemanager.h"
#include <QString>
#include <QFile>
#include <QTextStream>

template <class T>
class ISort
{
public:
    virtual void sort() = 0;
    double getAlgorithmTime()
    {
        return _tManager.getAlgTime();
    }
    virtual void readArrayFromFile()
    {
//        qDebug() << "Start read file";
        _arr.reserve(_MAX_VECTOR_SIZE);//need +1, coz read +1 bite ... fck
        QFile hFile("arr.dat");
        if (!hFile.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            qDebug() << "Error in opening file arr.dat";
            return;
        }/*else
            qDebug() << "File opened well";*/
        QTextStream in(&hFile);
        while(!in.atEnd())
        {
            T i ;
            in >> i;
            _arr.push_back(i);
        }
//        qDebug() << "All working good, array readed";
        _arr.pop_back();
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
            qDebug() << "Array of " << type <<  "sorted by ALGORITHM: " << _sortAlgorithmName;
        else
            qDebug() << "array of " << type <<  "not sorted by ALGORITHM: " << _sortAlgorithmName;
    }
    ~ISort()
    {
        _arr.clear();
    }

protected:
    const unsigned int _MAX_VECTOR_SIZE = 100000001;
    std::vector<T> _arr;
    TimeManager _tManager;
    QString _sortAlgorithmName;
};

#endif // ISORT_H
