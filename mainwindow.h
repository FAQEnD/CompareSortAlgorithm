#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void onClickSelectionSort(std::vector<int>);
    void onClickShellSort(std::vector<int>, QString);
    void onClickMergeSort(std::vector<int>);
    void onClickQuickSort(std::vector<int>);
    void onClickCountingSort(std::vector<int>);
    void onClickBubbleSort(std::vector<int>);

    void onClickSelectionSort(std::vector<double>);
    void onClickShellSort(std::vector<double>, QString);
    void onClickMergeSort(std::vector<double>);
    void onClickQuickSort(std::vector<double>);
    void onClickBubbleSort(std::vector<double>);
    void prepareArray(unsigned const int);
    void generateArray(std::vector<int>&, const unsigned int);
    void generateArray(std::vector<double>&, const unsigned int);

private:
    Ui::MainWindow *ui;
    std::vector<int> _arrInt;
    std::vector<int> _arrIntSorted;
    std::vector<double> _arrDouble;
    std::vector<double> _arrDoubleSorted;
    std::vector<unsigned int> _size;
};

#endif // MAINWINDOW_H
