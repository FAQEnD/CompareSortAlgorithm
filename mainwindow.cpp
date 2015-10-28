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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _size = {500, 1000, 5000, 10000, 50000, 100000, 500000, 1000000, 10000000, 100000000};
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
    prepareArray(8);
//    auto hThread = std::async(std::launch::async, &onClickSelectionSort, this);
//    hThread.get();
//    onClickSelectionSort(_arrInt);
//    onClickShellSort(_arrInt, "Shell");
//    onClickShellSort(_arrInt, "Pratt");
//    onClickShellSort(_arrInt, "Pratt2");
    onClickMergeSort(_arrInt);
    onClickQuickSort(_arrInt);
//    onClickCountingSort(_arrInt);
//    onClickBubbleSort(_arrInt);

//    onClickSelectionSort(_arrDouble);
//    onClickShellSort(_arrDouble, "Shell");
//    onClickShellSort(_arrDouble, "Pratt");
//    onClickShellSort(_arrDouble, "Pratt2");
//    onClickMergeSort(_arrDouble);
//    onClickQuickSort(_arrDouble);
//    onClickBubbleSort(_arrDouble);
}

void MainWindow::onClickSelectionSort(std::vector<int> arr)
{
    SelectionSort <int> selSort(arr);
    selSort.sort();
    qDebug() << "selection sort time:" << selSort.getAlgorithmTime();
}

void MainWindow::onClickShellSort(std::vector<int> arr, QString sequenceName)
{
    ShellSort <int> shell(arr, sequenceName);
    shell.sort();
    qDebug() << "shell sort time:" << shell.getAlgorithmTime();
}

void MainWindow::onClickMergeSort(std::vector<int> arr)
{
    MergeSort <int> merge(arr);
    merge.sort();
    qDebug() << "merge sort time:" << merge.getAlgorithmTime();

}

void MainWindow::onClickQuickSort(std::vector<int> arr)
{
    QuickSort <int> quSort(arr);
    quSort.sort();
    qDebug() << "quick sort time: " << quSort.getAlgorithmTime();

}

void MainWindow::onClickCountingSort(std::vector<int> arr)
{
    CountingSort <int> cSort(arr);
    cSort.sort();
    qDebug() << "counting sort time: " << cSort.getAlgorithmTime();
}

void MainWindow::onClickBubbleSort(std::vector<int> arr)
{
    BubbleSort <int> bSort(arr);
    bSort.sort();
    qDebug() << "simple bubble sort time: " << bSort.getAlgorithmTime();
    bSort.sortOptimized();
    qDebug() << "optimized bubble sort time: " << bSort.getAlgorithmTime();
    bSort.sortWithFlag();
    qDebug() << "bubble sort with flag time: " << bSort.getAlgorithmTime();

}


void MainWindow::onClickSelectionSort(std::vector<double> arr)
{
    SelectionSort <double> selSort(arr);
    selSort.sort();
    qDebug() << "selection sort time:" << selSort.getAlgorithmTime();
}

void MainWindow::onClickShellSort(std::vector<double> arr, QString sequenceName)
{
    ShellSort <double> shell(arr, sequenceName);
    shell.sort();
    qDebug() << "shell sort time:" << shell.getAlgorithmTime();
}

void MainWindow::onClickMergeSort(std::vector<double> arr)
{
    MergeSort <double> merge(arr);
    merge.sort();
    qDebug() << "merge sort time:" << merge.getAlgorithmTime();

}

void MainWindow::onClickQuickSort(std::vector<double> arr)
{
    QuickSort <double> quSort(arr);
    quSort.sort();
    qDebug() << "quick sort time: " << quSort.getAlgorithmTime();

}

void MainWindow::onClickBubbleSort(std::vector<double> arr)
{
    BubbleSort <double> bSort(arr);
    bSort.sort();
    qDebug() << "simple bubble sort time: " << bSort.getAlgorithmTime();
    bSort.sortOptimized();
    qDebug() << "optimized bubble sort time: " << bSort.getAlgorithmTime();
    bSort.sortWithFlag();
    qDebug() << "bubble sort with flag time: " << bSort.getAlgorithmTime();

}

void MainWindow::prepareArray(const unsigned int size)
{
    generateArray(_arrInt, _size[size]);
//    generateArray(_arrDouble, _size[size]);
//    _arrIntSorted = _arrInt;
//    std::sort(_arrIntSorted.begin(), _arrIntSorted.end());
//    _arrDoubleSorted = _arrDouble;
//    std::sort(_arrDoubleSorted.begin(), _arrDoubleSorted.end());
}

void MainWindow::generateArray(std::vector<double> &arr, unsigned const int size)
{
    arr.clear();
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

void MainWindow::generateArray(std::vector<int> &arr, unsigned const int size)
{
    arr.clear();
    srand(time(NULL));
    for(unsigned int i = 0; i < size; ++i)
        arr.push_back(rand()%200 + 1);
}
