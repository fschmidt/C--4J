/****************************************************************************
** Meta object code from reading C++ file 'showinputdialog.h'
**
** Created: Tue Jul 10 12:42:56 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Haushaltsbuch/showinputdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'showinputdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ShowInputDialog[] = {

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
      17,   16,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ShowInputDialog[] = {
    "ShowInputDialog\0\0showInput()\0"
};

void ShowInputDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ShowInputDialog *_t = static_cast<ShowInputDialog *>(_o);
        switch (_id) {
        case 0: _t->showInput(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData ShowInputDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ShowInputDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ShowInputDialog,
      qt_meta_data_ShowInputDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ShowInputDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ShowInputDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ShowInputDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ShowInputDialog))
        return static_cast<void*>(const_cast< ShowInputDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int ShowInputDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
