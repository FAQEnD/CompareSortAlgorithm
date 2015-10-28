#ifndef BUBBLESORT_H
#define BUBBLESORT_H
#include "isort.h"

template <class T>
class BubbleSort : public ISort<T>
{
public:
    BubbleSort(std::vector<T>);

    void sort()
    {
        this->_tManager.start();

        for (unsigned int i = 0; i < this->_arr.size()-1; ++i)
            for (unsigned int j = 0; j < this->_arr.size() -1 - i; ++j)
                if (this->_arr[j] > this->_arr[j + 1])
                    std::swap(this->_arr[j + 1], this->_arr[j]);
        this->_tManager.stop();
        this->isSorted();
    }
};

#endif // BUBBLESORT_H

template <class T>
BubbleSort<T>::BubbleSort(std::vector<T> arr)
{
    this->_arr = arr;
}
