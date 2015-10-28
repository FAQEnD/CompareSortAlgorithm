#ifndef COUNTINGSORT_H
#define COUNTINGSORT_H
#include "isort.h"

template <class T>
class CountingSort : public ISort<T>
{
public:
    CountingSort(std::vector<T> arr);
    T findMax();

    void sort()
    {
        this->_tManager.start();
        std::vector<int> counter(findMax() + 1, 0);
            for (auto arrEl : this->_arr)
                counter[arrEl]++;
            this->_arr.clear();
            for (unsigned int i = 0; i < counter.size(); i++)
                for (int j = 0; j < counter[i]; j++)
                    this->_arr.push_back(i);
        this->_tManager.stop();
        this->isSorted();
    }

};

#endif // COUNTINGSORT_H

template <class T>
CountingSort<T>::CountingSort(std::vector<T> arr)
{
    this->_arr = arr;
}

template <class T>
T CountingSort<T>::findMax()
{
    T max = -500000;
    for (auto arrEl: this->_arr)
        {
            if (max < arrEl)
                max = arrEl;
        }
    return max;
}
