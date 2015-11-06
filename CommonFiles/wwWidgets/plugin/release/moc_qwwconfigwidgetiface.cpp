/****************************************************************************
** Meta object code from reading C++ file 'qwwconfigwidgetiface.h'
**
** Created: Sat Jun 29 09:35:20 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qwwconfigwidgetiface.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qwwconfigwidgetiface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QwwConfigWidgetIface[] = {

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
      28,   22,   21,   21, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QwwConfigWidgetIface[] = {
    "QwwConfigWidgetIface\0\0index\0"
    "currentIndexChanged(int)\0"
};

void QwwConfigWidgetIface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QwwConfigWidgetIface *_t = static_cast<QwwConfigWidgetIface *>(_o);
        switch (_id) {
        case 0: _t->currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QwwConfigWidgetIface::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QwwConfigWidgetIface::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QwwConfigWidgetIface,
      qt_meta_data_QwwConfigWidgetIface, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QwwConfigWidgetIface::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QwwConfigWidgetIface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QwwConfigWidgetIface::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QwwConfigWidgetIface))
        return static_cast<void*>(const_cast< QwwConfigWidgetIface*>(this));
    if (!strcmp(_clname, "QDesignerCustomWidgetInterface"))
        return static_cast< QDesignerCustomWidgetInterface*>(const_cast< QwwConfigWidgetIface*>(this));
    if (!strcmp(_clname, "com.trolltech.Qt.Designer.CustomWidget"))
        return static_cast< QDesignerCustomWidgetInterface*>(const_cast< QwwConfigWidgetIface*>(this));
    return QObject::qt_metacast(_clname);
}

int QwwConfigWidgetIface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
static const uint qt_meta_data_QwwConfigWidgetContainerExtension[] = {

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

static const char qt_meta_stringdata_QwwConfigWidgetContainerExtension[] = {
    "QwwConfigWidgetContainerExtension\0"
};

void QwwConfigWidgetContainerExtension::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData QwwConfigWidgetContainerExtension::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QwwConfigWidgetContainerExtension::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QwwConfigWidgetContainerExtension,
      qt_meta_data_QwwConfigWidgetContainerExtension, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QwwConfigWidgetContainerExtension::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QwwConfigWidgetContainerExtension::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QwwConfigWidgetContainerExtension::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QwwConfigWidgetContainerExtension))
        return static_cast<void*>(const_cast< QwwConfigWidgetContainerExtension*>(this));
    if (!strcmp(_clname, "QDesignerContainerExtension"))
        return static_cast< QDesignerContainerExtension*>(const_cast< QwwConfigWidgetContainerExtension*>(this));
    if (!strcmp(_clname, "com.trolltech.Qt.Designer.Container"))
        return static_cast< QDesignerContainerExtension*>(const_cast< QwwConfigWidgetContainerExtension*>(this));
    return QObject::qt_metacast(_clname);
}

int QwwConfigWidgetContainerExtension::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_QwwConfigWidgetSheetExtension[] = {

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

static const char qt_meta_stringdata_QwwConfigWidgetSheetExtension[] = {
    "QwwConfigWidgetSheetExtension\0"
};

void QwwConfigWidgetSheetExtension::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData QwwConfigWidgetSheetExtension::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QwwConfigWidgetSheetExtension::staticMetaObject = {
    { &wwSheetExtension::staticMetaObject, qt_meta_stringdata_QwwConfigWidgetSheetExtension,
      qt_meta_data_QwwConfigWidgetSheetExtension, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QwwConfigWidgetSheetExtension::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QwwConfigWidgetSheetExtension::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QwwConfigWidgetSheetExtension::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QwwConfigWidgetSheetExtension))
        return static_cast<void*>(const_cast< QwwConfigWidgetSheetExtension*>(this));
    if (!strcmp(_clname, "com.trolltech.Qt.Designer.PropertySheet"))
        return static_cast< QDesignerPropertySheetExtension*>(const_cast< QwwConfigWidgetSheetExtension*>(this));
    return wwSheetExtension::qt_metacast(_clname);
}

int QwwConfigWidgetSheetExtension::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = wwSheetExtension::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
