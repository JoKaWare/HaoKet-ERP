/****************************************************************************
** Meta object code from reading C++ file 'colorlisteditor.h'
**
** Created: Sat Jun 29 09:35:24 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../colorlisteditor.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'colorlisteditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ColorListEditor[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x09,
      31,   16,   16,   16, 0x09,
      51,   16,   16,   16, 0x09,
      64,   16,   16,   16, 0x09,
      76,   16,   16,   16, 0x09,
      95,   16,   16,   16, 0x09,
     112,   16,   16,   16, 0x09,
     121,   16,   16,   16, 0x09,
     132,   16,   16,   16, 0x09,
     158,   16,   16,   16, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_ColorListEditor[] = {
    "ColorListEditor\0\0setColorMap()\0"
    "setStandardColors()\0clearModel()\0"
    "addNewRow()\0removeCurrentRow()\0"
    "chooseNewColor()\0moveUp()\0moveDown()\0"
    "updateFields(QModelIndex)\0updateText(QString)\0"
};

void ColorListEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ColorListEditor *_t = static_cast<ColorListEditor *>(_o);
        switch (_id) {
        case 0: _t->setColorMap(); break;
        case 1: _t->setStandardColors(); break;
        case 2: _t->clearModel(); break;
        case 3: _t->addNewRow(); break;
        case 4: _t->removeCurrentRow(); break;
        case 5: _t->chooseNewColor(); break;
        case 6: _t->moveUp(); break;
        case 7: _t->moveDown(); break;
        case 8: _t->updateFields((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 9: _t->updateText((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ColorListEditor::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ColorListEditor::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ColorListEditor,
      qt_meta_data_ColorListEditor, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ColorListEditor::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ColorListEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ColorListEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ColorListEditor))
        return static_cast<void*>(const_cast< ColorListEditor*>(this));
    return QDialog::qt_metacast(_clname);
}

int ColorListEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
