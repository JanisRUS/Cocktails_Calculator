/****************************************************************************
** Meta object code from reading C++ file 'F_Ingredient.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Include/F_Ingredient.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'F_Ingredient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_F_Ingredient_t {
    const uint offsetsAndSize[18];
    char stringdata0[132];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_F_Ingredient_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_F_Ingredient_t qt_meta_stringdata_F_Ingredient = {
    {
QT_MOC_LITERAL(0, 12), // "F_Ingredient"
QT_MOC_LITERAL(13, 13), // "Edited_Signal"
QT_MOC_LITERAL(27, 0), // ""
QT_MOC_LITERAL(28, 13), // "Delete_Signal"
QT_MOC_LITERAL(42, 15), // "Ingredient_Name"
QT_MOC_LITERAL(58, 21), // "Delete_Button_Clicked"
QT_MOC_LITERAL(80, 12), // "TBox_Changed"
QT_MOC_LITERAL(93, 8), // "New_Text"
QT_MOC_LITERAL(102, 29) // "Ingredient_Data_Edit_Finished"

    },
    "F_Ingredient\0Edited_Signal\0\0Delete_Signal\0"
    "Ingredient_Name\0Delete_Button_Clicked\0"
    "TBox_Changed\0New_Text\0"
    "Ingredient_Data_Edit_Finished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_F_Ingredient[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x06,    1 /* Public */,
       3,    1,   45,    2, 0x06,    2 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    0,   48,    2, 0x08,    4 /* Private */,
       6,    1,   49,    2, 0x08,    5 /* Private */,
       8,    0,   52,    2, 0x08,    7 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,

       0        // eod
};

void F_Ingredient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<F_Ingredient *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->Edited_Signal(); break;
        case 1: _t->Delete_Signal((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->Delete_Button_Clicked(); break;
        case 3: _t->TBox_Changed((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->Ingredient_Data_Edit_Finished(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (F_Ingredient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&F_Ingredient::Edited_Signal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (F_Ingredient::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&F_Ingredient::Delete_Signal)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject F_Ingredient::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_F_Ingredient.offsetsAndSize,
    qt_meta_data_F_Ingredient,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_F_Ingredient_t
, QtPrivate::TypeAndForceComplete<F_Ingredient, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *F_Ingredient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *F_Ingredient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_F_Ingredient.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int F_Ingredient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void F_Ingredient::Edited_Signal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void F_Ingredient::Delete_Signal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
