#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sorts/selectionsort.h"
#include "sorts/shellsort.h"
#include "sorts/mergesort.h"
#include "sorts/quicksort.h"
#include "sorts/countingsort.h"
#include "sorts/bubblesort.h"
#include <QtDebug>
#include <future>
#include <ctime>
#include <QString>
#include <algorithm>
#include <QFile>
#include <functional>
#include <QFile>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _size = {500, 1000, 5000, 10000, 50000, 100000, 500000, 1000000, 10000000, 100000000};
    _currentSizeIndex = 6;
//    _arr = {5, 10, 2, 0, 15, 18, 1};
//    connect(ui->pushButtonStartSort, SIGNAL(clicked()), this, SLOT(onClickSelectionSort()));
//    connect(ui->pushButtonStartSort, SIGNAL(clicked()), this, SLOT(onClickShellSort()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonStartSort_clicked()
{
    prepareArray(_currentSizeIndex, "int");
//    prepareArray(_currentSizeIndex, "r int");
    if(_currentSizeIndex <= 6) //then we can sort in threads
    {
        qDebug() << "Run in threads";
    }
    else
    {
        qDebug() << "Run one by one";
        //    auto hThread = std::async(std::launch::async, &onClickSelectionSort, this);
        //    hThread.get();
//        onClickSelectionSort();
        onClickShellSort("Shell");
        onClickShellSort("Pratt");
        onClickShellSort("Pratt2");
        //    auto hSort = std::async(std::launch::async, [this] { return this->onClickSelectionSort(_arrInt); } );
        // create new thread and formate lambda function for passing arg to function
        //    hSort.get();
        onClickMergeSort();
        onClickQuickSort();
        onClickCountingSort();
//        onClickBubbleSort();
    }

//    onClickSelectionSort(_arrDouble);
//    onClickShellSort(_arrDouble, "Shell");
//    onClickShellSort(_arrDouble, "Pratt");
//    onClickShellSort(_arrDouble, "Pratt2");
//    onClickMergeSort(_arrDouble);
//    onClickQuickSort(_arrDouble);
//    onClickBubbleSort(_arrDouble);
}

void MainWindow::onClickSelectionSort()
{
    SelectionSort <int> selSort;
    selSort.sort();
    qDebug() << "selection sort time:" << selSort.getAlgorithmTime();
}

void MainWindow::onClickShellSort(QString sequenceName)
{
    ShellSort <int> shell(sequenceName);
    shell.sort();
    qDebug() << "shell sort time:" << shell.getAlgorithmTime();
}

void MainWindow::onClickMergeSort()
{
    MergeSort <int> merge;
    merge.sort();
    qDebug() << "merge sort time:" << merge.getAlgorithmTime();

}

void MainWindow::onClickQuickSort()
{
    QuickSort <int> quSort;
    quSort.sort();
    qDebug() << "quick sort time: " << quSort.getAlgorithmTime();

}

void MainWindow::onClickCountingSort()
{
    CountingSort <int> cSort;
    cSort.sort();
    qDebug() << "counting sort time: " << cSort.getAlgorithmTime();
}

void MainWindow::onClickBubbleSort()
{
    BubbleSort <int> bSort;
    bSort.sort();
    qDebug() << "simple bubble sort time: " << bSort.getAlgorithmTime();
    bSort.sortOptimized();
    qDebug() << "optimized bubble sort time: " << bSort.getAlgorithmTime();
    bSort.sortWithFlag();
    qDebug() << "bubble sort with flag time: " << bSort.getAlgorithmTime();

}


void MainWindow::onClickSelectionSortD()
{
    SelectionSort <double> selSort;
    selSort.sort();
    qDebug() << "selection sort time:" << selSort.getAlgorithmTime();
}

void MainWindow::onClickShellSortD(QString sequenceName)
{
    ShellSort <double> shell(sequenceName);
    shell.sort();
    qDebug() << "shell sort time:" << shell.getAlgorithmTime();
}

void MainWindow::onClickMergeSortD()
{
    MergeSort <double> merge;
    merge.sort();
    qDebug() << "merge sort time:" << merge.getAlgorithmTime();

}

void MainWindow::onClickQuickSortD()
{
    QuickSort <double> quSort;
    quSort.sort();
    qDebug() << "quick sort time: " << quSort.getAlgorithmTime();

}

