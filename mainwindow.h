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
    void onClickSelectionSort();
    void onClickShellSort();
    void onClickMergeSort();
    void generateArray(std::vector<int>&, const unsigned int);
    void generateArray(std::vector<double>&, const unsigned int);

private:
    Ui::MainWindow *ui;
    std::vector<int> _arrInt;
    std::vector<double> _arrDouble;
    std::vector<unsigned int> _size;
};

#endif // MAINWINDOW_H
