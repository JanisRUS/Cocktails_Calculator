/****************************************************************************
** Meta object code from reading C++ file 'F_Main.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Include/F_Main.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'F_Main.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_F_Main_t {
    const uint offsetsAndSize[20];
    char stringdata0[166];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_F_Main_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_F_Main_t qt_meta_stringdata_F_Main = {
    {
QT_MOC_LITERAL(0, 6), // "F_Main"
QT_MOC_LITERAL(7, 27), // "Add_Cocktail_Button_Clicked"
QT_MOC_LITERAL(35, 0), // ""
QT_MOC_LITERAL(36, 29), // "Add_Ingredient_Button_Clicked"
QT_MOC_LITERAL(66, 15), // "Cocktail_Edited"
QT_MOC_LITERAL(82, 13), // "Cocktail_Name"
QT_MOC_LITERAL(96, 17), // "Ingredient_Edited"
QT_MOC_LITERAL(114, 15), // "Ingredient_Name"
QT_MOC_LITERAL(130, 16), // "Cocktail_Deteled"
QT_MOC_LITERAL(147, 18) // "Ingredient_Deteled"

    },
    "F_Main\0Add_Cocktail_Button_Clicked\0\0"
    "Add_Ingredient_Button_Clicked\0"
    "Cocktail_Edited\0Cocktail_Name\0"
    "Ingredient_Edited\0Ingredient_Name\0"
    "Cocktail_Deteled\0Ingredient_Deteled"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_F_Main[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x08,    1 /* Private */,
       3,    0,   51,    2, 0x08,    2 /* Private */,
       4,    1,   52,    2, 0x08,    3 /* Private */,
       6,    1,   55,    2, 0x08,    5 /* Private */,
       8,    1,   58,    2, 0x08,    7 /* Private */,
       9,    1,   61,    2, 0x08,    9 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    7,

       0        // eod
};

void F_Main::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<F_Main *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->Add_Cocktail_Button_Clicked(); break;
        case 1: _t->Add_Ingredient_Button_Clicked(); break;
        case 2: _t->Cocktail_Edited((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->Ingredient_Edited((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->Cocktail_Deteled((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->Ingredient_Deteled((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject F_Main::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_F_Main.offsetsAndSize,
    qt_meta_data_F_Main,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_F_Main_t
, QtPrivate::TypeAndForceComplete<F_Main, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>


>,
    nullptr
} };


const QMetaObject *F_Main::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *F_Main::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_F_Main.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int F_Main::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
