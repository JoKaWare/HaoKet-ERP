/****************************************************************************
** Meta object code from reading C++ file 'qwwcolorcomboboxiface.h'
**
** Created: Sat Jun 29 09:35:20 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qwwcolorcomboboxiface.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qwwcolorcomboboxiface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QwwColorComboBoxIface[] = {

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

static const char qt_meta_stringdata_QwwColorComboBoxIface[] = {
    "QwwColorComboBoxIface\0"
};

void QwwColorComboBoxIface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData QwwColorComboBoxIface::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QwwColorComboBoxIface::staticMetaObject = {
    { &wwWidgetInterface::staticMetaObject, qt_meta_stringdata_QwwColorComboBoxIface,
      qt_meta_data_QwwColorComboBoxIface, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QwwColorComboBoxIface::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QwwColorComboBoxIface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QwwColorComboBoxIface::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QwwColorComboBoxIface))
        return static_cast<void*>(const_cast< QwwColorComboBoxIface*>(this));
    if (!strcmp(_clname, "com.trolltech.Qt.Designer.CustomWidget"))
        return static_cast< QDesignerCustomWidgetInterface*>(const_cast< QwwColorComboBoxIface*>(this));
    return wwWidgetInterface::qt_metacast(_clname);
}

int QwwColorComboBoxIface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = wwWidgetInterface::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_QwwColorComboBoxTaskMenuExtension[] = {

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
      35,   34,   34,   34, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QwwColorComboBoxTaskMenuExtension[] = {
    "QwwColorComboBoxTaskMenuExtension\0\0"
    "mySlot()\0"
};

void QwwColorComboBoxTaskMenuExtension::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QwwColorComboBoxTaskMenuExtension *_t = static_cast<QwwColorComboBoxTaskMenuExtension *>(_o);
        switch (_id) {
        case 0: _t->mySlot(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData QwwColorComboBoxTaskMenuExtension::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QwwColorComboBoxTaskMenuExtension::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QwwColorComboBoxTaskMenuExtension,
      qt_meta_data_QwwColorComboBoxTaskMenuExtension, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QwwColorComboBoxTaskMenuExtension::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QwwColorComboBoxTaskMenuExtension::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QwwColorComboBoxTaskMenuExtension::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QwwColorComboBoxTaskMenuExtension))
        return static_cast<void*>(const_cast< QwwColorComboBoxTaskMenuExtension*>(this));
    if (!strcmp(_clname, "QDesignerTaskMenuExtension"))
        return static_cast< QDesignerTaskMenuExtension*>(const_cast< QwwColorComboBoxTaskMenuExtension*>(this));
    if (!strcmp(_clname, "com.trolltech.Qt.Designer.TaskMenu"))
        return static_cast< QDesignerTaskMenuExtension*>(const_cast< QwwColorComboBoxTaskMenuExtension*>(this));
    return QObject::qt_metacast(_clname);
}

int QwwColorComboBoxTaskMenuExtension::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
