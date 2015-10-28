#ifndef QUICKSORT_H
#define QUICKSORT_H
#include "isort.h"

template <class T>
class QuickSort : public ISort<T>
{
public:
    QuickSort(std::vector<T>);
    void quickSort(std::vector<T>&, unsigned int, unsigned int);

    void sort()
    {
        this->_tManager.start();
        quickSort(this->_arr, 0, this->_arr.size()-1);
        this->_tManager.stop();
        this->isSorted();
    }
};

#endif // QUICKSORT_H

template <class T>
QuickSort<T>::QuickSort(std::vector<T> arr)
{
    this->_arr = arr;
}

template <class T>
void QuickSort<T>::quickSort(std::vector<T> &arr, unsigned int left, unsigned int right)
{
    int l = left, r = right;
    int piv = arr[(left+right)/2];
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
