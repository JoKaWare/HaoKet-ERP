/****************************************************************************
** Meta object code from reading C++ file 'qwwloginbox.h'
**
** Created: Sat Jun 29 09:35:04 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qwwloginbox/qwwloginbox.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qwwloginbox.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QwwLoginBox[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       6,   29, // properties
       1,   47, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x0a,
      40,   30,   12,   12, 0x0a,
      70,   65,   12,   12, 0x2a,

 // properties: name, type, flags
      94,   87, 0x0009510b,
     109,  101, 0x0a095103,
     118,  114, 0x02095103,
      65,  101, 0x0a095001,
     128,  123, 0x01095103,
     145,  123, 0x01095103,

 // enums: name, flags, count, data
      87, 0x1,    8,   51,

 // enum data: key, value
     158, uint(QwwLoginBox::NoFields),
     167, uint(QwwLoginBox::HostField),
     177, uint(QwwLoginBox::PortField),
     187, uint(QwwLoginBox::UserField),
     197, uint(QwwLoginBox::PasswordField),
     211, uint(QwwLoginBox::RepeatPasswordField),
     231, uint(QwwLoginBox::RememberPasswordField),
     253, uint(QwwLoginBox::ProxyField),

       0        // eod
};

static const char qt_meta_stringdata_QwwLoginBox[] = {
    "QwwLoginBox\0\0setHost(QString)\0user,pass\0"
    "setUser(QString,QString)\0user\0"
    "setUser(QString)\0Fields\0fields\0QString\0"
    "host\0int\0port\0bool\0rememberPassword\0"
    "proxyEnabled\0NoFields\0HostField\0"
    "PortField\0UserField\0PasswordField\0"
    "RepeatPasswordField\0RememberPasswordField\0"
    "ProxyField\0"
};

void QwwLoginBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QwwLoginBox *_t = static_cast<QwwLoginBox *>(_o);
        switch (_id) {
        case 0: _t->setHost((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->setUser((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: _t->setUser((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QwwLoginBox::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QwwLoginBox::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QwwLoginBox,
      qt_meta_data_QwwLoginBox, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QwwLoginBox::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QwwLoginBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QwwLoginBox::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QwwLoginBox))
        return static_cast<void*>(const_cast< QwwLoginBox*>(this));
    if (!strcmp(_clname, "QwwPrivatable"))
        return static_cast< QwwPrivatable*>(const_cast< QwwLoginBox*>(this));
    return QWidget::qt_metacast(_clname);
}

int QwwLoginBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<int*>(_v) = QFlag(fields()); break;
        case 1: *reinterpret_cast< QString*>(_v) = host(); break;
        case 2: *reinterpret_cast< int*>(_v) = port(); break;
        case 3: *reinterpret_cast< QString*>(_v) = user(); break;
        case 4: *reinterpret_cast< bool*>(_v) = rememberPassword(); break;
        case 5: *reinterpret_cast< bool*>(_v) = proxyIsEnabled(); break;
        }
        _id -= 6;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setFields(QFlag(*reinterpret_cast<int*>(_v))); break;
        case 1: setHost(*reinterpret_cast< QString*>(_v)); break;
        case 2: setPort(*reinterpret_cast< int*>(_v)); break;
        case 4: setRememberPassword(*reinterpret_cast< bool*>(_v)); break;
        case 5: setProxyEnabled(*reinterpret_cast< bool*>(_v)); break;
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
QT_END_MOC_NAMESPACE
