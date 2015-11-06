/****************************************************************************
** Meta object code from reading C++ file 'qwwcolorcombobox.h'
**
** Created: Sat Jun 29 09:35:03 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qwwcolorcombobox/qwwcolorcombobox.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qwwcolorcombobox.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QwwColorComboBox[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       4,   34, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
      42,   36,   17,   17, 0x0a,
      66,   17,   17,   17, 0x08,
      84,   17,   17,   17, 0x08,

 // properties: name, type, flags
     106,  101, 0x01095103,
     129,  125, 0x02095001,
     147,  140, 0x43095001,
     172,  160, 0x0b095103,

       0        // eod
};

static const char qt_meta_stringdata_QwwColorComboBox[] = {
    "QwwColorComboBox\0\0activated(QColor)\0"
    "color\0setCurrentColor(QColor)\0"
    "_q_activated(int)\0_q_popupDialog()\0"
    "bool\0colorDialogEnabled\0int\0colorCount\0"
    "QColor\0currentColor\0QStringList\0colors\0"
};

void QwwColorComboBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QwwColorComboBox *_t = static_cast<QwwColorComboBox *>(_o);
        switch (_id) {
        case 0: _t->activated((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 1: _t->setCurrentColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 2: _t->d_func()->_q_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->d_func()->_q_popupDialog(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QwwColorComboBox::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QwwColorComboBox::staticMetaObject = {
    { &QComboBox::staticMetaObject, qt_meta_stringdata_QwwColorComboBox,
      qt_meta_data_QwwColorComboBox, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QwwColorComboBox::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QwwColorComboBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QwwColorComboBox::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QwwColorComboBox))
        return static_cast<void*>(const_cast< QwwColorComboBox*>(this));
    if (!strcmp(_clname, "QwwPrivatable"))
        return static_cast< QwwPrivatable*>(const_cast< QwwColorComboBox*>(this));
    return QComboBox::qt_metacast(_clname);
}

int QwwColorComboBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QComboBox::qt_metacall(_c, _id, _a);
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
        case 0: *reinterpret_cast< bool*>(_v) = isColorDialogEnabled(); break;
        case 1: *reinterpret_cast< int*>(_v) = colorCount(); break;
        case 2: *reinterpret_cast< QColor*>(_v) = currentColor(); break;
        case 3: *reinterpret_cast< QStringList*>(_v) = colors(); break;
        }
        _id -= 4;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setColorDialogEnabled(*reinterpret_cast< bool*>(_v)); break;
        case 3: setColors(*reinterpret_cast< QStringList*>(_v)); break;
        }
        _id -= 4;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QwwColorComboBox::activated(const QColor & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
