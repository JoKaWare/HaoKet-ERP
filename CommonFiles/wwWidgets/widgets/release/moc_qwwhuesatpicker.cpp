/****************************************************************************
** Meta object code from reading C++ file 'qwwhuesatpicker.h'
**
** Created: Sat Jun 29 09:35:04 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qwwhuesatpicker/qwwhuesatpicker.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qwwhuesatpicker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QwwHueSatPicker[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       6,   84, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x05,
      35,   16,   16,   16, 0x05,
      58,   16,   16,   16, 0x05,
      81,   16,   16,   16, 0x05,
     104,   16,   16,   16, 0x05,
     129,  127,   16,   16, 0x05,
     154,  127,   16,   16, 0x05,
     179,   16,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
     201,  199,   16,   16, 0x0a,
     215,  199,   16,   16, 0x0a,
     234,  199,   16,   16, 0x0a,
     255,  253,   16,   16, 0x0a,
     274,  253,   16,   16, 0x0a,
     295,  293,   16,   16, 0x0a,

 // properties: name, type, flags
     316,  312, 0x02095103,
     327,  312, 0x02095103,
     338,  312, 0x02095103,
     349,  312, 0x02095103,
     360,  312, 0x02095103,
     373,  366, 0x43095103,

       0        // eod
};

static const char qt_meta_stringdata_QwwHueSatPicker[] = {
    "QwwHueSatPicker\0\0valueChanged(int)\0"
    "minimumHueChanged(int)\0maximumHueChanged(int)\0"
    "minimumSatChanged(int)\0maximumSatChanged(int)\0"
    ",\0satRangeChanged(int,int)\0"
    "hueRangeChanged(int,int)\0colorPicked(QColor)\0"
    "v\0setValue(int)\0setMinimumSat(int)\0"
    "setMaximumSat(int)\0h\0setMinimumHue(int)\0"
    "setMaximumHue(int)\0c\0setColor(QColor)\0"
    "int\0minimumHue\0maximumHue\0minimumSat\0"
    "maximumSat\0value\0QColor\0color\0"
};

void QwwHueSatPicker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QwwHueSatPicker *_t = static_cast<QwwHueSatPicker *>(_o);
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->minimumHueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->maximumHueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->minimumSatChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->maximumSatChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->satRangeChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->hueRangeChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->colorPicked((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 8: _t->setValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->setMinimumSat((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->setMaximumSat((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->setMinimumHue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->setMaximumHue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->setColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QwwHueSatPicker::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QwwHueSatPicker::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_QwwHueSatPicker,
      qt_meta_data_QwwHueSatPicker, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QwwHueSatPicker::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QwwHueSatPicker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QwwHueSatPicker::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QwwHueSatPicker))
        return static_cast<void*>(const_cast< QwwHueSatPicker*>(this));
    if (!strcmp(_clname, "QwwPrivatable"))
        return static_cast< QwwPrivatable*>(const_cast< QwwHueSatPicker*>(this));
    return QFrame::qt_metacast(_clname);
}

int QwwHueSatPicker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = minimumHue(); break;
        case 1: *reinterpret_cast< int*>(_v) = maximumHue(); break;
        case 2: *reinterpret_cast< int*>(_v) = minimumSat(); break;
        case 3: *reinterpret_cast< int*>(_v) = maximumSat(); break;
        case 4: *reinterpret_cast< int*>(_v) = value(); break;
        case 5: *reinterpret_cast< QColor*>(_v) = color(); break;
        }
        _id -= 6;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setMinimumHue(*reinterpret_cast< int*>(_v)); break;
        case 1: setMaximumHue(*reinterpret_cast< int*>(_v)); break;
        case 2: setMinimumSat(*reinterpret_cast< int*>(_v)); break;
        case 3: setMaximumSat(*reinterpret_cast< int*>(_v)); break;
        case 4: setValue(*reinterpret_cast< int*>(_v)); break;
        case 5: setColor(*reinterpret_cast< QColor*>(_v)); break;
        }
        _id -= 6;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 6;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QwwHueSatPicker::valueChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QwwHueSatPicker::minimumHueChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QwwHueSatPicker::maximumHueChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QwwHueSatPicker::minimumSatChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void QwwHueSatPicker::maximumSatChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void QwwHueSatPicker::satRangeChanged(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void QwwHueSatPicker::hueRangeChanged(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void QwwHueSatPicker::colorPicked(QColor _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_END_MOC_NAMESPACE
