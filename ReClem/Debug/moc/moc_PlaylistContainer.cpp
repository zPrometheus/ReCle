/****************************************************************************
** Meta object code from reading C++ file 'PlaylistContainer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/playlist/PlaylistContainer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PlaylistContainer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PlaylistContainer_t {
    QByteArrayData data[9];
    char stringdata0[92];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PlaylistContainer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PlaylistContainer_t qt_meta_stringdata_PlaylistContainer = {
    {
QT_MOC_LITERAL(0, 0, 17), // "PlaylistContainer"
QT_MOC_LITERAL(1, 18, 15), // "SetTabBarHeight"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 6), // "height"
QT_MOC_LITERAL(4, 42, 11), // "DirtyTabBar"
QT_MOC_LITERAL(5, 54, 12), // "UpdateFilter"
QT_MOC_LITERAL(6, 67, 4), // "Save"
QT_MOC_LITERAL(7, 72, 10), // "QSettings*"
QT_MOC_LITERAL(8, 83, 8) // "settings"

    },
    "PlaylistContainer\0SetTabBarHeight\0\0"
    "height\0DirtyTabBar\0UpdateFilter\0Save\0"
    "QSettings*\0settings"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PlaylistContainer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x08 /* Private */,
       4,    0,   37,    2, 0x08 /* Private */,
       5,    0,   38,    2, 0x08 /* Private */,
       6,    1,   39,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,

       0        // eod
};

void PlaylistContainer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PlaylistContainer *_t = static_cast<PlaylistContainer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SetTabBarHeight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->DirtyTabBar(); break;
        case 2: _t->UpdateFilter(); break;
        case 3: _t->Save((*reinterpret_cast< QSettings*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PlaylistContainer::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PlaylistContainer.data,
      qt_meta_data_PlaylistContainer,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PlaylistContainer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PlaylistContainer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PlaylistContainer.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int PlaylistContainer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE