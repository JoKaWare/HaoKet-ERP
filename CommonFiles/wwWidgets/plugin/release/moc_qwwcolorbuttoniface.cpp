/****************************************************************************
** Meta object code from reading C++ file 'qwwcolorbuttoniface.h'
**
** Created: Sat Jun 29 09:35:20 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qwwcolorbuttoniface.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qwwcolorbuttoniface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QwwColorButtonIface[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_QwwColorButtonIface[] = {
    "QwwColorButtonIface\0"
};

void QwwColorButtonIface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData QwwColorButtonIface::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QwwColorButtonIface::staticMetaObject = {
    { &wwWidgetInterface::staticMetaObject, qt_meta_stringdata_QwwColorButtonIface,
      qt_meta_data_QwwColorButtonIface, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QwwColorButtonIface::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QwwColorButtonIface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QwwColorButtonIface::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QwwColorButtonIface))
        return static_cast<void*>(const_cast< QwwColorButtonIface*>(this));
    if (!strcmp(_clname, "com.trolltech.Qt.Designer.CustomWidget"))
        return static_cast< QDesignerCustomWidgetInterface*>(const_cast< QwwColorButtonIface*>(this));
    return wwWidgetInterface::qt_metacast(_clname);
}

int QwwColorButtonIface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = wwWidgetInterface::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_QwwColorButtonTaskMenuExtension[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      33,   32,   32,   32, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QwwColorButtonTaskMenuExtension[] = {
    "QwwColorButtonTaskMenuExtension\0\0"
    "mySlot()\0"
};

void QwwColorButtonTaskMenuExtension::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QwwColorButtonTaskMenuExtension *_t = static_cast<QwwColorButtonTaskMenuExtension *>(_o);
        switch (_id) {
        case 0: _t->mySlot(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData QwwColorButtonTaskMenuExtension::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QwwColorButtonTaskMenuExtension::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QwwColorButtonTaskMenuExtension,
      qt_meta_data_QwwColorButtonTaskMenuExtension, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QwwColorButtonTaskMenuExtension::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QwwColorButtonTaskMenuExtension::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QwwColorButtonTaskMenuExtension::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QwwColorButtonTaskMenuExtension))
        return static_cast<void*>(const_cast< QwwColorButtonTaskMenuExtension*>(this));
    if (!strcmp(_clname, "QDesignerTaskMenuExtension"))
        return static_cast< QDesignerTaskMenuExtension*>(const_cast< QwwColorButtonTaskMenuExtension*>(this));
    if (!strcmp(_clname, "com.trolltech.Qt.Designer.TaskMenu"))
        return static_cast< QDesignerTaskMenuExtension*>(const_cast< QwwColorButtonTaskMenuExtension*>(this));
    return QObject::qt_metacast(_clname);
}

int QwwColorButtonTaskMenuExtension::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
