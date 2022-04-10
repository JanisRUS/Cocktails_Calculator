/****************************************************************************
** Meta object code from reading C++ file 'F_Cocktail.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Include/F_Cocktail.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'F_Cocktail.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_F_Cocktail_t {
    const uint offsetsAndSize[24];
    char stringdata0[200];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_F_Cocktail_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_F_Cocktail_t qt_meta_stringdata_F_Cocktail = {
    {
QT_MOC_LITERAL(0, 10), // "F_Cocktail"
QT_MOC_LITERAL(11, 13), // "Edited_Signal"
QT_MOC_LITERAL(25, 0), // ""
QT_MOC_LITERAL(26, 13), // "Cocktail_Name"
QT_MOC_LITERAL(40, 13), // "Delete_Signal"
QT_MOC_LITERAL(54, 21), // "Accept_Button_Clicked"
QT_MOC_LITERAL(76, 21), // "Delete_Button_Clicked"
QT_MOC_LITERAL(98, 29), // "Add_Ingredient_Button_Clicked"
QT_MOC_LITERAL(128, 18), // "Name_Edit_Finished"
QT_MOC_LITERAL(147, 17), // "Ingredient_Edited"
QT_MOC_LITERAL(165, 18), // "Ingredient_Deteled"
QT_MOC_LITERAL(184, 15) // "Ingredient_Name"

    },
    "F_Cocktail\0Edited_Signal\0\0Cocktail_Name\0"
    "Delete_Signal\0Accept_Button_Clicked\0"
    "Delete_Button_Clicked\0"
    "Add_Ingredient_Button_Clicked\0"
    "Name_Edit_Finished\0Ingredient_Edited\0"
    "Ingredient_Deteled\0Ingredient_Name"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_F_Cocktail[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   62,    2, 0x06,    1 /* Public */,
       4,    1,   65,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    0,   68,    2, 0x08,    5 /* Private */,
       6,    0,   69,    2, 0x08,    6 /* Private */,
       7,    0,   70,    2, 0x08,    7 /* Private */,
       8,    0,   71,    2, 0x08,    8 /* Private */,
       9,    0,   72,    2, 0x08,    9 /* Private */,
      10,    1,   73,    2, 0x08,   10 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,

       0        // eod
};

void F_Cocktail::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<F_Cocktail *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->Edited_Signal((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->Delete_Signal((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->Accept_Button_Clicked(); break;
        case 3: _t->Delete_Button_Clicked(); break;
        case 4: _t->Add_Ingredient_Button_Clicked(); break;
        case 5: _t->Name_Edit_Finished(); break;
        case 6: _t->Ingredient_Edited(); break;
        case 7: _t->Ingredient_Deteled((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (F_Cocktail::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&F_Cocktail::Edited_Signal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (F_Cocktail::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&F_Cocktail::Delete_Signal)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject F_Cocktail::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_F_Cocktail.offsetsAndSize,
    qt_meta_data_F_Cocktail,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_F_Cocktail_t
, QtPrivate::TypeAndForceComplete<F_Cocktail, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>


>,
    nullptr
} };


const QMetaObject *F_Cocktail::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *F_Cocktail::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_F_Cocktail.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int F_Cocktail::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void F_Cocktail::Edited_Signal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void F_Cocktail::Delete_Signal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
