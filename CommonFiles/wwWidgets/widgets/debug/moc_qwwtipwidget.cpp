/****************************************************************************
** Meta object code from reading C++ file 'qwwtipwidget.h'
**
** Created: Sat Jun 29 09:35:10 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qwwtipwidget/qwwtipwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qwwtipwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QwwTipWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       6,   79, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x05,
      30,   13,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      39,   13,   13,   13, 0x0a,
      49,   13,   13,   13, 0x0a,
      59,   13,   13,   13, 0x0a,
      80,   13,   13,   13, 0x0a,
     102,   13,   13,   13, 0x0a,
     123,   13,   13,   13, 0x0a,
     145,   13,   13,   13, 0x0a,
     166,   13,   13,   13, 0x0a,
     201,   13,   13,   13, 0x0a,
     222,   13,   13,   13, 0x0a,
     241,   13,   13,   13, 0x08,

 // properties: name, type, flags
     265,  251, 0x0009510b,
     287,  282, 0x01095103,
     300,  282, 0x01095103,
     325,  313, 0x0b095103,
     334,  330, 0x02095103,
     345,  282, 0x01095103,

       0        // eod
};

static const char qt_meta_stringdata_QwwTipWidget[] = {
    "QwwTipWidget\0\0tipChanged(int)\0closed()\0"
    "nextTip()\0prevTip()\0setTipsEnabled(bool)\0"
    "setCheckVisible(bool)\0setCheckHidden(bool)\0"
    "setCloseVisible(bool)\0setCloseHidden(bool)\0"
    "setCanvasFrameShape(QFrame::Shape)\0"
    "setTips(QStringList)\0setCurrentTip(int)\0"
    "showTip()\0QFrame::Shape\0canvasFrameShape\0"
    "bool\0checkVisible\0closeVisible\0"
    "QStringList\0tips\0int\0currentTip\0"
    "tipsEnabled\0"
};

void QwwTipWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QwwTipWidget *_t = static_cast<QwwTipWidget *>(_o);
        switch (_id) {
        case 0: _t->tipChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->closed(); break;
        case 2: _t->nextTip(); break;
        case 3: _t->prevTip(); break;
        case 4: _t->setTipsEnabled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->setCheckVisible((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->setCheckHidden((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->setCloseVisible((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->setCloseHidden((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->setCanvasFrameShape((*reinterpret_cast< QFrame::Shape(*)>(_a[1]))); break;
        case 10: _t->setTips((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 11: _t->setCurrentTip((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->d_func()->showTip(); break;
        default: ;
        }
    }
}

#ifdef Q_NO_DATA_RELOCATION
static const QMetaObjectAccessor qt_meta_extradata_QwwTipWidget[] = {
        QFrame::getStaticMetaObject,
#else
static const QMetaObject *qt_meta_extradata_QwwTipWidget[] = {
        &QFrame::staticMetaObject,
#endif //Q_NO_DATA_RELOCATION
    0
};

const QMetaObjectExtraData QwwTipWidget::staticMetaObjectExtraData = {
    qt_meta_extradata_QwwTipWidget,  qt_static_metacall 
};

const QMetaObject QwwTipWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QwwTipWidget,
      qt_meta_data_QwwTipWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QwwTipWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QwwTipWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QwwTipWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QwwTipWidget))
        return static_cast<void*>(const_cast< QwwTipWidget*>(this));
    if (!strcmp(_clname, "QwwPrivatable"))
        return static_cast< QwwPrivatable*>(const_cast< QwwTipWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int QwwTipWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
        case 0: *reinterpret_cast< QFrame::Shape*>(_v) = canvasFrameShape(); break;
        case 1: *reinterpret_cast< bool*>(_v) = checkIsVisible(); break;
        case 2: *reinterpret_cast< bool*>(_v) = closeIsVisible(); break;
        case 3: *reinterpret_cast< QStringList*>(_v) = tips(); break;
        case 4: *reinterpret_cast< int*>(_v) = currentTip(); break;
        case 5: *reinterpret_cast< bool*>(_v) = tipsEnabled(); break;
        }
        _id -= 6;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setCanvasFrameShape(*reinterpret_cast< QFrame::Shape*>(_v)); break;
        case 1: setCheckVisible(*reinterpret_cast< bool*>(_v)); break;
        case 2: setCloseVisible(*reinterpret_cast< bool*>(_v)); break;
        case 3: setTips(*reinterpret_cast< QStringList*>(_v)); break;
        case 4: setCurrentTip(*reinterpret_cast< int*>(_v)); break;
        case 5: setTipsEnabled(*reinterpret_cast< bool*>(_v)); break;
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
void QwwTipWidget::tipChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QwwTipWidget::closed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
