/****************************************************************************
** Meta object code from reading C++ file 'qwwclearlineedit.h'
**
** Created: Sat Jun 29 09:35:03 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qwwclearlineedit/qwwclearlineedit.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qwwclearlineedit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QwwClearLineEdit[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      22,   18,   17,   17, 0x08,
      45,   17,   17,   17, 0x08,
      69,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QwwClearLineEdit[] = {
    "QwwClearLineEdit\0\0vis\0setButtonVisible(bool)\0"
    "_q_textChanged(QString)\0_q_clearRequested()\0"
};

void QwwClearLineEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QwwClearLineEdit *_t = static_cast<QwwClearLineEdit *>(_o);
        switch (_id) {
        case 0: _t->setButtonVisible((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->d_func()->_q_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->d_func()->_q_clearRequested(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QwwClearLineEdit::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QwwClearLineEdit::staticMetaObject = {
    { &QwwButtonLineEdit::staticMetaObject, qt_meta_stringdata_QwwClearLineEdit,
      qt_meta_data_QwwClearLineEdit, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QwwClearLineEdit::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QwwClearLineEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QwwClearLineEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QwwClearLineEdit))
        return static_cast<void*>(const_cast< QwwClearLineEdit*>(this));
    return QwwButtonLineEdit::qt_metacast(_clname);
}

int QwwClearLineEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QwwButtonLineEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
