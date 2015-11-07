#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sorts/bubblesort.h"
#include "sorts/selectionsort.h"
#include "sorts/shellsort.h"
#include "sorts/mergesort.h"
#include "sorts/quicksort.h"
#include "sorts/countingsort.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _size = {500, 1000, 5000, 10000, 50000, 100000, 500000, 1000000, 10000000, 100000000};
    _currentSizeIndex = 6;
    _sortInt.push_back([&]() {
        this->onClickBubbleSort();
        this->onClickBubbleSort();
        return this->onClickBubbleSort(); });
    _sortInt.push_back([&]() {
        this->onClickSelectionSort();
        this->onClickSelectionSort();
        return this->onClickSelectionSort(); });
    _sortInt.push_back([&]() {
        this->onClickShellSort("Shell");
        this->onClickShellSort("Shell");
        return this->onClickShellSort("Shell"); });
    _sortInt.push_back([&]() {
        this->onClickShellSort("Pratt");
        this->onClickShellSort("Pratt");
        return this->onClickShellSort("Pratt"); });
    _sortInt.push_back([&]() {
        this->onClickShellSort("Pratt2");
        this->onClickShellSort("Pratt2");
        return this->onClickShellSort("Pratt2"); });
    _sortInt.push_back([&]() {
        this->onClickMergeSort();
        this->onClickMergeSort();
        return this->onClickMergeSort(); });
    _sortInt.push_back([&]() {
        this->onClickQuickSort();
        this->onClickQuickSort();
        return this->onClickQuickSort(); });
    _sortInt.push_back([&]() {
        this->onClickCountingSort();
        this->onClickCountingSort();
        return this->onClickCountingSort(); });

    _sortDouble.push_back([&]() { return this->onClickBubbleSortD(); });
    _sortDouble.push_back([&]() { return this->onClickSelectionSortD(); });
    _sortDouble.push_back([&]() { return this->onClickShellSortD("Shell"); });
    _sortDouble.push_back([&]() { return this->onClickShellSortD("Pratt"); });
    _sortDouble.push_back([&]() { return this->onClickShellSortD("Pratt2"); });
    _sortDouble.push_back([&]() { return this->onClickMergeSortD(); });
    _sortDouble.push_back([&]() { return this->onClickQuickSortD(); });
//    connect(ui->pushButtonStartSort, SIGNAL(clicked()), this, SLOT(onClickSelectionSort()));
//    connect(ui->pushButtonStartSort, SIGNAL(clicked()), this, SLOT(onClickShellSort()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonStartSort_clicked()
{
//    prepareArray(_currentSizeIndex, "int");
    for(unsigned int i = 0; i < _size.size(); ++i)
    {
        ui->textOutput->append("Size: " + QString::number(_size[i]));
        prepareArray(i, "int");
        for(unsigned int j = 0; j < _sortInt.size(); ++j)
        {
            if(i < 4)
                _sortInt[j]();
            else
                if(j > 1)
                    _sortInt[j]();
        }
    }

    //    auto hThread = std::async(std::launch::async, &onClickSelectionSort, this);
    //    hThread.get();
    //    auto hSort = std::async(std::launch::async, [this] { return this->onClickSelectionSort(_arrInt); } );
    // create new thread and formate lambda function for passing arg to function
    //    hSort.get();

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
    static int runCount;
    SelectionSort <int> selSort;
    selSort.sort();
    qDebug() << "selection sort time:" << selSort.getAlgorithmTime();
    ++runCount;
    if(runCount >= 3)
    {
        ui->textOutput->append("Selection: " + QString::number(selSort.getAlgTimeSum()/3));
        runCount = 0;
    }
}

void MainWindow::onClickShellSort(QString sequenceName)
{
    static int runCount;
    ShellSort <int> shell(sequenceName);
    shell.sort();
    qDebug() << "shell sort time:" << shell.getAlgorithmTime();
    ++runCount;
    if(runCount >= 3)
    {
        if(sequenceName == "Shell")
            ui->textOutput->append("Shell(Shell sequence): " + QString::number(shell.getAlgTimeSumShell()/3));
        else
            if(sequenceName == "Pratt")
                ui->textOutput->append("Shell(Pratt sequence): " + QString::number(shell.getAlgTimeSumPratt()/3));
            else
                ui->textOutput->append("Shell(PrattSecond sequence): " + QString::number(shell.getAlgTimeSumPrattSecond()/3));
        runCount = 0;
    }
}

void MainWindow::onClickMergeSort()
{
    static int runCount;
    MergeSort <int> mSort;
    mSort.sort();
    qDebug() << "merge sort time:" << mSort.getAlgorithmTime();
    ++runCount;
    if(runCount >= 3)
    {
        ui->textOutput->append("Merge: " + QString::number(mSort.getAlgTimeSum()/3));
        runCount = 0;
    }
}

void MainWindow::onClickQuickSort()
{
    static int runCount;
    QuickSort <int> quSort;
    quSort.sort();
    qDebug() << "quick sort time: " << quSort.getAlgorithmTime();
    ++runCount;
    if(runCount >= 3)
    {
        ui->textOutput->append("Quick: " + QString::number(quSort.getAlgTimeSum()/3));
        runCount = 0;
    }

}

void MainWindow::onClickCountingSort()
{
    static int runCount;
    CountingSort <int> cSort;
    cSort.sort();
    qDebug() << "counting sort time: " << cSort.getAlgorithmTime();
    ++runCount;
    if(runCount >= 3)
    {
        ui->textOutput->append("Counting: " + QString::number(cSort.getAlgTimeSum()/3));
        runCount = 0;
    }
}

void MainWindow::onClickBubbleSort()
{
    static int runCount;
    BubbleSort <int> bSort;
    bSort.sort();
    qDebug() << "Simple Bubble: " << bSort.getAlgorithmTime();
    bSort.sortOptimized();
    qDebug() << "Optimized Bubble: " << bSort.getAlgorithmTime();
    bSort.sortWithFlag();
    qDebug() << "bubble sort with flag time: " << bSort.getAlgorithmTime();
    ++runCount;
    if(runCount >= 3)
    {
        ui->textOutput->append("Simple Bubble: " + QString::number(bSort.getAlgTimeSumSimple()/3));
        ui->textOutput->append("Optimized Bubble: " + QString::number(bSort.getAlgTimeSumOptimized()/3));
        ui->textOutput->append("With flag Bubble: " + QString::number(bSort.getAlgTimeSumWithFlag()/3));
        runCount = 0;
    }
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
    qDebug() << "array generated";
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
