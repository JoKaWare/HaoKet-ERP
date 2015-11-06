/****************************************************************************
** Meta object code from reading C++ file 'qwwrichtextbutton.h'
**
** Created: Sat Jun 29 09:35:10 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qwwrichtextbutton/qwwrichtextbutton.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qwwrichtextbutton.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QwwRichTextButton[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       2,   34, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x0a,
      38,   36,   18,   18, 0x0a,
      55,   18,   18,   18, 0x08,
      86,   18,   18,   18, 0x08,

 // properties: name, type, flags
     117,  109, 0x0a095003,
     122,  109, 0x0a195103,

       0        // eod
};

static const char qt_meta_stringdata_QwwRichTextButton[] = {
    "QwwRichTextButton\0\0setHtml(QString)\0"
    "t\0setText(QString)\0_q_documentSizeChanged(QSizeF)\0"
    "_q_documentDestroyed()\0QString\0text\0"
    "html\0"
};

void QwwRichTextButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QwwRichTextButton *_t = static_cast<QwwRichTextButton *>(_o);
        switch (_id) {
        case 0: _t->setHtml((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->setText((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->d_func()->_q_documentSizeChanged((*reinterpret_cast< const QSizeF(*)>(_a[1]))); break;
        case 3: _t->d_func()->_q_documentDestroyed(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QwwRichTextButton::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QwwRichTextButton::staticMetaObject = {
    { &QAbstractButton::staticMetaObject, qt_meta_stringdata_QwwRichTextButton,
      qt_meta_data_QwwRichTextButton, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QwwRichTextButton::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QwwRichTextButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QwwRichTextButton::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QwwRichTextButton))
        return static_cast<void*>(const_cast< QwwRichTextButton*>(this));
    if (!strcmp(_clname, "QwwPrivatable"))
        return static_cast< QwwPrivatable*>(const_cast< QwwRichTextButton*>(this));
    return QAbstractButton::qt_metacast(_clname);
}

int QwwRichTextButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = html(); break;
        case 1: *reinterpret_cast< QString*>(_v) = html(); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setHtml(*reinterpret_cast< QString*>(_v)); break;
        case 1: setHtml(*reinterpret_cast< QString*>(_v)); break;
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
QT_END_MOC_NAMESPACE
