/****************************************************************************
** Meta object code from reading C++ file 'qwwconfigwidget.h'
**
** Created: Sat Jun 29 09:35:04 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qwwconfigwidget/qwwconfigwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qwwconfigwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QwwConfigWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       3,   79, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x05,
      42,   16,   16,   16, 0x05,
      51,   16,   16,   16, 0x05,
      65,   16,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
      81,   16,   16,   16, 0x0a,
     102,   16,   16,   16, 0x0a,
     129,  127,   16,   16, 0x0a,
     157,  155,   16,   16, 0x0a,
     181,  155,   16,   16, 0x0a,
     208,   16,   16,   16, 0x0a,
     215,   16,   16,   16, 0x0a,
     223,   16,   16,   16, 0x0a,
     233,   16,   16,   16, 0x0a,

 // properties: name, type, flags
     256,  252, 0x02095103,
     275,  269, 0x15095103,
     284,  252, 0x02095001,

       0        // eod
};

static const char qt_meta_stringdata_QwwConfigWidget[] = {
    "QwwConfigWidget\0\0currentIndexChanged(int)\0"
    "saving()\0applying(int)\0discarding(int)\0"
    "setCurrentIndex(int)\0setCurrentGroup(QString)\0"
    "w\0setCurrentGroup(QWidget*)\0,\0"
    "setGroupIcon(int,QIcon)\0"
    "setGroupLabel(int,QString)\0save()\0"
    "apply()\0discard()\0setIconSize(QSize)\0"
    "int\0currentIndex\0QSize\0iconSize\0count\0"
};

void QwwConfigWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QwwConfigWidget *_t = static_cast<QwwConfigWidget *>(_o);
        switch (_id) {
        case 0: _t->currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->saving(); break;
        case 2: _t->applying((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->discarding((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->setCurrentIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->setCurrentGroup((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->setCurrentGroup((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 7: _t->setGroupIcon((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QIcon(*)>(_a[2]))); break;
        case 8: _t->setGroupLabel((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 9: _t->save(); break;
        case 10: _t->apply(); break;
        case 11: _t->discard(); break;
        case 12: _t->setIconSize((*reinterpret_cast< const QSize(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QwwConfigWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QwwConfigWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QwwConfigWidget,
      qt_meta_data_QwwConfigWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QwwConfigWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QwwConfigWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QwwConfigWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QwwConfigWidget))
        return static_cast<void*>(const_cast< QwwConfigWidget*>(this));
    if (!strcmp(_clname, "QwwPrivatable"))
        return static_cast< QwwPrivatable*>(const_cast< QwwConfigWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int QwwConfigWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = currentIndex(); break;
        case 1: *reinterpret_cast< QSize*>(_v) = iconSize(); break;
        case 2: *reinterpret_cast< int*>(_v) = count(); break;
        }
        _id -= 3;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setCurrentIndex(*reinterpret_cast< int*>(_v)); break;
        case 1: setIconSize(*reinterpret_cast< QSize*>(_v)); break;
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
void QwwConfigWidget::currentIndexChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QwwConfigWidget::saving()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void QwwConfigWidget::applying(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QwwConfigWidget::discarding(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
