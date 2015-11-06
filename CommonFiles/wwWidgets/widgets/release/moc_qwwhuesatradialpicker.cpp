/****************************************************************************
** Meta object code from reading C++ file 'qwwhuesatradialpicker.h'
**
** Created: Sat Jun 29 09:35:04 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qwwhuesatradialpicker/qwwhuesatradialpicker.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qwwhuesatradialpicker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QwwHueSatRadialPicker[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       2,   34, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      23,   22,   22,   22, 0x05,
      41,   22,   22,   22, 0x05,

 // slots: signature, parameters, type, tag, flags
      63,   61,   22,   22, 0x0a,
      79,   77,   22,   22, 0x0a,

 // properties: name, type, flags
     100,   96, 0x02095103,
     113,  106, 0x43095103,

       0        // eod
};

static const char qt_meta_stringdata_QwwHueSatRadialPicker[] = {
    "QwwHueSatRadialPicker\0\0valueChanged(int)\0"
    "colorPicked(QColor)\0v\0setValue(int)\0"
    "c\0setColor(QColor)\0int\0value\0QColor\0"
    "color\0"
};

void QwwHueSatRadialPicker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QwwHueSatRadialPicker *_t = static_cast<QwwHueSatRadialPicker *>(_o);
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->colorPicked((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 2: _t->setValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QwwHueSatRadialPicker::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QwwHueSatRadialPicker::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QwwHueSatRadialPicker,
      qt_meta_data_QwwHueSatRadialPicker, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QwwHueSatRadialPicker::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QwwHueSatRadialPicker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QwwHueSatRadialPicker::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QwwHueSatRadialPicker))
        return static_cast<void*>(const_cast< QwwHueSatRadialPicker*>(this));
    if (!strcmp(_clname, "QwwPrivatable"))
        return static_cast< QwwPrivatable*>(const_cast< QwwHueSatRadialPicker*>(this));
    return QWidget::qt_metacast(_clname);
}

int QwwHueSatRadialPicker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = value(); break;
        case 1: *reinterpret_cast< QColor*>(_v) = color(); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setValue(*reinterpret_cast< int*>(_v)); break;
        case 1: setColor(*reinterpret_cast< QColor*>(_v)); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QwwHueSatRadialPicker::valueChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QwwHueSatRadialPicker::colorPicked(QColor _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
