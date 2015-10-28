#ifndef MERGESORT_H
#define MERGESORT_H
#include "isort.h"

template <class T>
class MergeSort : public ISort<T>
{
public:
    MergeSort();
    void merge();
};

#endif // MERGESORT_H
