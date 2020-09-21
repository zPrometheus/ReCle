/****************************************************************************
** Meta object code from reading C++ file 'PlaylistManager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/playlist/PlaylistManager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PlaylistManager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PlaylistManagerInterface_t {
    QByteArrayData data[61];
    char stringdata0[751];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PlaylistManagerInterface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PlaylistManagerInterface_t qt_meta_stringdata_PlaylistManagerInterface = {
    {
QT_MOC_LITERAL(0, 0, 24), // "PlaylistManagerInterface"
QT_MOC_LITERAL(1, 25, 26), // "PlaylistManagerInitialized"
QT_MOC_LITERAL(2, 52, 0), // ""
QT_MOC_LITERAL(3, 53, 13), // "PlaylistAdded"
QT_MOC_LITERAL(4, 67, 2), // "id"
QT_MOC_LITERAL(5, 70, 4), // "name"
QT_MOC_LITERAL(6, 75, 8), // "favorite"
QT_MOC_LITERAL(7, 84, 15), // "PlaylistDeleted"
QT_MOC_LITERAL(8, 100, 14), // "PlaylistClosed"
QT_MOC_LITERAL(9, 115, 15), // "PlaylistRenamed"
QT_MOC_LITERAL(10, 131, 8), // "new_name"
QT_MOC_LITERAL(11, 140, 17), // "PlaylistFavorited"
QT_MOC_LITERAL(12, 158, 14), // "CurrentChanged"
QT_MOC_LITERAL(13, 173, 9), // "Playlist*"
QT_MOC_LITERAL(14, 183, 12), // "new_playlist"
QT_MOC_LITERAL(15, 196, 13), // "ActiveChanged"
QT_MOC_LITERAL(16, 210, 5), // "Error"
QT_MOC_LITERAL(17, 216, 7), // "message"
QT_MOC_LITERAL(18, 224, 18), // "SummaryTextChanged"
QT_MOC_LITERAL(19, 243, 7), // "summary"
QT_MOC_LITERAL(20, 251, 15), // "PlaylistChanged"
QT_MOC_LITERAL(21, 267, 8), // "playlist"
QT_MOC_LITERAL(22, 276, 15), // "EditingFinished"
QT_MOC_LITERAL(23, 292, 11), // "QModelIndex"
QT_MOC_LITERAL(24, 304, 5), // "index"
QT_MOC_LITERAL(25, 310, 13), // "PlayRequested"
QT_MOC_LITERAL(26, 324, 3), // "New"
QT_MOC_LITERAL(27, 328, 8), // "SongList"
QT_MOC_LITERAL(28, 337, 5), // "songs"
QT_MOC_LITERAL(29, 343, 12), // "special_type"
QT_MOC_LITERAL(30, 356, 4), // "Load"
QT_MOC_LITERAL(31, 361, 8), // "filename"
QT_MOC_LITERAL(32, 370, 4), // "Save"
QT_MOC_LITERAL(33, 375, 14), // "Playlist::Path"
QT_MOC_LITERAL(34, 390, 9), // "path_type"
QT_MOC_LITERAL(35, 400, 6), // "Rename"
QT_MOC_LITERAL(36, 407, 6), // "Delete"
QT_MOC_LITERAL(37, 414, 5), // "Close"
QT_MOC_LITERAL(38, 420, 4), // "Open"
QT_MOC_LITERAL(39, 425, 19), // "ChangePlaylistOrder"
QT_MOC_LITERAL(40, 445, 10), // "QList<int>"
QT_MOC_LITERAL(41, 456, 3), // "ids"
QT_MOC_LITERAL(42, 460, 5), // "Enque"
QT_MOC_LITERAL(43, 466, 26), // "SongChangeRequestProcessed"
QT_MOC_LITERAL(44, 493, 3), // "url"
QT_MOC_LITERAL(45, 497, 5), // "valid"
QT_MOC_LITERAL(46, 503, 18), // "SetCurrentPlaylist"
QT_MOC_LITERAL(47, 522, 17), // "SetActivePlaylist"
QT_MOC_LITERAL(48, 540, 18), // "SetActiveToCurrent"
QT_MOC_LITERAL(49, 559, 16), // "SelectionChanged"
QT_MOC_LITERAL(50, 576, 14), // "QItemSelection"
QT_MOC_LITERAL(51, 591, 9), // "selection"
QT_MOC_LITERAL(52, 601, 12), // "ClearCurrent"
QT_MOC_LITERAL(53, 614, 14), // "ShuffleCurrent"
QT_MOC_LITERAL(54, 629, 23), // "RemoveDuplicatesCurrent"
QT_MOC_LITERAL(55, 653, 24), // "RemoveUnavailableCurrent"
QT_MOC_LITERAL(56, 678, 16), // "SetActivePlaying"
QT_MOC_LITERAL(57, 695, 15), // "SetActivePaused"
QT_MOC_LITERAL(58, 711, 16), // "SetActiveStopped"
QT_MOC_LITERAL(59, 728, 15), // "RateCurrentSong"
QT_MOC_LITERAL(60, 744, 6) // "rating"

    },
    "PlaylistManagerInterface\0"
    "PlaylistManagerInitialized\0\0PlaylistAdded\0"
    "id\0name\0favorite\0PlaylistDeleted\0"
    "PlaylistClosed\0PlaylistRenamed\0new_name\0"
    "PlaylistFavorited\0CurrentChanged\0"
    "Playlist*\0new_playlist\0ActiveChanged\0"
    "Error\0message\0SummaryTextChanged\0"
    "summary\0PlaylistChanged\0playlist\0"
    "EditingFinished\0QModelIndex\0index\0"
    "PlayRequested\0New\0SongList\0songs\0"
    "special_type\0Load\0filename\0Save\0"
    "Playlist::Path\0path_type\0Rename\0Delete\0"
    "Close\0Open\0ChangePlaylistOrder\0"
    "QList<int>\0ids\0Enque\0SongChangeRequestProcessed\0"
    "url\0valid\0SetCurrentPlaylist\0"
    "SetActivePlaylist\0SetActiveToCurrent\0"
    "SelectionChanged\0QItemSelection\0"
    "selection\0ClearCurrent\0ShuffleCurrent\0"
    "RemoveDuplicatesCurrent\0"
    "RemoveUnavailableCurrent\0SetActivePlaying\0"
    "SetActivePaused\0SetActiveStopped\0"
    "RateCurrentSong\0rating"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PlaylistManagerInterface[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      38,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      13,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  204,    2, 0x06 /* Public */,
       3,    3,  205,    2, 0x06 /* Public */,
       7,    1,  212,    2, 0x06 /* Public */,
       8,    1,  215,    2, 0x06 /* Public */,
       9,    2,  218,    2, 0x06 /* Public */,
      11,    2,  223,    2, 0x06 /* Public */,
      12,    1,  228,    2, 0x06 /* Public */,
      15,    1,  231,    2, 0x06 /* Public */,
      16,    1,  234,    2, 0x06 /* Public */,
      18,    1,  237,    2, 0x06 /* Public */,
      20,    1,  240,    2, 0x06 /* Public */,
      22,    1,  243,    2, 0x06 /* Public */,
      25,    1,  246,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      26,    3,  249,    2, 0x0a /* Public */,
      26,    2,  256,    2, 0x2a /* Public | MethodCloned */,
      26,    1,  261,    2, 0x2a /* Public | MethodCloned */,
      30,    1,  264,    2, 0x0a /* Public */,
      32,    3,  267,    2, 0x0a /* Public */,
      35,    2,  274,    2, 0x0a /* Public */,
      36,    1,  279,    2, 0x0a /* Public */,
      37,    1,  282,    2, 0x0a /* Public */,
      38,    1,  285,    2, 0x0a /* Public */,
      39,    1,  288,    2, 0x0a /* Public */,
      42,    2,  291,    2, 0x0a /* Public */,
      43,    2,  296,    2, 0x0a /* Public */,
      46,    1,  301,    2, 0x0a /* Public */,
      47,    1,  304,    2, 0x0a /* Public */,
      48,    0,  307,    2, 0x0a /* Public */,
      49,    1,  308,    2, 0x0a /* Public */,
      52,    0,  311,    2, 0x0a /* Public */,
      53,    0,  312,    2, 0x0a /* Public */,
      54,    0,  313,    2, 0x0a /* Public */,
      55,    0,  314,    2, 0x0a /* Public */,
      56,    0,  315,    2, 0x0a /* Public */,
      57,    0,  316,    2, 0x0a /* Public */,
      58,    0,  317,    2, 0x0a /* Public */,
      59,    1,  318,    2, 0x0a /* Public */,
      59,    1,  321,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::Bool,    4,    5,    6,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    4,   10,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    4,    6,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::QString,   19,
    QMetaType::Void, 0x80000000 | 13,   21,
    QMetaType::Void, 0x80000000 | 23,   24,
    QMetaType::Void, 0x80000000 | 23,   24,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 27, QMetaType::QString,    5,   28,   29,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 27,    5,   28,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,   31,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, 0x80000000 | 33,    4,   31,   34,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    4,   10,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Bool, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, 0x80000000 | 40,   41,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,   24,
    QMetaType::Void, QMetaType::QUrl, QMetaType::Bool,   44,   45,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 50,   51,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   60,
    QMetaType::Void, QMetaType::Int,   60,

       0        // eod
};

void PlaylistManagerInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PlaylistManagerInterface *_t = static_cast<PlaylistManagerInterface *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->PlaylistManagerInitialized(); break;
        case 1: _t->PlaylistAdded((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 2: _t->PlaylistDeleted((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->PlaylistClosed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->PlaylistRenamed((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 5: _t->PlaylistFavorited((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 6: _t->CurrentChanged((*reinterpret_cast< Playlist*(*)>(_a[1]))); break;
        case 7: _t->ActiveChanged((*reinterpret_cast< Playlist*(*)>(_a[1]))); break;
        case 8: _t->Error((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->SummaryTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->PlaylistChanged((*reinterpret_cast< Playlist*(*)>(_a[1]))); break;
        case 11: _t->EditingFinished((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 12: _t->PlayRequested((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 13: _t->New((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const SongList(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 14: _t->New((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const SongList(*)>(_a[2]))); break;
        case 15: _t->New((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 16: _t->Load((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 17: _t->Save((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< Playlist::Path(*)>(_a[3]))); break;
        case 18: _t->Rename((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 19: _t->Delete((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: { bool _r = _t->Close((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 21: _t->Open((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->ChangePlaylistOrder((*reinterpret_cast< const QList<int>(*)>(_a[1]))); break;
        case 23: _t->Enque((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 24: _t->SongChangeRequestProcessed((*reinterpret_cast< const QUrl(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 25: _t->SetCurrentPlaylist((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 26: _t->SetActivePlaylist((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 27: _t->SetActiveToCurrent(); break;
        case 28: _t->SelectionChanged((*reinterpret_cast< const QItemSelection(*)>(_a[1]))); break;
        case 29: _t->ClearCurrent(); break;
        case 30: _t->ShuffleCurrent(); break;
        case 31: _t->RemoveDuplicatesCurrent(); break;
        case 32: _t->RemoveUnavailableCurrent(); break;
        case 33: _t->SetActivePlaying(); break;
        case 34: _t->SetActivePaused(); break;
        case 35: _t->SetActiveStopped(); break;
        case 36: _t->RateCurrentSong((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 37: _t->RateCurrentSong((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 22:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<int> >(); break;
            }
            break;
        case 28:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QItemSelection >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PlaylistManagerInterface::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlaylistManagerInterface::PlaylistManagerInitialized)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PlaylistManagerInterface::*)(int , const QString & , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlaylistManagerInterface::PlaylistAdded)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (PlaylistManagerInterface::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlaylistManagerInterface::PlaylistDeleted)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (PlaylistManagerInterface::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlaylistManagerInterface::PlaylistClosed)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (PlaylistManagerInterface::*)(int , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlaylistManagerInterface::PlaylistRenamed)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (PlaylistManagerInterface::*)(int , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlaylistManagerInterface::PlaylistFavorited)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (PlaylistManagerInterface::*)(Playlist * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlaylistManagerInterface::CurrentChanged)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (PlaylistManagerInterface::*)(Playlist * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlaylistManagerInterface::ActiveChanged)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (PlaylistManagerInterface::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlaylistManagerInterface::Error)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (PlaylistManagerInterface::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlaylistManagerInterface::SummaryTextChanged)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (PlaylistManagerInterface::*)(Playlist * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlaylistManagerInterface::PlaylistChanged)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (PlaylistManagerInterface::*)(const QModelIndex & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlaylistManagerInterface::EditingFinished)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (PlaylistManagerInterface::*)(const QModelIndex & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlaylistManagerInterface::PlayRequested)) {
                *result = 12;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PlaylistManagerInterface::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PlaylistManagerInterface.data,
      qt_meta_data_PlaylistManagerInterface,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PlaylistManagerInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PlaylistManagerInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PlaylistManagerInterface.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int PlaylistManagerInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 38)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 38;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 38)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 38;
    }
    return _id;
}

// SIGNAL 0
void PlaylistManagerInterface::PlaylistManagerInitialized()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void PlaylistManagerInterface::PlaylistAdded(int _t1, const QString & _t2, bool _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PlaylistManagerInterface::PlaylistDeleted(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void PlaylistManagerInterface::PlaylistClosed(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void PlaylistManagerInterface::PlaylistRenamed(int _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void PlaylistManagerInterface::PlaylistFavorited(int _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void PlaylistManagerInterface::CurrentChanged(Playlist * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void PlaylistManagerInterface::ActiveChanged(Playlist * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void PlaylistManagerInterface::Error(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void PlaylistManagerInterface::SummaryTextChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void PlaylistManagerInterface::PlaylistChanged(Playlist * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void PlaylistManagerInterface::EditingFinished(const QModelIndex & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void PlaylistManagerInterface::PlayRequested(const QModelIndex & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
