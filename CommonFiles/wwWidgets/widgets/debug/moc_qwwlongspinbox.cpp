/****************************************************************************
** Meta object code from reading C++ file 'qwwlongspinbox.h'
**
** Created: Sat Jun 29 09:35:09 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qwwlongspinbox/qwwlongspinbox.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qwwlongspinbox.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QwwLongSpinBox[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       6,   34, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   16,   15,   15, 0x05,
      47,   42,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      71,   69,   15,   15, 0x0a,
      93,   91,   15,   15, 0x08,

 // properties: name, type, flags
     133,  123, 0x04095103,
     141,  123, 0x04095103,
     149,  123, 0x04595103,
     163,  155, 0x0a095103,
     170,  155, 0x0a095103,
     177,  123, 0x04095103,

 // properties: notify_signal_id
       0,
       0,
       0,
       0,
       0,
       0,

       0        // eod
};

static const char qt_meta_stringdata_QwwLongSpinBox[] = {
    "QwwLongSpinBox\0\0i\0valueChanged(qlonglong)\0"
    "text\0valueChanged(QString)\0v\0"
    "setValue(qlonglong)\0t\0"
    "_q_editorTextChanged(QString)\0qlonglong\0"
    "minimum\0maximum\0value\0QString\0prefix\0"
    "suffix\0singleStep\0"
};

void QwwLongSpinBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QwwLongSpinBox *_t = static_cast<QwwLongSpinBox *>(_o);
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< qlonglong(*)>(_a[1]))); break;
        case 1: _t->valueChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->setValue((*reinterpret_cast< qlonglong(*)>(_a[1]))); break;
        case 3: _t->d_func()->_q_editorTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QwwLongSpinBox::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QwwLongSpinBox::staticMetaObject = {
    { &QAbstractSpinBox::staticMetaObject, qt_meta_stringdata_QwwLongSpinBox,
      qt_meta_data_QwwLongSpinBox, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QwwLongSpinBox::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QwwLongSpinBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QwwLongSpinBox::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QwwLongSpinBox))
        return static_cast<void*>(const_cast< QwwLongSpinBox*>(this));
    if (!strcmp(_clname, "QwwPrivatable"))
        return static_cast< QwwPrivatable*>(const_cast< QwwLongSpinBox*>(this));
    return QAbstractSpinBox::qt_metacast(_clname);
}

int QwwLongSpinBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractSpinBox::qt_metacall(_c, _id, _a);
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
        case 0: *reinterpret_cast< qlonglong*>(_v) = minimum(); break;
        case 1: *reinterpret_cast< qlonglong*>(_v) = maximum(); break;
        case 2: *reinterpret_cast< qlonglong*>(_v) = value(); break;
        case 3: *reinterpret_cast< QString*>(_v) = prefix(); break;
        case 4: *reinterpret_cast< QString*>(_v) = suffix(); break;
        case 5: *reinterpret_cast< qlonglong*>(_v) = singleStep(); break;
        }
        _id -= 6;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setMinimum(*reinterpret_cast< qlonglong*>(_v)); break;
        case 1: setMaximum(*reinterpret_cast< qlonglong*>(_v)); break;
        case 2: setValue(*reinterpret_cast< qlonglong*>(_v)); break;
        case 3: setPrefix(*reinterpret_cast< QString*>(_v)); break;
        case 4: setSuffix(*reinterpret_cast< QString*>(_v)); break;
        case 5: setSingleStep(*reinterpret_cast< qlonglong*>(_v)); break;
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
void QwwLongSpinBox::valueChanged(qlonglong _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QwwLongSpinBox::valueChanged(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