void MainWindow::onClickBubbleSortD()
{
    BubbleSort <double> bSort;
    bSort.sort();
    qDebug() << "simple bubble sort time: " << bSort.getAlgorithmTime();
    bSort.sortOptimized();
    qDebug() << "optimized bubble sort time: " << bSort.getAlgorithmTime();
    bSort.sortWithFlag();
    qDebug() << "bubble sort with flag time: " << bSort.getAlgorithmTime();

}

void MainWindow::prepareArray(const unsigned int size, QString type)
{
    if(type == "int")
    {
        generateArray(_arrInt, _size[size]);
        saveArrayToFile(_arrInt);
        _arrInt.clear();
    }else
        if(type == "sorted int" || type == "s int")
        {
            readArrayFromFile(_arrInt);
            std::sort(_arrInt.begin(), _arrInt.end());
            saveArrayToFile(_arrInt);
            _arrInt.clear();
        }else
            if(type == "reverse int" || type == "r int")
            {
                readArrayFromFile(_arrInt);
                if(std::is_sorted(_arrInt.begin(), _arrInt.end()))
                    std::reverse(_arrInt.begin(), _arrInt.end());
                else
                    std::sort(_arrInt.begin(), _arrInt.end(), std::greater<int>());
                saveArrayToFile(_arrInt);
                _arrInt.clear();
            }
    if(type == "double")
    {
        generateArray(_arrDouble, _size[size]);
        saveArrayToFile(_arrDouble);
        _arrDouble.clear();
    }else
        if(type == "sorted double" || type == "s double")
        {
            readArrayFromFile(_arrDouble);
            std::sort(_arrDouble.begin(), _arrDouble.end());
            saveArrayToFile(_arrDouble);
            _arrDouble.clear();
        }else
            if(type == "reverse double" || type == "r double")
            {
                readArrayFromFile(_arrDouble);
                if(std::is_sorted(_arrDouble.begin(), _arrDouble.end()))
                    std::reverse(_arrDouble.begin(), _arrDouble.end());
                else
                    std::sort(_arrDouble.begin(), _arrDouble.end(), std::greater<double>());
                saveArrayToFile(_arrDouble);
                _arrDouble.clear();
            }
}

void MainWindow::generateArray(std::vector<double> &arr, unsigned const int size)
{
    arr.clear();
    arr.reserve(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<>dis(0, 100);
    for (unsigned int i = 0; i < size; ++i)
        try
        {
            arr.push_back(dis(gen));
        } catch(std::bad_alloc &thebadallocation)
        {
            qDebug() << "Bad memory allocate in function generateArray(double, size)";
            exit(-1);
        };
}

template <class T>
void MainWindow::printArray(std::vector<T> &arr)
{
    if(arr.size() >= _size[4])
    {
        qDebug() << "Array too big for output";
        qDebug() << "First ellement of arr is " << arr[0] << " and last: " << arr[arr.size()-1];
        return;
    }
    QString str;
    for(auto arrEl : arr)
    {
        str = QString::number(arrEl) + ' ';
        ui->textOutput->append(str);
    }
}

void MainWindow::generateArray(std::vector<int> &arr, unsigned const int size)
{
    arr.clear();
    arr.reserve(size);
    srand(time(NULL));
    for(unsigned int i = 0; i < size; ++i)
        try
        {
            arr.push_back(rand()%200 + 1);
        }catch(std::bad_alloc &theBadAllocation)
        {
            qDebug() << "Bad memory allocate in function generateArray(int, size)";
            exit(-1);
        };
    qDebug() << "array generated";
}

template <class T>
void MainWindow::saveArrayToFile(std::vector<T> &arr)
{
    QFile hFile("arr.dat");
//    if(hFile.exists() && hFile.size() <= arr.size())
//        return;
    if (!hFile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Error in opening file arr.dat";
        return;
    }

    QTextStream out(&hFile);
    for(auto arrEl : arr)
    {
        out << arrEl << " ";
    }
    hFile.close();
    qDebug() << "Array saved to file";
}

template <class T>
void MainWindow::readArrayFromFile(std::vector<T> &arr)
{
    arr.clear();
    arr.reserve(_size[_currentSizeIndex]);
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
        arr.push_back(i);
    }
    arr.pop_back();
}

void MainWindow::on_comboBoxSizeIndex_currentIndexChanged(int index)
{
    _currentSizeIndex = index;
}
