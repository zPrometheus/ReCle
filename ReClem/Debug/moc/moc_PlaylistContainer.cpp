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
    QByteArrayData data[14];
    char stringdata0[187];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PlaylistContainer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PlaylistContainer_t qt_meta_stringdata_PlaylistContainer = {
    {
QT_MOC_LITERAL(0, 0, 17), // "PlaylistContainer"
QT_MOC_LITERAL(1, 18, 25), // "ViewSelectionModelChanged"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 15), // "SetTabBarHeight"
QT_MOC_LITERAL(4, 61, 6), // "height"
QT_MOC_LITERAL(5, 68, 11), // "DirtyTabBar"
QT_MOC_LITERAL(6, 80, 12), // "UpdateFilter"
QT_MOC_LITERAL(7, 93, 16), // "SelectionChanged"
QT_MOC_LITERAL(8, 110, 20), // "UpdateNoMatchesLabel"
QT_MOC_LITERAL(9, 131, 24), // "RepositionNoMatchesLabel"
QT_MOC_LITERAL(10, 156, 5), // "force"
QT_MOC_LITERAL(11, 162, 4), // "Save"
QT_MOC_LITERAL(12, 167, 10), // "QSettings*"
QT_MOC_LITERAL(13, 178, 8) // "settings"

    },
    "PlaylistContainer\0ViewSelectionModelChanged\0"
    "\0SetTabBarHeight\0height\0DirtyTabBar\0"
    "UpdateFilter\0SelectionChanged\0"
    "UpdateNoMatchesLabel\0RepositionNoMatchesLabel\0"
    "force\0Save\0QSettings*\0settings"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PlaylistContainer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   55,    2, 0x08 /* Private */,
       5,    0,   58,    2, 0x08 /* Private */,
       6,    0,   59,    2, 0x08 /* Private */,
       7,    0,   60,    2, 0x08 /* Private */,
       8,    0,   61,    2, 0x08 /* Private */,
       9,    1,   62,    2, 0x08 /* Private */,
      11,    1,   65,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, 0x80000000 | 12,   13,

       0        // eod
};

void PlaylistContainer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PlaylistContainer *_t = static_cast<PlaylistContainer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ViewSelectionModelChanged(); break;
        case 1: _t->SetTabBarHeight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->DirtyTabBar(); break;
        case 3: _t->UpdateFilter(); break;
        case 4: _t->SelectionChanged(); break;
        case 5: _t->UpdateNoMatchesLabel(); break;
        case 6: _t->RepositionNoMatchesLabel((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->Save((*reinterpret_cast< QSettings*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PlaylistContainer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlaylistContainer::ViewSelectionModelChanged)) {
                *result = 0;
                return;
            }
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
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void PlaylistContainer::ViewSelectionModelChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
