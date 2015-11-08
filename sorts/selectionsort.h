#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H
#include <vector>
#include <QString>
#include <QtDebug>
#include "isort.h"

template <class T>
class SelectionSort : public ISort<T>
{
public:
    SelectionSort();
    static double algTimeSum;
    double getAlgTimeSum()
    {
        double tempSum = this->algTimeSum;
        this->algTimeSum = 0;
        return tempSum;
    }

    void sort()
    {
        this->_tManager.start();
        for (unsigned int i = 0; i < this->_arr.size(); ++i) {
            T min = 9999999;
            int positionMin = 0;
            for (unsigned int j = i; j < this->_arr.size(); ++j)
                if (min >= this->_arr[j]) { min = this->_arr[j]; positionMin = j; }
            std::swap(this->_arr[i], this->_arr[positionMin]);
        }
        this->_tManager.stop();
        this->isSorted();
        this->algTimeSum += this->getAlgorithmTime();
    }
};
// END OF CLASS
template <class T>
double SelectionSort<T>::algTimeSum;

template <class T>
SelectionSort<T>::SelectionSort()
{
    this->readArrayFromFile();
    this->_sortAlgorithmName = "Selection";
}

#endif // SELECTIONSORT_H
