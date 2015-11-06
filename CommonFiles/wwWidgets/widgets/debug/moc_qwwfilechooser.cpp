/****************************************************************************
** Meta object code from reading C++ file 'qwwfilechooser.h'
**
** Created: Sat Jun 29 09:35:09 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qwwfilechooser/qwwfilechooser.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qwwfilechooser.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QwwFileChooser[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       5,   24, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x0a,
      31,   29,   15,   15, 0x08,

 // properties: name, type, flags
      82,   55, 0x0009510b,
     119,   97, 0x0009510b,
     152,  128, 0x0009510b,
     168,  163, 0x01095103,
     197,  189, 0x0a095103,

 // enums: name, flags, count, data

 // enum data: key, value

       0        // eod
};

static const char qt_meta_stringdata_QwwFileChooser[] = {
    "QwwFileChooser\0\0chooseFile()\0s\0"
    "_q_textChanged(QString)\0"
    "QCompleter::CompletionMode\0completionMode\0"
    "QFileDialog::FileMode\0fileMode\0"
    "QFileDialog::AcceptMode\0acceptMode\0"
    "bool\0usesNativeFileDialog\0QString\0"
    "filter\0"
};

void QwwFileChooser::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QwwFileChooser *_t = static_cast<QwwFileChooser *>(_o);
        switch (_id) {
        case 0: _t->chooseFile(); break;
        case 1: _t->d_func()->_q_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

#ifdef Q_NO_DATA_RELOCATION
static const QMetaObjectAccessor qt_meta_extradata_QwwFileChooser[] = {
        QCompleter::getStaticMetaObject,
    QFileDialog::getStaticMetaObject,
#else
static const QMetaObject *qt_meta_extradata_QwwFileChooser[] = {
        &QCompleter::staticMetaObject,
    &QFileDialog::staticMetaObject,
#endif //Q_NO_DATA_RELOCATION
    0
};

const QMetaObjectExtraData QwwFileChooser::staticMetaObjectExtraData = {
    qt_meta_extradata_QwwFileChooser,  qt_static_metacall 
};

const QMetaObject QwwFileChooser::staticMetaObject = {
    { &QwwButtonLineEdit::staticMetaObject, qt_meta_stringdata_QwwFileChooser,
      qt_meta_data_QwwFileChooser, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QwwFileChooser::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QwwFileChooser::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QwwFileChooser::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QwwFileChooser))
        return static_cast<void*>(const_cast< QwwFileChooser*>(this));
    return QwwButtonLineEdit::qt_metacast(_clname);
}

int QwwFileChooser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QwwButtonLineEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QCompleter::CompletionMode*>(_v) = completionMode(); break;
        case 1: *reinterpret_cast< QFileDialog::FileMode*>(_v) = fileMode(); break;
        case 2: *reinterpret_cast< QFileDialog::AcceptMode*>(_v) = acceptMode(); break;
        case 3: *reinterpret_cast< bool*>(_v) = usesNativeFileDialog(); break;
        case 4: *reinterpret_cast< QString*>(_v) = filter(); break;
        }
        _id -= 5;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setCompletionMode(*reinterpret_cast< QCompleter::CompletionMode*>(_v)); break;
        case 1: setFileMode(*reinterpret_cast< QFileDialog::FileMode*>(_v)); break;
        case 2: setAcceptMode(*reinterpret_cast< QFileDialog::AcceptMode*>(_v)); break;
        case 3: setUsesNativeFileDialog(*reinterpret_cast< bool*>(_v)); break;
        case 4: setFilter(*reinterpret_cast< QString*>(_v)); break;
        }
        _id -= 5;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 5;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
