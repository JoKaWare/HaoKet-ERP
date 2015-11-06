/****************************************************************************
** Meta object code from reading C++ file 'qwwtaskpanel_p.h'
**
** Created: Sat Jun 29 09:35:05 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qwwtaskpanel/qwwtaskpanel_p.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qwwtaskpanel_p.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TaskHeader[] = {

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

static const char qt_meta_stringdata_TaskHeader[] = {
    "TaskHeader\0"
};

void TaskHeader::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData TaskHeader::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TaskHeader::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_TaskHeader,
      qt_meta_data_TaskHeader, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TaskHeader::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TaskHeader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TaskHeader::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TaskHeader))
        return static_cast<void*>(const_cast< TaskHeader*>(this));
    return QFrame::qt_metacast(_clname);
}

int TaskHeader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_Task[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
       6,    5,    5,    5, 0x05,
      15,    5,    5,    5, 0x05,

 // slots: signature, parameters, type, tag, flags
      26,   24,    5,    5, 0x0a,
      40,    5,    5,    5, 0x08,
      53,    5,    5,    5, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Task[] = {
    "Task\0\0opened()\0closed()\0o\0setOpen(bool)\0"
    "animate(int)\0animFinished()\0"
};

void Task::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Task *_t = static_cast<Task *>(_o);
        switch (_id) {
        case 0: _t->opened(); break;
        case 1: _t->closed(); break;
        case 2: _t->setOpen((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->animate((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->animFinished(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Task::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Task::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Task,
      qt_meta_data_Task, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Task::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Task::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Task::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Task))
        return static_cast<void*>(const_cast< Task*>(this));
    return QWidget::qt_metacast(_clname);
}

int Task::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Task::opened()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Task::closed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
