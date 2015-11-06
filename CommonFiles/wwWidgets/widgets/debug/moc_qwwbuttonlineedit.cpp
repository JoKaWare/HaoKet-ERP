/****************************************************************************
** Meta object code from reading C++ file 'qwwbuttonlineedit.h'
**
** Created: Sat Jun 29 09:35:10 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qwwbuttonlineedit/qwwbuttonlineedit.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qwwbuttonlineedit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QwwButtonLineEdit[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       6,   49, // properties
       1,   67, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x05,
      35,   18,   18,   18, 0x05,

 // slots: signature, parameters, type, tag, flags
      61,   18,   18,   18, 0x0a,
      80,   18,   18,   18, 0x0a,
      99,   18,   18,   18, 0x0a,
     114,   18,   18,   18, 0x0a,
     133,   18,   18,   18, 0x0a,

 // properties: name, type, flags
     162,  156, 0x45095103,
     172,  167, 0x01095103,
     191,  182, 0x0009510b,
     206,  167, 0x01095103,
     228,  220, 0x0a095103,
     251,  235, 0x0009510b,

 // enums: name, flags, count, data
     182, 0x0,    5,   71,

 // enum data: key, value
     269, uint(QwwButtonLineEdit::None),
     274, uint(QwwButtonLineEdit::RightOutside),
     287, uint(QwwButtonLineEdit::RightInside),
     299, uint(QwwButtonLineEdit::LeftOutside),
     311, uint(QwwButtonLineEdit::LeftInside),

       0        // eod
};

static const char qt_meta_stringdata_QwwButtonLineEdit[] = {
    "QwwButtonLineEdit\0\0buttonClicked()\0"
    "validatorChanged(QString)\0setRegExp(QString)\0"
    "setRegExp(QRegExp)\0setIcon(QIcon)\0"
    "setAutoRaise(bool)\0setButtonVisible(bool)\0"
    "QIcon\0icon\0bool\0autoRaise\0Position\0"
    "buttonPosition\0buttonVisible\0QString\0"
    "regExp\0Qt::FocusPolicy\0buttonFocusPolicy\0"
    "None\0RightOutside\0RightInside\0LeftOutside\0"
    "LeftInside\0"
};

void QwwButtonLineEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QwwButtonLineEdit *_t = static_cast<QwwButtonLineEdit *>(_o);
        switch (_id) {
        case 0: _t->buttonClicked(); break;
        case 1: _t->validatorChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->setRegExp((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->setRegExp((*reinterpret_cast< const QRegExp(*)>(_a[1]))); break;
        case 4: _t->setIcon((*reinterpret_cast< const QIcon(*)>(_a[1]))); break;
        case 5: _t->setAutoRaise((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->setButtonVisible((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QwwButtonLineEdit::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QwwButtonLineEdit::staticMetaObject = {
    { &QLineEdit::staticMetaObject, qt_meta_stringdata_QwwButtonLineEdit,
      qt_meta_data_QwwButtonLineEdit, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QwwButtonLineEdit::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QwwButtonLineEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QwwButtonLineEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QwwButtonLineEdit))
        return static_cast<void*>(const_cast< QwwButtonLineEdit*>(this));
    if (!strcmp(_clname, "QwwPrivatable"))
        return static_cast< QwwPrivatable*>(const_cast< QwwButtonLineEdit*>(this));
    return QLineEdit::qt_metacast(_clname);
}

int QwwButtonLineEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLineEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QIcon*>(_v) = icon(); break;
        case 1: *reinterpret_cast< bool*>(_v) = autoRaise(); break;
        case 2: *reinterpret_cast< Position*>(_v) = buttonPosition(); break;
        case 3: *reinterpret_cast< bool*>(_v) = buttonIsVisible(); break;
        case 4: *reinterpret_cast< QString*>(_v) = regExp(); break;
        case 5: *reinterpret_cast< Qt::FocusPolicy*>(_v) = buttonFocusPolicy(); break;
        }
        _id -= 6;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setIcon(*reinterpret_cast< QIcon*>(_v)); break;
        case 1: setAutoRaise(*reinterpret_cast< bool*>(_v)); break;
        case 2: setButtonPosition(*reinterpret_cast< Position*>(_v)); break;
        case 3: setButtonVisible(*reinterpret_cast< bool*>(_v)); break;
        case 4: setRegExp(*reinterpret_cast< QString*>(_v)); break;
        case 5: setButtonFocusPolicy(*reinterpret_cast< Qt::FocusPolicy*>(_v)); break;
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
void QwwButtonLineEdit::buttonClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QwwButtonLineEdit::validatorChanged(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
