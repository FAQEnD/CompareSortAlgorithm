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
    SelectionSort(std::vector<T> arr);
private:
//    std::vector<T> _arr;
    void isSorted();
public:
    void sort()
    {
        for (unsigned int i = 0; i < this->_arr.size(); ++i) {
            T min = 9999999;
            int positionMin = 0;
            for (unsigned int j = i; j < this->_arr.size(); ++j)
                if (min >= this->_arr[j]) { min = this->_arr[j]; positionMin = j; }
            std::swap(this->_arr[i], this->_arr[positionMin]);
        }
        isSorted();
    }
};
// END OF CLASS


template <class T>
SelectionSort<T>::SelectionSort(std::vector<T> arr)
{
    this->_arr = arr;
}

template <class T> void SelectionSort<T>::isSorted()
{
    QString type;
    int sizeOfElement = sizeof(this->_arr[0]);
    if(sizeOfElement == 4)
        type = "int";
    else
        type = "double";
    if(std::is_sorted(this->_arr.begin(), this->_arr.end()))
        qDebug() << "Array of " << type <<  "sorted by selection sort";
    else
        qDebug() << "array of " << type <<  "not sorted by selection sort";
}

#endif // SELECTIONSORT_H
