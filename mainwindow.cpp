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
#include <windows.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _size = {500, 1000, 5000, 10000, 50000, 100000, 500000, 1000000, 10000000, 100000000};
    generateArray(_arrInt, _size[3]);
    generateArray(_arrDouble, _size[6]);
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
//    auto hThread = std::async(std::launch::async, &onClickSelectionSort, this);
//    hThread.get();
//    onClickSelectionSort();

//    onClickShellSort();

//    onClickMergeSort();

//    onClickQuickSort();

//    onClickCountingSort();

    onClickBubbleSort();


//    std::function<int (int)> f = [&] (int i)
//    {
//        return (i == 1) ? 1 : i * f(i-1);
//    };
//    qDebug() << f(5);

//    auto selSort = [&arr]()
//    {
//        for (unsigned int i = 0; i < arr.size(); ++i) {
//            auto min = *(std::max_element(arr.begin(), arr.end()));
//            int positionMin = 0;
//            for (unsigned int j = i; j < arr.size(); ++j)
//                if (min >= arr[j]) { min = arr[j]; positionMin = j; }
//            std::swap(arr[i], arr[positionMin]);
//        }
//    };
//    selSort();
//    auto hThread = std::async(selSort);
//    hThread.get();

}

void MainWindow::onClickSelectionSort()
{
    SelectionSort <int> selSort(_arrInt);
    selSort.sort();
    qDebug() << selSort.getAlgorithmTime();
}

void MainWindow::onClickShellSort()
{
    ShellSort <int> shell(_arrInt, "Pratt12");
    shell.sort();
}

void MainWindow::onClickMergeSort()
{
    MergeSort <int> merge(_arrInt);

    merge.sort();
    qDebug() << merge.getAlgorithmTime();

}

void MainWindow::onClickQuickSort()
{
    QuickSort <int> quSort(_arrInt);
    quSort.sort();
    qDebug() << quSort.getAlgorithmTime();

}

void MainWindow::onClickCountingSort()
{
    CountingSort <int> cSort(_arrInt);
    cSort.sort();
    qDebug() << cSort.getAlgorithmTime();
}

void MainWindow::onClickBubbleSort()
{
    BubbleSort <int> bSort(_arrInt);
    bSort.sort();
    qDebug() << bSort.getAlgorithmTime();
}

void MainWindow::generateArray(std::vector<double> &arr, const unsigned int size)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<>dis(0, 100);
    for (unsigned int i = 0; i < size; ++i)
        arr.push_back(dis(gen));
}

void MainWindow::generateArray(std::vector<int> &arr, unsigned const int size)
{
    srand(time(NULL));
    for(unsigned int i = 0; i < size; ++i)
        arr.push_back(rand()%200 + 1);
}
