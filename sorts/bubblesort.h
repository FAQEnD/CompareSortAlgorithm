#ifndef BUBBLESORT_H
#define BUBBLESORT_H
#include "isort.h"

template <class T>
class BubbleSort : public ISort<T>
{
public:
    BubbleSort();
    void sortOptimized();
    void sortWithFlag();
    void readArrayFromFile();
    static double algTimeSumSimple;
    static double algTimeSumOptimized;
    static double algTimeSumWithFlag;
private:
    std::vector<T> _saveArr;

public:
    double getAlgTimeSumSimple()
    {
        double tempSum = this->algTimeSumSimple;
        this->algTimeSumSimple = 0;
        return tempSum;
    }
    double getAlgTimeSumOptimized()
    {
        double tempSum = this->algTimeSumOptimized;
        this->algTimeSumOptimized = 0;
        return tempSum;
    }
    double getAlgTimeSumWithFlag()
    {
        double tempSum = this->algTimeSumWithFlag;
        this->algTimeSumWithFlag = 0;
        return tempSum;
    }
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
        this->algTimeSumSimple += this->getAlgorithmTime();
    }
};

template <class T>
double BubbleSort<T>::algTimeSumSimple;
template <class T>
double BubbleSort<T>::algTimeSumOptimized;
template <class T>
double BubbleSort<T>::algTimeSumWithFlag;

template <class T>
BubbleSort<T>::BubbleSort()
{
    this->readArrayFromFile();
    this->_sortAlgorithmName = "Bubble";
}

template <class T>
void BubbleSort<T>::sortOptimized()
{
    this->_sortAlgorithmName = "Optimized bubble";
    this->_arr = _saveArr;
    this->_tManager.start();

    for (unsigned int i = 0; i < this->_arr.size()-1; ++i)
        for (unsigned int j = 0; j < this->_arr.size() - 1 - i; ++j)
            if (this->_arr[j] > this->_arr[j + 1])
                std::swap(this->_arr[j + 1], this->_arr[j]);
    this->_tManager.stop();
    this->isSorted();
    this->algTimeSumOptimized += this->getAlgorithmTime();
}

template <class T>
void BubbleSort<T>::sortWithFlag()
{
    this->_sortAlgorithmName = "With flag bubble";
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
    this->algTimeSumWithFlag += this->getAlgorithmTime();
}

template <class T>
void BubbleSort<T>::readArrayFromFile()
{
    _saveArr.reserve(100000000);
    QFile hFile("arr.dat");
    if (!hFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Error in opening file arr.dat";
        return;
    }
    QTextStream in(&hFile);
    while(!in.atEnd())
    {
        T i ;
        in >> i;
        _saveArr.push_back(i);
    }
    _saveArr.pop_back();
}
#endif // BUBBLESORT_H
