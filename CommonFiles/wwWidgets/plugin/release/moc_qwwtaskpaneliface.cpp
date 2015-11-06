/****************************************************************************
** Meta object code from reading C++ file 'qwwtaskpaneliface.h'
**
** Created: Sat Jun 29 09:35:21 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qwwtaskpaneliface.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qwwtaskpaneliface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QwwTaskPanelIface[] = {

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
      19,   18,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QwwTaskPanelIface[] = {
    "QwwTaskPanelIface\0\0currentIndexChanged(int)\0"
};

void QwwTaskPanelIface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QwwTaskPanelIface *_t = static_cast<QwwTaskPanelIface *>(_o);
        switch (_id) {
        case 0: _t->currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QwwTaskPanelIface::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QwwTaskPanelIface::staticMetaObject = {
    { &wwWidgetInterface::staticMetaObject, qt_meta_stringdata_QwwTaskPanelIface,
      qt_meta_data_QwwTaskPanelIface, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QwwTaskPanelIface::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QwwTaskPanelIface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QwwTaskPanelIface::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QwwTaskPanelIface))
        return static_cast<void*>(const_cast< QwwTaskPanelIface*>(this));
    if (!strcmp(_clname, "com.trolltech.Qt.Designer.CustomWidget"))
        return static_cast< QDesignerCustomWidgetInterface*>(const_cast< QwwTaskPanelIface*>(this));
    return wwWidgetInterface::qt_metacast(_clname);
}

int QwwTaskPanelIface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
static const uint qt_meta_data_QwwTaskPanelContainerExtension[] = {

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

static const char qt_meta_stringdata_QwwTaskPanelContainerExtension[] = {
    "QwwTaskPanelContainerExtension\0"
};

void QwwTaskPanelContainerExtension::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData QwwTaskPanelContainerExtension::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QwwTaskPanelContainerExtension::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QwwTaskPanelContainerExtension,
      qt_meta_data_QwwTaskPanelContainerExtension, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QwwTaskPanelContainerExtension::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QwwTaskPanelContainerExtension::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QwwTaskPanelContainerExtension::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QwwTaskPanelContainerExtension))
        return static_cast<void*>(const_cast< QwwTaskPanelContainerExtension*>(this));
    if (!strcmp(_clname, "QDesignerContainerExtension"))
        return static_cast< QDesignerContainerExtension*>(const_cast< QwwTaskPanelContainerExtension*>(this));
    if (!strcmp(_clname, "com.trolltech.Qt.Designer.Container"))
        return static_cast< QDesignerContainerExtension*>(const_cast< QwwTaskPanelContainerExtension*>(this));
    return QObject::qt_metacast(_clname);
}

int QwwTaskPanelContainerExtension::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_QwwTaskPanelSheetExtension[] = {

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

static const char qt_meta_stringdata_QwwTaskPanelSheetExtension[] = {
    "QwwTaskPanelSheetExtension\0"
};

void QwwTaskPanelSheetExtension::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData QwwTaskPanelSheetExtension::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QwwTaskPanelSheetExtension::staticMetaObject = {
    { &wwSheetExtension::staticMetaObject, qt_meta_stringdata_QwwTaskPanelSheetExtension,
      qt_meta_data_QwwTaskPanelSheetExtension, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QwwTaskPanelSheetExtension::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QwwTaskPanelSheetExtension::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QwwTaskPanelSheetExtension::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QwwTaskPanelSheetExtension))
        return static_cast<void*>(const_cast< QwwTaskPanelSheetExtension*>(this));
    if (!strcmp(_clname, "com.trolltech.Qt.Designer.PropertySheet"))
        return static_cast< QDesignerPropertySheetExtension*>(const_cast< QwwTaskPanelSheetExtension*>(this));
    return wwSheetExtension::qt_metacast(_clname);
}

int QwwTaskPanelSheetExtension::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = wwSheetExtension::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
