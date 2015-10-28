#ifndef MERGESORT_H
#define MERGESORT_H
#include "isort.h"
#include <algorithm>

template <class T>
class MergeSort : public ISort<T>
{
public:
    MergeSort(std::vector<T>);
    void isSorted();
    void merge(std::vector<T>&, const int, const int, const int);

    void sort()
    {
        unsigned int size = this->_arr.size();
        if (this->_arr.size() <= 20)
            {
                std::sort(this->_arr.begin(), this->_arr.end());
                return;
            }
            for (unsigned int i = 1; i < size; i *= 2)
                for (unsigned int j = 0; j < size - i; j += 2 * i)
                    merge(this->_arr, j, j + i, std::min(j + 2 * i, size));
        isSorted();
    }
};

template <class T>
MergeSort<T>::MergeSort(std::vector<T> arr)
{
    this->_arr = arr;
}

template <class T>
void MergeSort<T>::merge(std::vector<T> &arr, const int left, const int middle, const int right)
{
    int indexA(0), indexB(0);
    std::vector<T> result;
    result.resize(right - left);

    while (left + indexA < middle && middle + indexB < right)
    {
        if (arr[left + indexA] < arr[middle + indexB])
        {
            result[indexA + indexB] = arr[left + indexA];
            ++indexA;
        }
        else
        {
            result[indexA + indexB] = arr[middle + indexB];
            ++indexB;
        }
    }

    while (left + indexA < middle)
    {
        result[indexA + indexB] = arr[left + indexA];
        ++indexA;
    }

    while (middle + indexB < right)
    {
        result[indexA + indexB] = arr[middle + indexB];
        ++indexB;
    }

    for (int i = 0; i < indexA + indexB; ++i)
    {
        arr[left + i] = result[i];
    }
}

template <class T>
void MergeSort<T>::isSorted()
{
    QString type;
    int sizeOfElement = sizeof(this->_arr[0]);
    if(sizeOfElement == 4)
        type = "int";
    else
        type = "double";
    if(std::is_sorted(this->_arr.begin(), this->_arr.end()))
        qDebug() << "Array of " << type <<  "sorted by merge sort";
    else
        qDebug() << "array of " << type <<  "not sorted by merge sort";
}

#endif // MERGESORT_H
