/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[20];
    char stringdata0[361];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 30), // "on_pushButtonStartSort_clicked"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 20), // "onClickSelectionSort"
QT_MOC_LITERAL(4, 64, 16), // "onClickShellSort"
QT_MOC_LITERAL(5, 81, 16), // "onClickMergeSort"
QT_MOC_LITERAL(6, 98, 16), // "onClickQuickSort"
QT_MOC_LITERAL(7, 115, 19), // "onClickCountingSort"
QT_MOC_LITERAL(8, 135, 17), // "onClickBubbleSort"
QT_MOC_LITERAL(9, 153, 21), // "onClickSelectionSortD"
QT_MOC_LITERAL(10, 175, 17), // "onClickShellSortD"
QT_MOC_LITERAL(11, 193, 17), // "onClickMergeSortD"
QT_MOC_LITERAL(12, 211, 17), // "onClickQuickSortD"
QT_MOC_LITERAL(13, 229, 18), // "onClickBubbleSortD"
QT_MOC_LITERAL(14, 248, 12), // "prepareArray"
QT_MOC_LITERAL(15, 261, 13), // "generateArray"
QT_MOC_LITERAL(16, 275, 17), // "std::vector<int>&"
QT_MOC_LITERAL(17, 293, 20), // "std::vector<double>&"
QT_MOC_LITERAL(18, 314, 40), // "on_comboBoxSizeIndex_currentI..."
QT_MOC_LITERAL(19, 355, 5) // "index"

    },
    "MainWindow\0on_pushButtonStartSort_clicked\0"
    "\0onClickSelectionSort\0onClickShellSort\0"
    "onClickMergeSort\0onClickQuickSort\0"
    "onClickCountingSort\0onClickBubbleSort\0"
    "onClickSelectionSortD\0onClickShellSortD\0"
    "onClickMergeSortD\0onClickQuickSortD\0"
    "onClickBubbleSortD\0prepareArray\0"
    "generateArray\0std::vector<int>&\0"
    "std::vector<double>&\0"
    "on_comboBoxSizeIndex_currentIndexChanged\0"
    "index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x08 /* Private */,
       3,    0,   95,    2, 0x08 /* Private */,
       4,    1,   96,    2, 0x08 /* Private */,
       5,    0,   99,    2, 0x08 /* Private */,
       6,    0,  100,    2, 0x08 /* Private */,
       7,    0,  101,    2, 0x08 /* Private */,
       8,    0,  102,    2, 0x08 /* Private */,
       9,    0,  103,    2, 0x08 /* Private */,
      10,    1,  104,    2, 0x08 /* Private */,
      11,    0,  107,    2, 0x08 /* Private */,
      12,    0,  108,    2, 0x08 /* Private */,
      13,    0,  109,    2, 0x08 /* Private */,
      14,    1,  110,    2, 0x08 /* Private */,
      15,    2,  113,    2, 0x08 /* Private */,
      15,    2,  118,    2, 0x08 /* Private */,
      18,    1,  123,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UInt,    2,
    QMetaType::Void, 0x80000000 | 16, QMetaType::UInt,    2,    2,
    QMetaType::Void, 0x80000000 | 17, QMetaType::UInt,    2,    2,
    QMetaType::Void, QMetaType::Int,   19,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButtonStartSort_clicked(); break;
        case 1: _t->onClickSelectionSort(); break;
        case 2: _t->onClickShellSort((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->onClickMergeSort(); break;
        case 4: _t->onClickQuickSort(); break;
        case 5: _t->onClickCountingSort(); break;
        case 6: _t->onClickBubbleSort(); break;
        case 7: _t->onClickSelectionSortD(); break;
        case 8: _t->onClickShellSortD((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->onClickMergeSortD(); break;
        case 10: _t->onClickQuickSortD(); break;
        case 11: _t->onClickBubbleSortD(); break;
        case 12: _t->prepareArray((*reinterpret_cast< const uint(*)>(_a[1]))); break;
        case 13: _t->generateArray((*reinterpret_cast< std::vector<int>(*)>(_a[1])),(*reinterpret_cast< const uint(*)>(_a[2]))); break;
        case 14: _t->generateArray((*reinterpret_cast< std::vector<double>(*)>(_a[1])),(*reinterpret_cast< const uint(*)>(_a[2]))); break;
        case 15: _t->on_comboBoxSizeIndex_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
