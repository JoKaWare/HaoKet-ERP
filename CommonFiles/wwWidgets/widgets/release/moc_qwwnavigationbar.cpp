/****************************************************************************
** Meta object code from reading C++ file 'qwwnavigationbar.h'
**
** Created: Sat Jun 29 09:35:04 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qwwnavigationbar/qwwnavigationbar.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qwwnavigationbar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QwwNavigationBar[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       2,   59, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x05,
      43,   17,   17,   17, 0x05,
      71,   17,   17,   17, 0x05,
      96,   17,   17,   17, 0x05,
     133,  126,   17,   17, 0x05,
     165,  126,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
     194,   17,   17,   17, 0x0a,
     215,   17,   17,   17, 0x0a,
     241,   17,   17,   17, 0x08,

 // properties: name, type, flags
     264,  260, 0x02095103,
     282,  277, 0x01095103,

       0        // eod
};

static const char qt_meta_stringdata_QwwNavigationBar[] = {
    "QwwNavigationBar\0\0currentIndexChanged(int)\0"
    "widgetLabelChanged(QString)\0"
    "widgetIconChanged(QIcon)\0"
    "topWidgetVisibleChanged(bool)\0index,\0"
    "widgetLabelChanged(int,QString)\0"
    "widgetIconChanged(int,QIcon)\0"
    "setCurrentIndex(int)\0setTopWidgetVisible(bool)\0"
    "_q_buttonClicked()\0int\0currentIndex\0"
    "bool\0topWidgetVisible\0"
};

void QwwNavigationBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QwwNavigationBar *_t = static_cast<QwwNavigationBar *>(_o);
        switch (_id) {
        case 0: _t->currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->widgetLabelChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->widgetIconChanged((*reinterpret_cast< const QIcon(*)>(_a[1]))); break;
        case 3: _t->topWidgetVisibleChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->widgetLabelChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 5: _t->widgetIconChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QIcon(*)>(_a[2]))); break;
        case 6: _t->setCurrentIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->setTopWidgetVisible((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->d_func()->_q_buttonClicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QwwNavigationBar::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QwwNavigationBar::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QwwNavigationBar,
      qt_meta_data_QwwNavigationBar, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QwwNavigationBar::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QwwNavigationBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QwwNavigationBar::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QwwNavigationBar))
        return static_cast<void*>(const_cast< QwwNavigationBar*>(this));
    if (!strcmp(_clname, "QwwPrivatable"))
        return static_cast< QwwPrivatable*>(const_cast< QwwNavigationBar*>(this));
    return QWidget::qt_metacast(_clname);
}

int QwwNavigationBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = currentIndex(); break;
        case 1: *reinterpret_cast< bool*>(_v) = topWidgetIsVisible(); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setCurrentIndex(*reinterpret_cast< int*>(_v)); break;
        case 1: setTopWidgetVisible(*reinterpret_cast< bool*>(_v)); break;
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
void QwwNavigationBar::currentIndexChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QwwNavigationBar::widgetLabelChanged(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QwwNavigationBar::widgetIconChanged(const QIcon & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QwwNavigationBar::topWidgetVisibleChanged(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void QwwNavigationBar::widgetLabelChanged(int _t1, const QString & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void QwwNavigationBar::widgetIconChanged(int _t1, const QIcon & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
