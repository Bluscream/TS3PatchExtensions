/****************************************************************************
** Meta object code from reading C++ file 'QtConfig.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QtConfig.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QtConfig.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QtConfig_t {
    QByteArrayData data[11];
    char stringdata0[122];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QtConfig_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QtConfig_t qt_meta_stringdata_QtConfig = {
    {
QT_MOC_LITERAL(0, 0, 8), // "QtConfig"
QT_MOC_LITERAL(1, 9, 11), // "updateBoxes"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 12), // "saveToConfig"
QT_MOC_LITERAL(4, 35, 8), // "addBadge"
QT_MOC_LITERAL(5, 44, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(6, 61, 4), // "item"
QT_MOC_LITERAL(7, 66, 12), // "deleteBadge1"
QT_MOC_LITERAL(8, 79, 12), // "deleteBadge2"
QT_MOC_LITERAL(9, 92, 12), // "deleteBadge3"
QT_MOC_LITERAL(10, 105, 16) // "openManualBadges"

    },
    "QtConfig\0updateBoxes\0\0saveToConfig\0"
    "addBadge\0QTreeWidgetItem*\0item\0"
    "deleteBadge1\0deleteBadge2\0deleteBadge3\0"
    "openManualBadges"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QtConfig[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x0a /* Public */,
       3,    0,   50,    2, 0x0a /* Public */,
       4,    1,   51,    2, 0x0a /* Public */,
       7,    0,   54,    2, 0x0a /* Public */,
       8,    0,   55,    2, 0x0a /* Public */,
       9,    0,   56,    2, 0x0a /* Public */,
      10,    0,   57,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QtConfig::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QtConfig *_t = static_cast<QtConfig *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateBoxes(); break;
        case 1: _t->saveToConfig(); break;
        case 2: _t->addBadge((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1]))); break;
        case 3: _t->deleteBadge1(); break;
        case 4: _t->deleteBadge2(); break;
        case 5: _t->deleteBadge3(); break;
        case 6: _t->openManualBadges(); break;
        default: ;
        }
    }
}

const QMetaObject QtConfig::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_QtConfig.data,
      qt_meta_data_QtConfig,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QtConfig::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtConfig::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QtConfig.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int QtConfig::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE