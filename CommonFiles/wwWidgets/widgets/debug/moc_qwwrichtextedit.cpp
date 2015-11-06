/****************************************************************************
** Meta object code from reading C++ file 'qwwrichtextedit.h'
**
** Created: Sat Jun 29 09:35:10 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qwwrichtextedit/qwwrichtextedit.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qwwrichtextedit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QwwRichTextEdit[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       1,   69, // properties
       1,   72, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      19,   17,   16,   16, 0x0a,
      47,   45,   16,   16, 0x0a,
      61,   45,   16,   16, 0x0a,
      77,   45,   16,   16, 0x0a,
      96,   16,   16,   16, 0x0a,
     110,  108,   16,   16, 0x0a,
     125,   45,   16,   16, 0x0a,
     139,   16,   16,   16, 0x0a,
     160,  156,   16,   16, 0x0a,
     184,  180,   16,   16, 0x0a,
     225,   16,   16,   16, 0x0a,

 // properties: name, type, flags
     260,  252, 0x0009510b,

 // enums: name, flags, count, data
     252, 0x1,    6,   76,

 // enum data: key, value
     268, uint(QwwRichTextEdit::NoOptions),
     278, uint(QwwRichTextEdit::Style),
     284, uint(QwwRichTextEdit::Alignment),
     294, uint(QwwRichTextEdit::FontFamily),
     305, uint(QwwRichTextEdit::FontSize),
     314, uint(QwwRichTextEdit::Color),

       0        // eod
};

static const char qt_meta_stringdata_QwwRichTextEdit[] = {
    "QwwRichTextEdit\0\0a\0changeAlignment(QAction*)\0"
    "v\0setBold(bool)\0setItalic(bool)\0"
    "setUnderline(bool)\0setFont_h()\0f\0"
    "setFont(QFont)\0setList(bool)\0"
    "setColor(QColor)\0opt\0setOptions(Options)\0"
    "fmt\0updateCurrentCharFormat(QTextCharFormat)\0"
    "updateCurrentBlockFormat()\0Options\0"
    "options\0NoOptions\0Style\0Alignment\0"
    "FontFamily\0FontSize\0Color\0"
};

void QwwRichTextEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QwwRichTextEdit *_t = static_cast<QwwRichTextEdit *>(_o);
        switch (_id) {
        case 0: _t->changeAlignment((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 1: _t->setBold((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->setItalic((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->setUnderline((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->setFont_h(); break;
        case 5: _t->setFont((*reinterpret_cast< const QFont(*)>(_a[1]))); break;
        case 6: _t->setList((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->setColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 8: _t->setOptions((*reinterpret_cast< Options(*)>(_a[1]))); break;
        case 9: _t->updateCurrentCharFormat((*reinterpret_cast< const QTextCharFormat(*)>(_a[1]))); break;
        case 10: _t->updateCurrentBlockFormat(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QwwRichTextEdit::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QwwRichTextEdit::staticMetaObject = {
    { &QTextEdit::staticMetaObject, qt_meta_stringdata_QwwRichTextEdit,
      qt_meta_data_QwwRichTextEdit, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QwwRichTextEdit::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QwwRichTextEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QwwRichTextEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QwwRichTextEdit))
        return static_cast<void*>(const_cast< QwwRichTextEdit*>(this));
    return QTextEdit::qt_metacast(_clname);
}

int QwwRichTextEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTextEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<int*>(_v) = QFlag(options()); break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setOptions(QFlag(*reinterpret_cast<int*>(_v))); break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
