/****************************************************************************
** Meta object code from reading C++ file 'PlaylistHeader.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/playlist/PlaylistHeader.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PlaylistHeader.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PlaylistHeader_t {
    QByteArrayData data[12];
    char stringdata0[164];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PlaylistHeader_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PlaylistHeader_t qt_meta_stringdata_PlaylistHeader = {
    {
QT_MOC_LITERAL(0, 0, 14), // "PlaylistHeader"
QT_MOC_LITERAL(1, 15, 24), // "SectionVisibilityChanged"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 7), // "logical"
QT_MOC_LITERAL(4, 49, 7), // "visible"
QT_MOC_LITERAL(5, 57, 12), // "MouseEntered"
QT_MOC_LITERAL(6, 70, 30), // "SectionRatingLockStatusChanged"
QT_MOC_LITERAL(7, 101, 5), // "state"
QT_MOC_LITERAL(8, 107, 13), // "ToggleVisible"
QT_MOC_LITERAL(9, 121, 7), // "section"
QT_MOC_LITERAL(10, 129, 11), // "HideCurrent"
QT_MOC_LITERAL(11, 141, 22) // "ToggleRatingEditStatus"

    },
    "PlaylistHeader\0SectionVisibilityChanged\0"
    "\0logical\0visible\0MouseEntered\0"
    "SectionRatingLockStatusChanged\0state\0"
    "ToggleVisible\0section\0HideCurrent\0"
    "ToggleRatingEditStatus"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PlaylistHeader[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x06 /* Public */,
       5,    0,   49,    2, 0x06 /* Public */,
       6,    1,   50,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   53,    2, 0x08 /* Private */,
      10,    0,   56,    2, 0x08 /* Private */,
      11,    0,   57,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PlaylistHeader::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PlaylistHeader *_t = static_cast<PlaylistHeader *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SectionVisibilityChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->MouseEntered(); break;
        case 2: _t->SectionRatingLockStatusChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->ToggleVisible((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->HideCurrent(); break;
        case 5: _t->ToggleRatingEditStatus(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PlaylistHeader::*)(int , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlaylistHeader::SectionVisibilityChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PlaylistHeader::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlaylistHeader::MouseEntered)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (PlaylistHeader::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlaylistHeader::SectionRatingLockStatusChanged)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PlaylistHeader::staticMetaObject = {
    { &StretchHeaderView::staticMetaObject, qt_meta_stringdata_PlaylistHeader.data,
      qt_meta_data_PlaylistHeader,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PlaylistHeader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PlaylistHeader::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PlaylistHeader.stringdata0))
        return static_cast<void*>(this);
    return StretchHeaderView::qt_metacast(_clname);
}

int PlaylistHeader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = StretchHeaderView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void PlaylistHeader::SectionVisibilityChanged(int _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PlaylistHeader::MouseEntered()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void PlaylistHeader::SectionRatingLockStatusChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
