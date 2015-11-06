/****************************************************************************
** Meta object code from reading C++ file 'qwwcolorbutton.h'
**
** Created: Sat Jun 29 09:35:09 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qwwcolorbutton/qwwcolorbutton.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qwwcolorbutton.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QwwColorButton[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       4,   49, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      38,   36,   15,   15, 0x0a,
      64,   62,   15,   15, 0x0a,
      82,   15,   15,   15, 0x08,
      95,   15,   15,   15, 0x08,
     121,   15,   15,   15, 0x08,
     147,   15,   15,   15, 0x08,

 // properties: name, type, flags
     191,  179, 0x0b095103,
     205,  198, 0x43095103,
     223,  218, 0x01095103,
     235,  218, 0x01095103,

       0        // eod
};

static const char qt_meta_stringdata_QwwColorButton[] = {
    "QwwColorButton\0\0colorPicked(QColor)\0"
    "c\0setCurrentColor(QColor)\0v\0"
    "setShowName(bool)\0_q_clicked()\0"
    "_q_activated(QModelIndex)\0"
    "_q_colorDialogRequested()\0"
    "_q_setCurrentIndex(QModelIndex)\0"
    "QStringList\0colors\0QColor\0currentColor\0"
    "bool\0dragEnabled\0showName\0"
};

void QwwColorButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QwwColorButton *_t = static_cast<QwwColorButton *>(_o);
        switch (_id) {
        case 0: _t->colorPicked((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 1: _t->setCurrentColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 2: _t->setShowName((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->d_func()->_q_clicked(); break;
        case 4: _t->d_func()->_q_activated((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 5: _t->d_func()->_q_colorDialogRequested(); break;
        case 6: _t->d_func()->_q_setCurrentIndex((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QwwColorButton::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QwwColorButton::staticMetaObject = {
    { &QPushButton::staticMetaObject, qt_meta_stringdata_QwwColorButton,
      qt_meta_data_QwwColorButton, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QwwColorButton::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QwwColorButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QwwColorButton::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QwwColorButton))
        return static_cast<void*>(const_cast< QwwColorButton*>(this));
    if (!strcmp(_clname, "QwwPrivatable"))
        return static_cast< QwwPrivatable*>(const_cast< QwwColorButton*>(this));
    return QPushButton::qt_metacast(_clname);
}

int QwwColorButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QStringList*>(_v) = colors(); break;
        case 1: *reinterpret_cast< QColor*>(_v) = currentColor(); break;
        case 2: *reinterpret_cast< bool*>(_v) = dragEnabled(); break;
        case 3: *reinterpret_cast< bool*>(_v) = showName(); break;
        }
        _id -= 4;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setColors(*reinterpret_cast< QStringList*>(_v)); break;
        case 1: setCurrentColor(*reinterpret_cast< QColor*>(_v)); break;
        case 2: setDragEnabled(*reinterpret_cast< bool*>(_v)); break;
        case 3: setShowName(*reinterpret_cast< bool*>(_v)); break;
        }
        _id -= 4;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QwwColorButton::colorPicked(const QColor & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
