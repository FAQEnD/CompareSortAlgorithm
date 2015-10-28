#ifndef BUBBLESORT_H
#define BUBBLESORT_H
#include "isort.h"

template <class T>
class BubbleSort : public ISort<T>
{
public:
    BubbleSort(std::vector<T>);
    void sortOptimized();
    void sortWithFlag();
private:
    std::vector<T> _saveArr;

public:
    void sort()
    {
        this->_arr = _saveArr;
        this->_tManager.start();

        for (unsigned int i = 0; i < this->_arr.size()-1; ++i)
            for (unsigned int j = 0; j < this->_arr.size() -1; ++j)
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
    _saveArr = arr;
}

template <class T>
void BubbleSort<T>::sortOptimized()
{
    this->_arr = _saveArr;
    this->_tManager.start();

    for (unsigned int i = 0; i < this->_arr.size()-1; ++i)
        for (unsigned int j = 0; j < this->_arr.size() - 1 - i; ++j)
            if (this->_arr[j] > this->_arr[j + 1])
                std::swap(this->_arr[j + 1], this->_arr[j]);
    this->_tManager.stop();
    this->isSorted();
}

template <class T>
void BubbleSort<T>::sortWithFlag()
{
    this->_arr = _saveArr;
    this->_tManager.start();

    bool flag = true;
    for (unsigned int i = 0; i < this->_arr.size()-1 && flag; ++i)
    {
        flag = false;
        for (unsigned int j = 0; j < this->_arr.size() - 1; ++j)
            if (this->_arr[j] > this->_arr[j + 1])
            {
                std::swap(this->_arr[j + 1], this->_arr[j]);
                flag = true;
            }
    }
    this->_tManager.stop();
    this->isSorted();
}
