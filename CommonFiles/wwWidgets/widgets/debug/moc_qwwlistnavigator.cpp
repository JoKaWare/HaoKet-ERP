/****************************************************************************
** Meta object code from reading C++ file 'qwwlistnavigator.h'
**
** Created: Sat Jun 29 09:35:09 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qwwlistnavigator/qwwlistnavigator.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qwwlistnavigator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QwwListNavigator[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       4,   84, // properties
       1,   96, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x05,
      26,   17,   17,   17, 0x05,
      37,   17,   17,   17, 0x05,
      44,   17,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
      53,   51,   17,   17, 0x0a,
      87,   85,   17,   17, 0x0a,
     106,   17,   17,   17, 0x0a,
     146,   17,   17,   17, 0x0a,
     156,   17,   17,   17, 0x0a,
     165,   17,   17,   17, 0x0a,
     178,   17,   17,   17, 0x0a,
     187,   17,   17,   17, 0x08,
     208,   17,   17,   17, 0x08,
     227,   17,   17,   17, 0x08,

 // properties: name, type, flags
     269,  253, 0x0009510b,
     289,  281, 0x0009510b,
     302,  297, 0x01095103,
     332,  312, 0x0009510b,

 // enums: name, flags, count, data
     281, 0x1,    6,  100,

 // enum data: key, value
     348, uint(QwwListNavigator::NoButtons),
     358, uint(QwwListNavigator::FirstButton),
     370, uint(QwwListNavigator::PrevButton),
     381, uint(QwwListNavigator::Slider),
     388, uint(QwwListNavigator::NextButton),
     399, uint(QwwListNavigator::LastButton),

       0        // eod
};

static const char qt_meta_stringdata_QwwListNavigator[] = {
    "QwwListNavigator\0\0first()\0previous()\0"
    "next()\0last()\0o\0setOrientation(Qt::Orientation)\0"
    "v\0setAutoRaise(bool)\0"
    "setToolButtonStyle(Qt::ToolButtonStyle)\0"
    "toFirst()\0toLast()\0toPrevious()\0"
    "toNext()\0_q_valueChanged(int)\0"
    "_q_updateLWRange()\0_q_disconnectListWidget()\0"
    "Qt::Orientation\0orientation\0Buttons\0"
    "buttons\0bool\0autoRaise\0Qt::ToolButtonStyle\0"
    "toolButtonStyle\0NoButtons\0FirstButton\0"
    "PrevButton\0Slider\0NextButton\0LastButton\0"
};

void QwwListNavigator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QwwListNavigator *_t = static_cast<QwwListNavigator *>(_o);
        switch (_id) {
        case 0: _t->first(); break;
        case 1: _t->previous(); break;
        case 2: _t->next(); break;
        case 3: _t->last(); break;
        case 4: _t->setOrientation((*reinterpret_cast< Qt::Orientation(*)>(_a[1]))); break;
        case 5: _t->setAutoRaise((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->setToolButtonStyle((*reinterpret_cast< Qt::ToolButtonStyle(*)>(_a[1]))); break;
        case 7: _t->toFirst(); break;
        case 8: _t->toLast(); break;
        case 9: _t->toPrevious(); break;
        case 10: _t->toNext(); break;
        case 11: _t->d_func()->_q_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->d_func()->_q_updateLWRange(); break;
        case 13: _t->d_func()->_q_disconnectListWidget(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QwwListNavigator::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QwwListNavigator::staticMetaObject = {
    { &QAbstractSlider::staticMetaObject, qt_meta_stringdata_QwwListNavigator,
      qt_meta_data_QwwListNavigator, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QwwListNavigator::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QwwListNavigator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QwwListNavigator::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QwwListNavigator))
        return static_cast<void*>(const_cast< QwwListNavigator*>(this));
    if (!strcmp(_clname, "QwwPrivatable"))
        return static_cast< QwwPrivatable*>(const_cast< QwwListNavigator*>(this));
    return QAbstractSlider::qt_metacast(_clname);
}

int QwwListNavigator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractSlider::qt_metacall(_c, _id, _a);
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
        case 0: *reinterpret_cast< Qt::Orientation*>(_v) = orientation(); break;
        case 1: *reinterpret_cast<int*>(_v) = QFlag(buttons()); break;
        case 2: *reinterpret_cast< bool*>(_v) = autoRaise(); break;
        case 3: *reinterpret_cast< Qt::ToolButtonStyle*>(_v) = toolButtonStyle(); break;
        }
        _id -= 4;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setOrientation(*reinterpret_cast< Qt::Orientation*>(_v)); break;
        case 1: setButtons(QFlag(*reinterpret_cast<int*>(_v))); break;
        case 2: setAutoRaise(*reinterpret_cast< bool*>(_v)); break;
        case 3: setToolButtonStyle(*reinterpret_cast< Qt::ToolButtonStyle*>(_v)); break;
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
void QwwListNavigator::first()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QwwListNavigator::previous()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void QwwListNavigator::next()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void QwwListNavigator::last()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
