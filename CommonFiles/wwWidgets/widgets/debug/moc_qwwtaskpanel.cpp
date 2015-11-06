/****************************************************************************
** Meta object code from reading C++ file 'qwwtaskpanel.h'
**
** Created: Sat Jun 29 09:35:10 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qwwtaskpanel/qwwtaskpanel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qwwtaskpanel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QwwTaskPanel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       3,   29, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      45,   39,   13,   13, 0x0a,
      68,   66,   13,   13, 0x0a,

 // properties: name, type, flags
      90,   86, 0x02495103,
     109,  103, 0x45095103,
     125,  120, 0x01095103,

 // properties: notify_signal_id
       0,
       0,
       0,

       0        // eod
};

static const char qt_meta_stringdata_QwwTaskPanel[] = {
    "QwwTaskPanel\0\0currentIndexChanged(int)\0"
    "index\0setCurrentIndex(int)\0a\0"
    "setAnimated(bool)\0int\0currentIndex\0"
    "QIcon\0toggleIcon\0bool\0animated\0"
};

void QwwTaskPanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QwwTaskPanel *_t = static_cast<QwwTaskPanel *>(_o);
        switch (_id) {
        case 0: _t->currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->setCurrentIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->setAnimated((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QwwTaskPanel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QwwTaskPanel::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QwwTaskPanel,
      qt_meta_data_QwwTaskPanel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QwwTaskPanel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QwwTaskPanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QwwTaskPanel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QwwTaskPanel))
        return static_cast<void*>(const_cast< QwwTaskPanel*>(this));
    return QWidget::qt_metacast(_clname);
}

int QwwTaskPanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
        case 0: *reinterpret_cast< int*>(_v) = currentIndex(); break;
        case 1: *reinterpret_cast< QIcon*>(_v) = toggleIcon(); break;
        case 2: *reinterpret_cast< bool*>(_v) = isAnimated(); break;
        }
        _id -= 3;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setCurrentIndex(*reinterpret_cast< int*>(_v)); break;
        case 1: setToggleIcon(*reinterpret_cast< QIcon*>(_v)); break;
        case 2: setAnimated(*reinterpret_cast< bool*>(_v)); break;
        }
        _id -= 3;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QwwTaskPanel::currentIndexChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
