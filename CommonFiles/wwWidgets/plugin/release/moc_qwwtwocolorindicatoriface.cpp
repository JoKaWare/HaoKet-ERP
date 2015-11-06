/****************************************************************************
** Meta object code from reading C++ file 'qwwtwocolorindicatoriface.h'
**
** Created: Sat Jun 29 09:35:21 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qwwtwocolorindicatoriface.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qwwtwocolorindicatoriface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QwwTwoColorIndicatorIface[] = {

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

static const char qt_meta_stringdata_QwwTwoColorIndicatorIface[] = {
    "QwwTwoColorIndicatorIface\0"
};

void QwwTwoColorIndicatorIface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData QwwTwoColorIndicatorIface::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QwwTwoColorIndicatorIface::staticMetaObject = {
    { &wwWidgetInterface::staticMetaObject, qt_meta_stringdata_QwwTwoColorIndicatorIface,
      qt_meta_data_QwwTwoColorIndicatorIface, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QwwTwoColorIndicatorIface::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QwwTwoColorIndicatorIface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QwwTwoColorIndicatorIface::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QwwTwoColorIndicatorIface))
        return static_cast<void*>(const_cast< QwwTwoColorIndicatorIface*>(this));
    if (!strcmp(_clname, "com.trolltech.Qt.Designer.CustomWidget"))
        return static_cast< QDesignerCustomWidgetInterface*>(const_cast< QwwTwoColorIndicatorIface*>(this));
    return wwWidgetInterface::qt_metacast(_clname);
}

int QwwTwoColorIndicatorIface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = wwWidgetInterface::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_QwwTwoColorIndicatorTaskMenuExtension[] = {

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
      39,   38,   38,   38, 0x08,
      48,   38,   38,   38, 0x08,
      57,   38,   38,   38, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QwwTwoColorIndicatorTaskMenuExtension[] = {
    "QwwTwoColorIndicatorTaskMenuExtension\0"
    "\0editBg()\0editFg()\0swap()\0"
};

void QwwTwoColorIndicatorTaskMenuExtension::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QwwTwoColorIndicatorTaskMenuExtension *_t = static_cast<QwwTwoColorIndicatorTaskMenuExtension *>(_o);
        switch (_id) {
        case 0: _t->editBg(); break;
        case 1: _t->editFg(); break;
        case 2: _t->swap(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData QwwTwoColorIndicatorTaskMenuExtension::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QwwTwoColorIndicatorTaskMenuExtension::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QwwTwoColorIndicatorTaskMenuExtension,
      qt_meta_data_QwwTwoColorIndicatorTaskMenuExtension, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QwwTwoColorIndicatorTaskMenuExtension::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QwwTwoColorIndicatorTaskMenuExtension::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QwwTwoColorIndicatorTaskMenuExtension::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QwwTwoColorIndicatorTaskMenuExtension))
        return static_cast<void*>(const_cast< QwwTwoColorIndicatorTaskMenuExtension*>(this));
    if (!strcmp(_clname, "QDesignerTaskMenuExtension"))
        return static_cast< QDesignerTaskMenuExtension*>(const_cast< QwwTwoColorIndicatorTaskMenuExtension*>(this));
    if (!strcmp(_clname, "com.trolltech.Qt.Designer.TaskMenu"))
        return static_cast< QDesignerTaskMenuExtension*>(const_cast< QwwTwoColorIndicatorTaskMenuExtension*>(this));
    return QObject::qt_metacast(_clname);
}

int QwwTwoColorIndicatorTaskMenuExtension::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
