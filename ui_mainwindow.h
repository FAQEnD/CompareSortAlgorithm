/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButtonStartSort;
    QTextEdit *textOutput;
    QComboBox *comboBoxSizeIndex;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(478, 248);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButtonStartSort = new QPushButton(centralWidget);
        pushButtonStartSort->setObjectName(QStringLiteral("pushButtonStartSort"));
        pushButtonStartSort->setGeometry(QRect(10, 40, 80, 21));
        textOutput = new QTextEdit(centralWidget);
        textOutput->setObjectName(QStringLiteral("textOutput"));
        textOutput->setGeometry(QRect(180, 10, 271, 171));
        textOutput->setReadOnly(true);
        comboBoxSizeIndex = new QComboBox(centralWidget);
        comboBoxSizeIndex->setObjectName(QStringLiteral("comboBoxSizeIndex"));
        comboBoxSizeIndex->setGeometry(QRect(100, 40, 69, 22));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 478, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        comboBoxSizeIndex->setCurrentIndex(6);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        pushButtonStartSort->setText(QApplication::translate("MainWindow", "Sort arrays", 0));
        comboBoxSizeIndex->clear();
        comboBoxSizeIndex->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "500", 0)
         << QApplication::translate("MainWindow", "1000", 0)
         << QApplication::translate("MainWindow", "5000", 0)
         << QApplication::translate("MainWindow", "10000", 0)
         << QApplication::translate("MainWindow", "50000", 0)
         << QApplication::translate("MainWindow", "100000", 0)
         << QApplication::translate("MainWindow", "500000", 0)
         << QApplication::translate("MainWindow", "1000000", 0)
         << QApplication::translate("MainWindow", "10000000", 0)
         << QApplication::translate("MainWindow", "100000000", 0)
        );
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
