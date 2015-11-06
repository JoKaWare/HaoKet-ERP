/****************************************************************************
** Meta object code from reading C++ file 'qwwnavigationbariface.h'
**
** Created: Sat Jun 29 09:35:21 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qwwnavigationbariface.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qwwnavigationbariface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QwwNavigationBarIface[] = {

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
      29,   23,   22,   22, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QwwNavigationBarIface[] = {
    "QwwNavigationBarIface\0\0index\0"
    "currentIndexChanged(int)\0"
};

void QwwNavigationBarIface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QwwNavigationBarIface *_t = static_cast<QwwNavigationBarIface *>(_o);
        switch (_id) {
        case 0: _t->currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QwwNavigationBarIface::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QwwNavigationBarIface::staticMetaObject = {
    { &wwWidgetInterface::staticMetaObject, qt_meta_stringdata_QwwNavigationBarIface,
      qt_meta_data_QwwNavigationBarIface, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QwwNavigationBarIface::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QwwNavigationBarIface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QwwNavigationBarIface::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QwwNavigationBarIface))
        return static_cast<void*>(const_cast< QwwNavigationBarIface*>(this));
    if (!strcmp(_clname, "com.trolltech.Qt.Designer.CustomWidget"))
        return static_cast< QDesignerCustomWidgetInterface*>(const_cast< QwwNavigationBarIface*>(this));
    return wwWidgetInterface::qt_metacast(_clname);
}

int QwwNavigationBarIface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = wwWidgetInterface::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
static const uint qt_meta_data_QwwNavigationBarContainerExtension[] = {

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

static const char qt_meta_stringdata_QwwNavigationBarContainerExtension[] = {
    "QwwNavigationBarContainerExtension\0"
};

void QwwNavigationBarContainerExtension::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData QwwNavigationBarContainerExtension::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QwwNavigationBarContainerExtension::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QwwNavigationBarContainerExtension,
      qt_meta_data_QwwNavigationBarContainerExtension, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QwwNavigationBarContainerExtension::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QwwNavigationBarContainerExtension::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QwwNavigationBarContainerExtension::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QwwNavigationBarContainerExtension))
        return static_cast<void*>(const_cast< QwwNavigationBarContainerExtension*>(this));
    if (!strcmp(_clname, "QDesignerContainerExtension"))
        return static_cast< QDesignerContainerExtension*>(const_cast< QwwNavigationBarContainerExtension*>(this));
    if (!strcmp(_clname, "com.trolltech.Qt.Designer.Container"))
        return static_cast< QDesignerContainerExtension*>(const_cast< QwwNavigationBarContainerExtension*>(this));
    return QObject::qt_metacast(_clname);
}

int QwwNavigationBarContainerExtension::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_QwwNavigationBarSheetExtension[] = {

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

static const char qt_meta_stringdata_QwwNavigationBarSheetExtension[] = {
    "QwwNavigationBarSheetExtension\0"
};

void QwwNavigationBarSheetExtension::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData QwwNavigationBarSheetExtension::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QwwNavigationBarSheetExtension::staticMetaObject = {
    { &wwSheetExtension::staticMetaObject, qt_meta_stringdata_QwwNavigationBarSheetExtension,
      qt_meta_data_QwwNavigationBarSheetExtension, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QwwNavigationBarSheetExtension::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QwwNavigationBarSheetExtension::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QwwNavigationBarSheetExtension::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QwwNavigationBarSheetExtension))
        return static_cast<void*>(const_cast< QwwNavigationBarSheetExtension*>(this));
    if (!strcmp(_clname, "com.trolltech.Qt.Designer.PropertySheet"))
        return static_cast< QDesignerPropertySheetExtension*>(const_cast< QwwNavigationBarSheetExtension*>(this));
    return wwSheetExtension::qt_metacast(_clname);
}

int QwwNavigationBarSheetExtension::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = wwSheetExtension::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
