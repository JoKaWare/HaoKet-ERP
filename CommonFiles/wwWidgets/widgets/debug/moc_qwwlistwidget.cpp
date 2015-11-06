/****************************************************************************
** Meta object code from reading C++ file 'qwwlistwidget.h'
**
** Created: Sat Jun 29 09:35:09 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qwwlistwidget/qwwlistwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qwwlistwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QwwListWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x05,
      38,   14,   14,   14, 0x05,
      62,   14,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      84,   14,   14,   14, 0x0a,
     102,   14,   14,   14, 0x0a,
     118,   14,   14,   14, 0x0a,
     134,   14,   14,   14, 0x0a,
     153,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QwwListWidget[] = {
    "QwwListWidget\0\0currentAvailable(bool)\0"
    "moveDownAvailable(bool)\0moveUpAvailable(bool)\0"
    "moveCurrentDown()\0moveCurrentUp()\0"
    "removeCurrent()\0setCurrentRow(int)\0"
    "_q_curCh(QListWidgetItem*)\0"
};

void QwwListWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QwwListWidget *_t = static_cast<QwwListWidget *>(_o);
        switch (_id) {
        case 0: _t->currentAvailable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->moveDownAvailable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->moveUpAvailable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->moveCurrentDown(); break;
        case 4: _t->moveCurrentUp(); break;
        case 5: _t->removeCurrent(); break;
        case 6: _t->setCurrentRow((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->d_func()->_q_curCh((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QwwListWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QwwListWidget::staticMetaObject = {
    { &QListWidget::staticMetaObject, qt_meta_stringdata_QwwListWidget,
      qt_meta_data_QwwListWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QwwListWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QwwListWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QwwListWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QwwListWidget))
        return static_cast<void*>(const_cast< QwwListWidget*>(this));
    if (!strcmp(_clname, "QwwPrivatable"))
        return static_cast< QwwPrivatable*>(const_cast< QwwListWidget*>(this));
    return QListWidget::qt_metacast(_clname);
}

int QwwListWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QListWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void QwwListWidget::currentAvailable(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QwwListWidget::moveDownAvailable(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QwwListWidget::moveUpAvailable(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
