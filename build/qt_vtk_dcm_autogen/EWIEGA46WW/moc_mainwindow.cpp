/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[15];
    char stringdata[257];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 13),
QT_MOC_LITERAL(2, 25, 0),
QT_MOC_LITERAL(3, 26, 8),
QT_MOC_LITERAL(4, 35, 13),
QT_MOC_LITERAL(5, 49, 11),
QT_MOC_LITERAL(6, 61, 9),
QT_MOC_LITERAL(7, 71, 27),
QT_MOC_LITERAL(8, 99, 23),
QT_MOC_LITERAL(9, 123, 25),
QT_MOC_LITERAL(10, 149, 8),
QT_MOC_LITERAL(11, 158, 24),
QT_MOC_LITERAL(12, 183, 23),
QT_MOC_LITERAL(13, 207, 25),
QT_MOC_LITERAL(14, 233, 22)
    },
    "MainWindow\0openDCMFolder\0\0drawFile\0"
    "drawDCMSeries\0std::string\0folderDCM\0"
    "on_btnOpenDCMFolder_clicked\0"
    "on_btnOpenImage_clicked\0"
    "on_hSliderDCM_sliderMoved\0position\0"
    "on_btnRotateFile_clicked\0"
    "on_btnRotateDCM_clicked\0"
    "on_btnExportImage_clicked\0"
    "on_btnMoveFile_clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08,
       3,    0,   65,    2, 0x08,
       4,    1,   66,    2, 0x08,
       7,    0,   69,    2, 0x08,
       8,    0,   70,    2, 0x08,
       9,    1,   71,    2, 0x08,
      11,    0,   74,    2, 0x08,
      12,    0,   75,    2, 0x08,
      13,    0,   76,    2, 0x08,
      14,    0,   77,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->openDCMFolder(); break;
        case 1: _t->drawFile(); break;
        case 2: _t->drawDCMSeries((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 3: _t->on_btnOpenDCMFolder_clicked(); break;
        case 4: _t->on_btnOpenImage_clicked(); break;
        case 5: _t->on_hSliderDCM_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_btnRotateFile_clicked(); break;
        case 7: _t->on_btnRotateDCM_clicked(); break;
        case 8: _t->on_btnExportImage_clicked(); break;
        case 9: _t->on_btnMoveFile_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
