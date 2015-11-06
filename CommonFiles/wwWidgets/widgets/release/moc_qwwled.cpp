/****************************************************************************
** Meta object code from reading C++ file 'qwwled.h'
**
** Created: Sat Jun 29 09:35:04 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qwwled/qwwled.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qwwled.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QwwLed[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       6,   69, // properties
       1,   87, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x05,
      29,    7,    7,    7, 0x05,
      43,    7,    7,    7, 0x05,

 // slots: signature, parameters, type, tag, flags
      55,   53,    7,    7, 0x0a,
      72,    7,    7,    7, 0x0a,
      89,    7,    7,    7, 0x0a,
     105,    7,    7,    7, 0x0a,
     114,    7,    7,    7, 0x0a,
     133,    7,    7,    7, 0x0a,
     151,    7,    7,    7, 0x0a,
     166,    7,    7,    7, 0x0a,

 // properties: name, type, flags
     181,  174, 0x43095103,
     192,  187, 0x01095103,
     206,  200, 0x0009510b,
     216,  212, 0x02095103,
     227,  187, 0x01095103,
     236,  212, 0x02095103,

 // enums: name, flags, count, data
     200, 0x0,    4,   91,

 // enum data: key, value
     243, uint(QwwLed::Circular),
     252, uint(QwwLed::RectangularSunken),
     270, uint(QwwLed::RectangularRaised),
     288, uint(QwwLed::RectangularPlain),

       0        // eod
};

static const char qt_meta_stringdata_QwwLed[] = {
    "QwwLed\0\0colorChanged(QColor)\0toggled(bool)\0"
    "clicked()\0c\0setColor(QColor)\0"
    "setChecked(bool)\0setShape(Shape)\0"
    "toggle()\0setFrameWidth(int)\0"
    "setAnimated(bool)\0setPeriod(int)\0"
    "blink()\0QColor\0color\0bool\0checked\0"
    "Shape\0shape\0int\0frameWidth\0animated\0"
    "period\0Circular\0RectangularSunken\0"
    "RectangularRaised\0RectangularPlain\0"
};

void QwwLed::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QwwLed *_t = static_cast<QwwLed *>(_o);
        switch (_id) {
        case 0: _t->colorChanged((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 1: _t->toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->clicked(); break;
        case 3: _t->setColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 4: _t->setChecked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->setShape((*reinterpret_cast< Shape(*)>(_a[1]))); break;
        case 6: _t->toggle(); break;
        case 7: _t->setFrameWidth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->setAnimated((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->setPeriod((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->blink(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QwwLed::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QwwLed::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QwwLed,
      qt_meta_data_QwwLed, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QwwLed::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QwwLed::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QwwLed::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QwwLed))
        return static_cast<void*>(const_cast< QwwLed*>(this));
    if (!strcmp(_clname, "QwwPrivatable"))
        return static_cast< QwwPrivatable*>(const_cast< QwwLed*>(this));
    return QWidget::qt_metacast(_clname);
}

int QwwLed::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QColor*>(_v) = color(); break;
        case 1: *reinterpret_cast< bool*>(_v) = isChecked(); break;
        case 2: *reinterpret_cast< Shape*>(_v) = shape(); break;
        case 3: *reinterpret_cast< int*>(_v) = frameWidth(); break;
        case 4: *reinterpret_cast< bool*>(_v) = isAnimated(); break;
        case 5: *reinterpret_cast< int*>(_v) = period(); break;
        }
        _id -= 6;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setColor(*reinterpret_cast< QColor*>(_v)); break;
        case 1: setChecked(*reinterpret_cast< bool*>(_v)); break;
        case 2: setShape(*reinterpret_cast< Shape*>(_v)); break;
        case 3: setFrameWidth(*reinterpret_cast< int*>(_v)); break;
        case 4: setAnimated(*reinterpret_cast< bool*>(_v)); break;
        case 5: setPeriod(*reinterpret_cast< int*>(_v)); break;
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
void QwwLed::colorChanged(const QColor & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QwwLed::toggled(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QwwLed::clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
