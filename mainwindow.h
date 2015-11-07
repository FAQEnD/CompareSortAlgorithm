#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QtDebug>
#include <algorithm>
#include <functional>
#include <future>
#include <ctime>
#include <random>
#include <thread>
#include <condition_variable>
#include <chrono>
#include <windows.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButtonStartSort_clicked();
    void onClickSelectionSort();
    void onClickShellSort(QString);
    void onClickMergeSort();
    void onClickQuickSort();
    void onClickCountingSort();
    void onClickBubbleSort();

    void onClickSelectionSortD();
    void onClickShellSortD(QString);
    void onClickMergeSortD();
    void onClickQuickSortD();
    void onClickBubbleSortD();

    void prepareArray(unsigned const int, QString);
    void generateArray(std::vector<int>&, const unsigned int);
    void generateArray(std::vector<double>&, const unsigned int);

    void on_comboBoxSizeIndex_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    std::vector<int> _arrInt;
    std::vector<double> _arrDouble;
    std::vector<unsigned int> _size;
    std::vector<std::function<void()> > _sortInt;
    std::vector<std::function<void()> > _sortDouble;
    unsigned int _currentSizeIndex;
    template <class T>
    void saveArrayToFile(std::vector<T>&);
    template <class T>
    void readArrayFromFile(std::vector<T>&);
    template <class T>
    void printArray(std::vector<T>&);
    void saveResultToFile(QString, double);
};

#endif // MAINWINDOW_H
