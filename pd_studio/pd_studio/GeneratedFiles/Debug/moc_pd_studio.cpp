/****************************************************************************
** Meta object code from reading C++ file 'pd_studio.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../pd_studio.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pd_studio.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_pd_studio_t {
    QByteArrayData data[12];
    char stringdata0[157];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_pd_studio_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_pd_studio_t qt_meta_stringdata_pd_studio = {
    {
QT_MOC_LITERAL(0, 0, 9), // "pd_studio"
QT_MOC_LITERAL(1, 10, 15), // "slot_FileImport"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 13), // "slot_CloseTab"
QT_MOC_LITERAL(4, 41, 5), // "index"
QT_MOC_LITERAL(5, 47, 16), // "slot_Trim_Export"
QT_MOC_LITERAL(6, 64, 15), // "slot_Trim_Reset"
QT_MOC_LITERAL(7, 80, 14), // "slot_Trim_Save"
QT_MOC_LITERAL(8, 95, 11), // "slot_Filter"
QT_MOC_LITERAL(9, 107, 18), // "slot_Filter_Update"
QT_MOC_LITERAL(10, 126, 14), // "slot_FFT_Trans"
QT_MOC_LITERAL(11, 141, 15) // "slot_FFT_Update"

    },
    "pd_studio\0slot_FileImport\0\0slot_CloseTab\0"
    "index\0slot_Trim_Export\0slot_Trim_Reset\0"
    "slot_Trim_Save\0slot_Filter\0"
    "slot_Filter_Update\0slot_FFT_Trans\0"
    "slot_FFT_Update"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_pd_studio[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    1,   60,    2, 0x08 /* Private */,
       5,    0,   63,    2, 0x08 /* Private */,
       6,    0,   64,    2, 0x08 /* Private */,
       7,    0,   65,    2, 0x08 /* Private */,
       8,    0,   66,    2, 0x08 /* Private */,
       9,    0,   67,    2, 0x08 /* Private */,
      10,    0,   68,    2, 0x08 /* Private */,
      11,    0,   69,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void pd_studio::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        pd_studio *_t = static_cast<pd_studio *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slot_FileImport(); break;
        case 1: _t->slot_CloseTab((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->slot_Trim_Export(); break;
        case 3: _t->slot_Trim_Reset(); break;
        case 4: _t->slot_Trim_Save(); break;
        case 5: _t->slot_Filter(); break;
        case 6: _t->slot_Filter_Update(); break;
        case 7: _t->slot_FFT_Trans(); break;
        case 8: _t->slot_FFT_Update(); break;
        default: ;
        }
    }
}

const QMetaObject pd_studio::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_pd_studio.data,
      qt_meta_data_pd_studio,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *pd_studio::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *pd_studio::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_pd_studio.stringdata0))
        return static_cast<void*>(const_cast< pd_studio*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int pd_studio::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
