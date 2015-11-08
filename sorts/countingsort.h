#ifndef COUNTINGSORT_H
#define COUNTINGSORT_H
#include "isort.h"

template <class T>
class CountingSort : public ISort<T>
{
public:
    CountingSort();
    T findMax();
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
        std::vector<int> counter(findMax() + 1, 0);
            for (auto arrEl : this->_arr)
                counter[arrEl]++;
            this->_arr.clear();
            for (unsigned int i = 0; i < counter.size(); i++)
                for (int j = 0; j < counter[i]; j++)
                    this->_arr.push_back(i);

        this->_tManager.stop();
        this->isSorted();
        this->algTimeSum += this->getAlgorithmTime();
    }

};

template <class T>
double CountingSort<T>::algTimeSum;

template <class T>
CountingSort<T>::CountingSort()
{
    this->readArrayFromFile();
    this->_sortAlgorithmName = "Counting";
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
#endif // COUNTINGSORT_H
