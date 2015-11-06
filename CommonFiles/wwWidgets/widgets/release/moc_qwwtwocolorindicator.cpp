/****************************************************************************
** Meta object code from reading C++ file 'qwwtwocolorindicator.h'
**
** Created: Sat Jun 29 09:35:05 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qwwtwocolorindicator/qwwtwocolorindicator.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qwwtwocolorindicator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QwwTwoColorIndicator[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       4,   64, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: signature, parameters, type, tag, flags
      22,   21,   21,   21, 0x05,
      40,   21,   21,   21, 0x05,
      58,   21,   21,   21, 0x05,
      70,   21,   21,   21, 0x05,
      82,   21,   21,   21, 0x05,
      94,   21,   21,   21, 0x05,

 // slots: signature, parameters, type, tag, flags
     106,   21,   21,   21, 0x0a,
     125,   21,   21,   21, 0x0a,
     144,   21,   21,   21, 0x0a,
     159,   21,   21,   21, 0x0a,

 // properties: name, type, flags
     182,  175, 0x43095103,
     190,  175, 0x43095103,
     203,  198, 0x01095103,
     210,  198, 0x01095103,

       0        // eod
};

static const char qt_meta_stringdata_QwwTwoColorIndicator[] = {
    "QwwTwoColorIndicator\0\0fgChanged(QColor)\0"
    "bgChanged(QColor)\0fgClicked()\0bgClicked()\0"
    "fgPressed()\0bgPressed()\0setFgColor(QColor)\0"
    "setBgColor(QColor)\0switchColors()\0"
    "setActive(bool)\0QColor\0fgColor\0bgColor\0"
    "bool\0active\0dragEnabled\0"
};

void QwwTwoColorIndicator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QwwTwoColorIndicator *_t = static_cast<QwwTwoColorIndicator *>(_o);
        switch (_id) {
        case 0: _t->fgChanged((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 1: _t->bgChanged((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 2: _t->fgClicked(); break;
        case 3: _t->bgClicked(); break;
        case 4: _t->fgPressed(); break;
        case 5: _t->bgPressed(); break;
        case 6: _t->setFgColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 7: _t->setBgColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 8: _t->switchColors(); break;
        case 9: _t->setActive((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QwwTwoColorIndicator::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QwwTwoColorIndicator::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QwwTwoColorIndicator,
      qt_meta_data_QwwTwoColorIndicator, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QwwTwoColorIndicator::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QwwTwoColorIndicator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QwwTwoColorIndicator::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QwwTwoColorIndicator))
        return static_cast<void*>(const_cast< QwwTwoColorIndicator*>(this));
    if (!strcmp(_clname, "QwwPrivatable"))
        return static_cast< QwwPrivatable*>(const_cast< QwwTwoColorIndicator*>(this));
    return QWidget::qt_metacast(_clname);
}

int QwwTwoColorIndicator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QColor*>(_v) = fgColor(); break;
        case 1: *reinterpret_cast< QColor*>(_v) = bgColor(); break;
        case 2: *reinterpret_cast< bool*>(_v) = isActive(); break;
        case 3: *reinterpret_cast< bool*>(_v) = dragEnabled(); break;
        }
        _id -= 4;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setFgColor(*reinterpret_cast< QColor*>(_v)); break;
        case 1: setBgColor(*reinterpret_cast< QColor*>(_v)); break;
        case 2: setActive(*reinterpret_cast< bool*>(_v)); break;
        case 3: setDragEnabled(*reinterpret_cast< bool*>(_v)); break;
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
void QwwTwoColorIndicator::fgChanged(const QColor & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QwwTwoColorIndicator::bgChanged(const QColor & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QwwTwoColorIndicator::fgClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void QwwTwoColorIndicator::bgClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void QwwTwoColorIndicator::fgPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void QwwTwoColorIndicator::bgPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}
QT_END_MOC_NAMESPACE
