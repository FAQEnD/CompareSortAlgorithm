#ifndef ISORT_H
#define ISORT_H
#include <vector>

template <class T>
class ISort
{
public:
    virtual void sort() = 0;
protected:
    std::vector<T> _arr;
};

#endif // ISORT_H
