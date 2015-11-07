#ifndef QUICKSORT_H
#define QUICKSORT_H
#include "isort.h"

template <class T>
class QuickSort : public ISort<T>
{
public:
    QuickSort();
    void quickSort(std::vector<T>&, size_t, size_t);

    void sort()
    {
        this->_tManager.start();
        qDebug() << "Start sort, array size: " << this->_arr.size();
        quickSort(this->_arr, 0, this->_arr.size()-1);
        this->_tManager.stop();
        this->isSorted();
    }
};

#endif // QUICKSORT_H

template <class T>
QuickSort<T>::QuickSort()
{
    this->readArrayFromFile();
    qDebug() << "Array readed";
    this->_sortAlgorithmName = "Quick";
}

template <class T>
void QuickSort<T>::quickSort(std::vector<T> &arr, size_t left, size_t right)
{
//    qDebug() << "left: " << left << " right: " << right;
    size_t l = left, r = right;
    double piv = (arr[left] + arr[(left+right)/2] + arr[right])/3;
    while(l <= r)
    {
        while(arr[l] < piv)
            l++;
        while(arr[r] > piv)
            r--;
        if(l <= r)
            std::swap(arr[l++], arr[r--]);
    }
    if(left < r)
        quickSort(arr, left, r);
    if(right > l)
        quickSort(arr, l, right);
}
