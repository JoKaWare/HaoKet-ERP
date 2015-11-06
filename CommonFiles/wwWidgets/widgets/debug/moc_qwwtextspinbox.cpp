/****************************************************************************
** Meta object code from reading C++ file 'qwwtextspinbox.h'
**
** Created: Sat Jun 29 09:35:10 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qwwtextspinbox/qwwtextspinbox.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qwwtextspinbox.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QwwTextSpinBox[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       1,   29, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      46,   44,   15,   15, 0x0a,
      70,   15,   15,   15, 0x0a,

 // properties: name, type, flags
      92,   80, 0x0b095103,

       0        // eod
};

static const char qt_meta_stringdata_QwwTextSpinBox[] = {
    "QwwTextSpinBox\0\0stringsChanged(QStringList)\0"
    "s\0setStrings(QStringList)\0strings()\0"
    "QStringList\0strings\0"
};

void QwwTextSpinBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QwwTextSpinBox *_t = static_cast<QwwTextSpinBox *>(_o);
        switch (_id) {
        case 0: _t->stringsChanged((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 1: _t->setStrings((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 2: _t->strings(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QwwTextSpinBox::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QwwTextSpinBox::staticMetaObject = {
    { &QSpinBox::staticMetaObject, qt_meta_stringdata_QwwTextSpinBox,
      qt_meta_data_QwwTextSpinBox, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QwwTextSpinBox::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QwwTextSpinBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QwwTextSpinBox::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QwwTextSpinBox))
        return static_cast<void*>(const_cast< QwwTextSpinBox*>(this));
    if (!strcmp(_clname, "QwwPrivatable"))
        return static_cast< QwwPrivatable*>(const_cast< QwwTextSpinBox*>(this));
    return QSpinBox::qt_metacast(_clname);
}

int QwwTextSpinBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSpinBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QStringList*>(_v) = strings(); break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setStrings(*reinterpret_cast< QStringList*>(_v)); break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QwwTextSpinBox::stringsChanged(const QStringList & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
