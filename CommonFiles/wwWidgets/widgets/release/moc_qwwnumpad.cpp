/****************************************************************************
** Meta object code from reading C++ file 'qwwnumpad.h'
**
** Created: Sat Jun 29 09:35:04 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qwwnumpad/qwwnumpad.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qwwnumpad.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QwwNumPad[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,
      30,   10,   10,   10, 0x05,
      50,   10,   10,   10, 0x05,
      64,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      89,   82,   10,   10, 0x0a,
     117,  115,   10,   10, 0x2a,
     139,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QwwNumPad[] = {
    "QwwNumPad\0\0numberClicked(int)\0"
    "keyClicked(QString)\0hashClicked()\0"
    "asteriskClicked()\0b,msec\0"
    "animateClick(QString,int)\0b\0"
    "animateClick(QString)\0_q_clicked(int)\0"
};

void QwwNumPad::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QwwNumPad *_t = static_cast<QwwNumPad *>(_o);
        switch (_id) {
        case 0: _t->numberClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->keyClicked((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->hashClicked(); break;
        case 3: _t->asteriskClicked(); break;
        case 4: _t->animateClick((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->animateClick((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->d_func()->_q_clicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QwwNumPad::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QwwNumPad::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QwwNumPad,
      qt_meta_data_QwwNumPad, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QwwNumPad::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QwwNumPad::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QwwNumPad::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QwwNumPad))
        return static_cast<void*>(const_cast< QwwNumPad*>(this));
    if (!strcmp(_clname, "QwwPrivatable"))
        return static_cast< QwwPrivatable*>(const_cast< QwwNumPad*>(this));
    return QWidget::qt_metacast(_clname);
}

int QwwNumPad::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void QwwNumPad::numberClicked(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QwwNumPad::keyClicked(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QwwNumPad::hashClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void QwwNumPad::asteriskClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
