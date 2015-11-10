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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
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
    QGroupBox *groupBoxSort;
    QCheckBox *checkBoxBubble;
    QCheckBox *checkBoxSelection;
    QCheckBox *checkBoxShell;
    QCheckBox *checkBoxMerge;
    QCheckBox *checkBoxQuick;
    QCheckBox *checkBoxCounting;
    QPushButton *pushButtonSort;
    QComboBox *comboBoxSelectedSort;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(478, 317);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButtonStartSort = new QPushButton(centralWidget);
        pushButtonStartSort->setObjectName(QStringLiteral("pushButtonStartSort"));
        pushButtonStartSort->setEnabled(false);
        pushButtonStartSort->setGeometry(QRect(10, 230, 80, 21));
        textOutput = new QTextEdit(centralWidget);
        textOutput->setObjectName(QStringLiteral("textOutput"));
        textOutput->setGeometry(QRect(310, 10, 141, 241));
        textOutput->setReadOnly(true);
        comboBoxSizeIndex = new QComboBox(centralWidget);
        comboBoxSizeIndex->setObjectName(QStringLiteral("comboBoxSizeIndex"));
        comboBoxSizeIndex->setGeometry(QRect(160, 40, 81, 22));
        groupBoxSort = new QGroupBox(centralWidget);
        groupBoxSort->setObjectName(QStringLiteral("groupBoxSort"));
        groupBoxSort->setGeometry(QRect(10, 70, 241, 101));
        checkBoxBubble = new QCheckBox(groupBoxSort);
        checkBoxBubble->setObjectName(QStringLiteral("checkBoxBubble"));
        checkBoxBubble->setGeometry(QRect(10, 20, 111, 17));
        checkBoxSelection = new QCheckBox(groupBoxSort);
        checkBoxSelection->setObjectName(QStringLiteral("checkBoxSelection"));
        checkBoxSelection->setGeometry(QRect(10, 40, 70, 17));
        checkBoxShell = new QCheckBox(groupBoxSort);
        checkBoxShell->setObjectName(QStringLiteral("checkBoxShell"));
        checkBoxShell->setGeometry(QRect(10, 60, 70, 17));
        checkBoxMerge = new QCheckBox(groupBoxSort);
        checkBoxMerge->setObjectName(QStringLiteral("checkBoxMerge"));
        checkBoxMerge->setGeometry(QRect(140, 20, 70, 17));
        checkBoxQuick = new QCheckBox(groupBoxSort);
        checkBoxQuick->setObjectName(QStringLiteral("checkBoxQuick"));
        checkBoxQuick->setGeometry(QRect(140, 40, 70, 17));
        checkBoxCounting = new QCheckBox(groupBoxSort);
        checkBoxCounting->setObjectName(QStringLiteral("checkBoxCounting"));
        checkBoxCounting->setGeometry(QRect(140, 60, 70, 17));
        pushButtonSort = new QPushButton(centralWidget);
        pushButtonSort->setObjectName(QStringLiteral("pushButtonSort"));
        pushButtonSort->setGeometry(QRect(164, 180, 81, 23));
        comboBoxSelectedSort = new QComboBox(centralWidget);
        comboBoxSelectedSort->setObjectName(QStringLiteral("comboBoxSelectedSort"));
        comboBoxSelectedSort->setGeometry(QRect(20, 40, 121, 22));
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

        comboBoxSizeIndex->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        pushButtonStartSort->setText(QApplication::translate("MainWindow", "All sorts", 0));
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
        groupBoxSort->setTitle(QApplication::translate("MainWindow", "Sort", 0));
        checkBoxBubble->setText(QApplication::translate("MainWindow", "Bubble", 0));
        checkBoxSelection->setText(QApplication::translate("MainWindow", "Selection", 0));
        checkBoxShell->setText(QApplication::translate("MainWindow", "Shell", 0));
        checkBoxMerge->setText(QApplication::translate("MainWindow", "Merge", 0));
        checkBoxQuick->setText(QApplication::translate("MainWindow", "Quick", 0));
        checkBoxCounting->setText(QApplication::translate("MainWindow", "Counting", 0));
        pushButtonSort->setText(QApplication::translate("MainWindow", "Sort", 0));
        comboBoxSelectedSort->clear();
        comboBoxSelectedSort->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Random Int", 0)
         << QApplication::translate("MainWindow", "Sorted Int", 0)
         << QApplication::translate("MainWindow", "Reverse Sorted Int", 0)
         << QApplication::translate("MainWindow", "Random Double", 0)
         << QApplication::translate("MainWindow", "Sorted Double", 0)
         << QApplication::translate("MainWindow", "Reverse Sorted Double", 0)
        );
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
