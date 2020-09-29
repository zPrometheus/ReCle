/****************************************************************************
** Meta object code from reading C++ file 'PlaylistTabBar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/playlist/PlaylistTabBar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PlaylistTabBar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PlaylistTabBar_t {
    QByteArrayData data[21];
    char stringdata0[248];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PlaylistTabBar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PlaylistTabBar_t qt_meta_stringdata_PlaylistTabBar = {
    {
QT_MOC_LITERAL(0, 0, 14), // "PlaylistTabBar"
QT_MOC_LITERAL(1, 15, 16), // "CurrentIdChanged"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 2), // "id"
QT_MOC_LITERAL(4, 36, 6), // "Rename"
QT_MOC_LITERAL(5, 43, 4), // "name"
QT_MOC_LITERAL(6, 48, 5), // "Close"
QT_MOC_LITERAL(7, 54, 4), // "Save"
QT_MOC_LITERAL(8, 59, 20), // "PlaylistOrderChanged"
QT_MOC_LITERAL(9, 80, 10), // "QList<int>"
QT_MOC_LITERAL(10, 91, 3), // "ids"
QT_MOC_LITERAL(11, 95, 17), // "PlaylistFavorited"
QT_MOC_LITERAL(12, 113, 8), // "favorite"
QT_MOC_LITERAL(13, 122, 19), // "CurrentIndexChanged"
QT_MOC_LITERAL(14, 142, 5), // "index"
QT_MOC_LITERAL(15, 148, 12), // "RenameInline"
QT_MOC_LITERAL(16, 161, 10), // "HideEditor"
QT_MOC_LITERAL(17, 172, 17), // "CloseFromTabIndex"
QT_MOC_LITERAL(18, 190, 21), // "PlaylistFavoritedSlot"
QT_MOC_LITERAL(19, 212, 26), // "PlaylistManagerInitialized"
QT_MOC_LITERAL(20, 239, 8) // "TabMoved"

    },
    "PlaylistTabBar\0CurrentIdChanged\0\0id\0"
    "Rename\0name\0Close\0Save\0PlaylistOrderChanged\0"
    "QList<int>\0ids\0PlaylistFavorited\0"
    "favorite\0CurrentIndexChanged\0index\0"
    "RenameInline\0HideEditor\0CloseFromTabIndex\0"
    "PlaylistFavoritedSlot\0PlaylistManagerInitialized\0"
    "TabMoved"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PlaylistTabBar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x06 /* Public */,
       4,    2,   97,    2, 0x06 /* Public */,
       6,    1,  102,    2, 0x06 /* Public */,
       7,    1,  105,    2, 0x06 /* Public */,
       8,    1,  108,    2, 0x06 /* Public */,
      11,    2,  111,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    1,  116,    2, 0x08 /* Private */,
       4,    0,  119,    2, 0x08 /* Private */,
      15,    0,  120,    2, 0x08 /* Private */,
      16,    0,  121,    2, 0x08 /* Private */,
       6,    0,  122,    2, 0x08 /* Private */,
      17,    1,  123,    2, 0x08 /* Private */,
      18,    2,  126,    2, 0x08 /* Private */,
      19,    0,  131,    2, 0x08 /* Private */,
      20,    0,  132,    2, 0x08 /* Private */,
       7,    0,  133,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    5,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    3,   12,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    3,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PlaylistTabBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PlaylistTabBar *_t = static_cast<PlaylistTabBar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->CurrentIdChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->Rename((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: _t->Close((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->Save((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->PlaylistOrderChanged((*reinterpret_cast< const QList<int>(*)>(_a[1]))); break;
        case 5: _t->PlaylistFavorited((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 6: _t->CurrentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->Rename(); break;
        case 8: _t->RenameInline(); break;
        case 9: _t->HideEditor(); break;
        case 10: _t->Close(); break;
        case 11: _t->CloseFromTabIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->PlaylistFavoritedSlot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 13: _t->PlaylistManagerInitialized(); break;
        case 14: _t->TabMoved(); break;
        case 15: _t->Save(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<int> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PlaylistTabBar::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlaylistTabBar::CurrentIdChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PlaylistTabBar::*)(int , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlaylistTabBar::Rename)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (PlaylistTabBar::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlaylistTabBar::Close)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (PlaylistTabBar::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlaylistTabBar::Save)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (PlaylistTabBar::*)(const QList<int> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlaylistTabBar::PlaylistOrderChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (PlaylistTabBar::*)(int , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlaylistTabBar::PlaylistFavorited)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PlaylistTabBar::staticMetaObject = {
    { &QTabBar::staticMetaObject, qt_meta_stringdata_PlaylistTabBar.data,
      qt_meta_data_PlaylistTabBar,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PlaylistTabBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PlaylistTabBar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PlaylistTabBar.stringdata0))
        return static_cast<void*>(this);
    return QTabBar::qt_metacast(_clname);
}

int PlaylistTabBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTabBar::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void PlaylistTabBar::CurrentIdChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PlaylistTabBar::Rename(int _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PlaylistTabBar::Close(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void PlaylistTabBar::Save(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void PlaylistTabBar::PlaylistOrderChanged(const QList<int> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void PlaylistTabBar::PlaylistFavorited(int _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
